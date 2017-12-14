#include "GameMenuLayer.h"

GameMenuLayer::GameMenuLayer(){
}

GameMenuLayer::~GameMenuLayer(){
}

bool GameMenuLayer::init(){
	do{
		CC_BREAK_IF(!CCLayer::init());
		CCSprite* bgSprite = CCSprite::create("ui_background_normal-ipadhd.png");
		CC_BREAK_IF(!bgSprite);
		this->addChild(bgSprite);
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		bgSprite->setPosition(CCPointMake(winSize.width * 0.5,winSize.height * 0.5));

		CCSprite* titleSprite = CCSprite::create("main_ui_title_cn-ipadhd.png");
		CC_BREAK_IF(!titleSprite);
		this->addChild(titleSprite);
		titleSprite->setPosition(CCPointMake(winSize.width * 0.5,winSize.height * 0.75));
		this->createMenu();
		return true;
	}while(0);
	return false;
}

void GameMenuLayer::createMenu(){
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI_GameStartMenuLayer-ipadhd.plist");
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI_GameMenuText_cn-ipadhd.plist");

	//开始按钮默认
	CCSprite *startNormalBgSprite = CCSprite::createWithSpriteFrameName("ui_button_box02_02.png");
	CCSprite *startNormalTextSprite = CCSprite::createWithSpriteFrameName("ui_2p_010.png");
	CCSize startButtonSize = startNormalBgSprite->getContentSize();
	startNormalBgSprite->addChild(startNormalTextSprite);
	startNormalTextSprite->setPosition(CCPointMake(startButtonSize.width / 2,startButtonSize.height / 2 + 20));

	//开始按钮选中
	CCSprite *startSelectedBgSprite = CCSprite::createWithSpriteFrameName("ui_button_box02_01.png");
	CCSprite *startSelectedTextSprite = CCSprite::createWithSpriteFrameName("ui_2p_010.png");
	startSelectedBgSprite->addChild(startSelectedTextSprite);
	startSelectedTextSprite->setPosition(CCPointMake(startButtonSize.width / 2,startButtonSize.height / 2 + 20));

	CCMenuItemSprite* startMenuItem = CCMenuItemSprite::create(startNormalBgSprite,
		startSelectedBgSprite,this,menu_selector(GameMenuLayer::onStartGame));

	//选择按钮默认
	CCSprite *sceneNormalBgSprite = CCSprite::createWithSpriteFrameName("ui_button_box01_02.png");
	CCSprite *sceneNormalTextSprite = CCSprite::createWithSpriteFrameName("button_other_014.png");
	CCSize sceneButtonSize = sceneNormalBgSprite->getContentSize();
	sceneNormalBgSprite->addChild(sceneNormalTextSprite);
	sceneNormalTextSprite->setPosition(CCPointMake(sceneButtonSize.width / 2,sceneButtonSize.height / 2 + 3));

	//选择按钮选中
	CCSprite *sceneSelectedBgSprite = CCSprite::createWithSpriteFrameName("ui_button_box01_01.png");
	CCSprite *sceneSelectedTextSprite = CCSprite::createWithSpriteFrameName("button_other_014.png");
	sceneSelectedBgSprite->addChild(sceneSelectedTextSprite);
	sceneSelectedTextSprite->setPosition(CCPointMake(sceneButtonSize.width / 2,sceneButtonSize.height / 2 + 3));

	CCMenuItemSprite* sceneMenuItem = CCMenuItemSprite::create(sceneNormalBgSprite,
		sceneSelectedBgSprite,this,menu_selector(GameMenuLayer::onSelectScene));

	CCMenu* menu = CCMenu::create(startMenuItem,sceneMenuItem,NULL);
	this->addChild(menu);
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	menu->setPosition(CCPointMake(winSize.width * 0.5,winSize.height * 0.4));
	menu->alignItemsVerticallyWithPadding(50);
}

void GameMenuLayer::onSelectScene(CCObject *sender){
}

void GameMenuLayer::onStartGame(CCObject *sender){
}

CCScene* GameMenuLayer::scene(){
	CCScene* scene = CCScene::create();
	GameMenuLayer* gameMenuLayer = GameMenuLayer::create();
	scene->addChild(gameMenuLayer);
	return scene;
}