#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class GameMenuLayer:
	public CCLayer{
public:
	CREATE_FUNC(GameMenuLayer)
	GameMenuLayer();
	virtual ~GameMenuLayer();
	virtual bool init();
	void onStartGame(CCObject *sender);
	void onSelectScene(CCObject *sender);
	static CCScene* scene();
protected:
	void createMenu();
};