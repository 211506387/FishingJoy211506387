#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class Counter:
	public CCNode{
public:
	Counter();
	static Counter* create(CCArray* presenters,int digit = 0);
	bool init(CCArray* presenters, int digit);
	CC_PROPERTY(int, _digit, Digit);
	void animation(int digit);
	
protected:
	CCNode* _presenters;
	virtual void visit();
};