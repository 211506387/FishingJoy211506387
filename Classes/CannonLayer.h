#pragma once
#include "cocos2d.h"
#include "Weapon.h"

class CannonLayer:
	public CCLayer{
public:
	CannonLayer();
	virtual ~CannonLayer();
	virtual bool init();
	void switchCannon(cocos2d::CCObject *sender);
	CREATE_FUNC(CannonLayer);
protected:
	Weapon* _weapon;
	CCMenuItemImage *_addItem,*_subItem;
};