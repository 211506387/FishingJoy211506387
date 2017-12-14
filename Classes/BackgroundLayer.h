#pragma once
#include "cocos2d.h"

using namespace cocos2d;

 class BackgroundLayer:
	 public CCLayer{
 public:
	 BackgroundLayer();
	 virtual ~BackgroundLayer();
	 virtual bool init();
	 CREATE_FUNC(BackgroundLayer)
 };