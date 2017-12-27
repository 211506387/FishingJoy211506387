#pragma once
#include "cocos2d.h"

using namespace cocos2d;

typedef enum{
	k_Cannon_Type_1 = 0,
	k_Cannon_Type_2,
	k_Cannon_Type_3,
	k_Cannon_Type_4,
	k_Cannon_Type_5,
	k_Cannon_Type_6,
	k_Cannon_Type_7,
	k_Cannon_Count,
	k_Cannon_Invalid
}CannonType;

typedef enum{
	    k_Cannon_Operate_Up = 1,
	    k_Cannon_Operate_Down = -1
}CannonOperate;

class Cannon:
	public CCNode{
public:
	Cannon();
	virtual ~Cannon();
	bool init(CannonType type = k_Cannon_Type_1);
	void setType(CannonType);
	CannonType getType(void);
	float getFireRange();
	static Cannon* create(CannonType type = k_Cannon_Type_1);
	CCSize getSize();
protected:
	CCArray* _cannonSprite;
	CannonType _type;
};