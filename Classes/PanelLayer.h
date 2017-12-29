#pragma once
#include "cocos2d.h"
#include "GoldCounterLayer.h"
#include "ScheduleCounterDelegate.h"
#include "ScheduleCountDown.h"

using namespace cocos2d;

class PanelLayer:
	public CCLayer,public ScheduleCounterDelegate{
public:
	CREATE_FUNC(PanelLayer);
	CC_SYNTHESIZE_READONLY(GoldCounterLayer*, _goldCounterLayer, GoldCounterLayer);
	virtual bool init();
	void setScheduleNumber(int number);
	void scheduleTimeUp();
protected:
	CCLabelAtlas* _scheduleLabel;
};