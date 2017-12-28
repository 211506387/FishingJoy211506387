#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class FishNet:
	public CCNode{
public:
	FishNet();
	virtual ~FishNet();
	bool init();
	CREATE_FUNC(FishNet);
	void showAt(CCPoint pos,int type = 0);
	CCRect getCollisionArea();
protected:
	CCSprite*  _fishNetSprite;
};