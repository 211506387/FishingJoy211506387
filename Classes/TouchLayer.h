#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class GameScene;
class TouchLayer:
	public CCLayer{
public:
	TouchLayer();
	virtual ~TouchLayer();
	bool init();
	void registerWithTouchDispatcher();
	CREATE_FUNC(TouchLayer);
protected:
	GameScene *getGameScene();
	virtual bool TouchLayer::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
	virtual void TouchLayer::ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent);
	virtual void TouchLayer::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent);
};