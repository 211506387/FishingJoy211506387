#pragma once

using namespace cocos2d;

class ScheduleCounterDelegate{
public:
	virtual void scheduleTimeUp() = 0;
	virtual void setScheduleNumber(int number){	return;	}
};