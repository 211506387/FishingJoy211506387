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
	void aimAt(CCPoint target);
	void shootTo (CCPoint target);
	Bullet* getBulletToShoot();
	CCRect getCollisionArea(Bullet* bullet);
protected:
	CC_SYNTHESIZE_READONLY(Cannon*, _cannon, Cannon);
	CC_SYNTHESIZE_READONLY(CCArray*, _bullets, Bullets);
	CC_SYNTHESIZE_READONLY(CCArray*, _fishNets, FishNets);
	CC_SYNTHESIZE_READONLY(CCArray*, _particles, CCParticleSystemQuad);
};