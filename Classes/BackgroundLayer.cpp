#include "BackgroundLayer.h"

BackgroundLayer::BackgroundLayer(){
}

BackgroundLayer::~BackgroundLayer(){
}

bool BackgroundLayer::init(){
	do{
		CC_BREAK_IF(!CCLayer::init());
		CCSprite* bgSprite = CCSprite::create("bj01_01-ipadhd.png");
		CC_BREAK_IF(!bgSprite);
		this->addChild(bgSprite);
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		bgSprite->setPosition(CCPointMake(winSize.width * 0.5,winSize.height * 0.5));
		return true;
	}while(0);
}