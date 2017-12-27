#pragma once
#include "cocos2d.h"
#include "Cannon.h"
#include "Bullet.h"
#include "FishNet.h"

using namespace cocos2d;

class Weapon:
	public CCNode{
public:
	virtual ~Weapon();
	static Weapon* create(CannonType type = k_Cannon_Type_1);
	bool init(CannonType type = k_Cannon_Type_1);
	void changeCannon(CannonOperate operate);
	CCSize getCannonSize();
protected:
	Cannon* _cannon;
	CCArray* _bullets;
	CCArray* _fishNets;
};