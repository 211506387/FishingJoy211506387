#include "ScheduleCountDown.h"

ScheduleCountDown* ScheduleCountDown::create(ScheduleCounterDelegate* target,int perimeter,bool loop){
	ScheduleCountDown* counter = new ScheduleCountDown();
	if(counter && counter->init(target,perimeter,loop)){
		counter->autorelease();
		return counter;
	}else{
		CC_SAFE_DELETE(counter);
		return NULL;
	}
}

bool ScheduleCountDown::init(ScheduleCounterDelegate* target,int perimeter,bool loop){
	do{
		CC_BREAK_IF(!CCNode::init());
		_target = target;
		_maxTime = perimeter;
		_curTime = perimeter;
		_loop = loop;
		schedule(schedule_selector(ScheduleCountDown::schedulePerSecond),1.0f);
		return true;
	}while(0);
	return false;
}

void ScheduleCountDown::schedulePerSecond(float delta){
	_curTime--;
	if(_curTime <0){
		if(_loop==true){
			_curTime =_maxTime;
		}else{
			this->unschedule(schedule_selector(ScheduleCountDown::schedulePerSecond));
		}
		_target->scheduleTimeUp();
	}else{
		_target->setScheduleNumber(_curTime);
	}
}