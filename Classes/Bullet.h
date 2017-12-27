#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class Bullet:
	public CCNode{
public:
	Bullet();
	virtual ~Bullet();
	bool init();
	float getSpeed(int type);
	CREATE_FUNC(Bullet);
protected:
	CCSprite*  _bulletSprite;
};