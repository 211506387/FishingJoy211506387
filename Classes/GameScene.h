#pragma once
#include "cocos2d.h"
#include "BackgroundLayer.h"
#include "FishLayer.h"
#include "CannonLayer.h"
#include "TouchLayer.h"
//#include

using namespace cocos2d;

class GameScene:
	public CCScene{
public:
	GameScene();
	virtual ~GameScene();
	CREATE_FUNC(GameScene)
	virtual bool init();
	void preloadResources();
	void cannonAimAt(CCPoint target);
	void cannonShootTo(CCPoint target);
protected:
	BackgroundLayer* _bgLayer;
	FishLayer* _fishLayer;
	CannonLayer* _cannonLayer;
	TouchLayer* _touchLayer;
};