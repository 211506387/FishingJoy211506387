#include "PanelLayer.h"
#include "GameScene.h"

bool PanelLayer::init(){
	do{
		CC_BREAK_IF(!CCLayer::init());
		_goldCounterLayer = GoldCounterLayer::create(0);
		this->addChild(_goldCounterLayer);
		_goldCounterLayer->setPosition(ccp(600, 17));

		ScheduleCountDown* countDown = ScheduleCountDown::create(this,10,true);
		this->addChild(countDown,0, 99);
		_scheduleLabel=CCLabelAtlas::create(CCString::createWithFormat("%d",10)->getCString(),"baoshiyu_shuzi_02-ipadhd.png",50,54,'0');
		addChild(_scheduleLabel);
		_scheduleLabel->setPosition(ccp(100,1200));
		return true;
	}while(0);
	return false;
}

void PanelLayer::setScheduleNumber(int number){
	_scheduleLabel->setString(CCString::createWithFormat("%d",number)->getCString());
}

void PanelLayer::scheduleTimeUp(){
	((GameScene *)getParent())->alterGold(200);
	ScheduleCountDown *countDown =(ScheduleCountDown *)getChildByTag(99);
	if(countDown->getLoop()==false){
		_scheduleLabel->setVisible(false);
	}
}