#include "CannonLayer.h"

CannonLayer::CannonLayer(){
}

CannonLayer::~CannonLayer(){
}

bool CannonLayer::init(){
	do{
		CC_BREAK_IF(!CCLayer::init());
		_weapon = Weapon::create((CannonType)0);
		this->addChild(_weapon,1);
		CCSize winSize=CCDirector::sharedDirector()->getWinSize();
		_weapon->setPosition(ccp(winSize.width/2 - 18, 0));

		_addItem = CCMenuItemImage::create(
		"ui_button_65-ipadhd.png",
		"ui_button_65-ipadhd.png",
		this,menu_selector(CannonLayer::switchCannon));

		_subItem = CCMenuItemImage::create(
		"ui_button_63-ipadhd.png",
		"ui_button_63-ipadhd.png",
		this,menu_selector(CannonLayer::switchCannon));

		CCMenu* menu = CCMenu::create(_subItem, _addItem, NULL);
		menu->alignItemsHorizontallyWithPadding(120);
		this->addChild(menu);
		menu->setPosition(ccp(winSize.width/2-20, _addItem->getContentSize().height/2));
		return true;
	}while(0);
	return false;
}

void CannonLayer::switchCannon(cocos2d::CCObject *sender){
	CannonOperate operate = k_Cannon_Operate_Down;
	if((CCMenuItemImage*)sender == _addItem)
	{
		operate = k_Cannon_Operate_Up;
	}
	_weapon->changeCannon(operate);
}