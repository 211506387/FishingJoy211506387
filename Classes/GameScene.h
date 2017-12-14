#pragma once
#include "cocos2d.h"
#include "BackgroundLayer.h"
//#include
//#include
//#include
//#include

using namespace cocos2d;

class GameScene:
	public CCScene{
public:
	GameScene();
	virtual ~GameScene();
	CREATE_FUNC(GameScene)
	virtual bool init();
protected:
	BackgroundLayer* _bgLayer;
};