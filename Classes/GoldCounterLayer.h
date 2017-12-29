#pragma once
#include "cocos2d.h"


using namespace cocos2d;

class GoldCounterLayer:
	public CCNode{
public:
	static GoldCounterLayer* create(int number);
	bool init(int number);
	void setNumber(int number, int ceiling =999999);
protected:
	int _number;
};