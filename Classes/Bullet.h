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
	void end();
	void flyTo(CCPoint targetInWordSpace, int type =0);
	CCPoint getCollisionPoint();
protected:
	CCSprite*  _bulletSprite;
};