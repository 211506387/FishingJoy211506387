#pragma once
#include "cocos2d.h"
#include "StaticData.h"

using namespace cocos2d;

class FishingJoyData:
	public CCObject{
public:
	FishingJoyData();
	~FishingJoyData();
	CC_SYNTHESIZE(bool, _isBeginer, IsBeginer);
	CC_SYNTHESIZE(int, _gold, Gold);
	CC_SYNTHESIZE(bool, _isMusic, IsMusic)
	CC_SYNTHESIZE(bool, _isSound, IsSound)
	void purge();
	void flush();
	bool init();
	void reset();
	static FishingJoyData* getInstance();
	static void destoryInstance();
	void alterGold(int delta);
protected:

};