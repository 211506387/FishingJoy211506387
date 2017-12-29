#pragma once
#include "cocos2d.h"
#include "ScheduleCounterDelegate.h"

using namespace cocos2d;

class ScheduleCountDown:
	public CCNode{
public:
	CC_SYNTHESIZE(ScheduleCounterDelegate *,_target,Target);
	CC_SYNTHESIZE(int,_curTime,CurTime);
	CC_SYNTHESIZE(int,_maxTime,MaxTime);
	CC_SYNTHESIZE(bool,_loop,Loop);
	static ScheduleCountDown* create(ScheduleCounterDelegate* target,int perimeter,bool loop);
	bool init(ScheduleCounterDelegate* target,int perimeter,bool loop);
	void schedulePerSecond(float delta);
};