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
	_cannonLayer->shootTo(target);
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
				
			}
		}
	}
}

void GameScene::update(float delta){
	this->checkOutCollision();
}