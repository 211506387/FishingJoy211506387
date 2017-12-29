#include "GameScene.h"

GameScene::GameScene(){
}

GameScene::~GameScene(){
}

bool GameScene::init(){
	do{
		CC_BREAK_IF(!CCScene::init());
		this->preloadResources();
		_bgLayer = BackgroundLayer::create();
		CC_BREAK_IF(!_bgLayer);
		this->addChild(_bgLayer);

		_fishLayer = FishLayer::create();
		CC_BREAK_IF(!_fishLayer);
		this->addChild(_fishLayer);

		_cannonLayer = CannonLayer::create();
		CC_BREAK_IF(!_cannonLayer);
		this->addChild(_cannonLayer);

		_touchLayer = TouchLayer::create();
		CC_BREAK_IF(!_touchLayer);
		this->addChild(_touchLayer);

		_paneLayer = PanelLayer::create();
		CC_BREAK_IF(!_paneLayer);
		this->addChild(_paneLayer);
		_paneLayer->getGoldCounterLayer()->setNumber(FishingJoyData::getInstance()->getGold());
		
		scheduleUpdate();
		return true;
	}while(0);
	return false;
}

void GameScene::preloadResources(){
	CCSpriteFrameCache* spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Large-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Marlin-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Shark-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Small-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("FishActor-Mid-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("cannon-ipadhd.plist");
	spriteFrameCache->addSpriteFramesWithFile("Item-chaojiwuqi-ipadhd.plist");

	char str[][50] = {"SmallFish","Croaker","AngelFish","Amphiprion","PufferS",	
		"Bream","Porgy","Chelonian","Lantern","Ray","Shark","GoldenTrout",	
		"GShark","GMarlinsFish","GrouperFish","JadePerch","MarlinsFish","PufferB"};

	for(int i = 0;i < 18;i++){
		CCArray* array = CCArray::createWithCapacity(10);
		for(int j = 0;j < 10;j++){
			CCString* string = CCString::createWithFormat("%s_actor_%03d.png",str[i],j+1);
			CCSpriteFrame* spriteFrame = spriteFrameCache->spriteFrameByName(string->getCString());
			CC_BREAK_IF(!spriteFrame);
			array->addObject(spriteFrame);
		}
		if (array->count() == 0)
		{
			continue;
		}
		CCAnimation* animation = CCAnimation::createWithSpriteFrames(array,0.15f);
		CCString* animationName = CCString::createWithFormat("fish_animation_%02d", i + 1);
		CCAnimationCache::sharedAnimationCache()->addAnimation(animation,animationName->getCString());
	}
}

void GameScene::cannonAimAt(CCPoint target){
	_cannonLayer->aimAt(target);
}

void GameScene::cannonShootTo(CCPoint target){
	int cost = (_cannonLayer->getWeapon()->getCannonType() + 1) * 1;
	int currentGold = FishingJoyData::getInstance()->getGold();
	if(currentGold >= cost){
		_cannonLayer->shootTo(target);
		this->alterGold(-cost);
	}
}

bool GameScene::checkOutCollisionBetweenFishesAndBullet(Bullet* bullet){
	Weapon* weapon = _cannonLayer->getWeapon();
	CCPoint bulletPosition = bullet->getCollisionPoint();
	CCArray* fishArray = _fishLayer->getFishes();
	CCObject* object = NULL;
	CCARRAY_FOREACH(fishArray,object){
		Fish* fish =(Fish*)object;
		if(fish->isRunning() && fish->getCollisionArea().containsPoint(bulletPosition)){
			bullet->end();
			return true;
		}
	}
	return false;
}

void GameScene::checkOutCollision(){
	CCArray* bullets = _cannonLayer->getWeapon()->getBullets();
	CCObject* object = NULL;
	CCARRAY_FOREACH(bullets, object){
		Bullet* bullet = (Bullet*)object;
		if(bullet->isVisible()){
			if(checkOutCollisionBetweenFishesAndBullet(bullet)){
				checkOutCollisionBetweenFishesAndFishingNet(bullet);
			}
		}
	}
}

void GameScene::update(float delta){
	this->checkOutCollision();
}

void GameScene::fishWillBeCaught(Fish* fish){
	int weaponType = _cannonLayer->getWeapon()->getCannonType();
	int fishType = fish->getType();
	float fishPer[k_Fish_Type_Count] = { 1, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4 };
	float weaponPer[k_Cannon_Count] = { 0.3, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1 };
	if(CCRANDOM_0_1() < 1.1 /*Óã±»×½¸ÅÂÊ*/){
		fish->beCaught();
		int reward = STATIC_DATA_INT(CCString::createWithFormat(STATIC_DATA_STRING("reward_format"),fishType)->getCString());
		alterGold(reward);
	}
}

void GameScene::checkOutCollisionBetweenFishesAndFishingNet(Bullet *bullet){
	Weapon* weapon = _cannonLayer->getWeapon();
	CCRect rect = weapon->getCollisionArea(bullet);
	CCArray* fishesArray = _fishLayer->getFishes();
	CCObject* object = NULL;
	CCARRAY_FOREACH(fishesArray,object){
		Fish* fish = (Fish*)object;
		if(fish->isRunning() && rect.intersectsRect(fish->getCollisionArea())){
			this->fishWillBeCaught(fish);
		}
	}
}

void GameScene::alterGold(int delta){
	FishingJoyData::getInstance()->alterGold(delta);
	_paneLayer->getGoldCounterLayer()->setNumber(FishingJoyData::getInstance()->getGold());
}

void GameScene::scheduleTimeUp(){
	this->alterGold(STATIC_DATA_INT("recovery_gold"));
}

void GameScene::onEnter()
{
	CCScene::onEnter();
	PersonalAudioEngine::getInstance()->playBackgroundMusic(3);
}