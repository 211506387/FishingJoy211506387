#pragma once
#include "cocos2d.h"
#include "Fish.h"

#define FISH_MAX_COUNT 50

using namespace cocos2d;

class FishLayer:
	public CCLayer{
public:
	FishLayer();
	virtual ~FishLayer();
	virtual bool init();
	CREATE_FUNC(FishLayer)
	void addFish(float dt);
protected:
	CCArray* _fishes;
};