#include "GameScene.h"

GameScene::GameScene(){
}

GameScene::~GameScene(){
}

bool GameScene::init(){
	do{
		CC_BREAK_IF(!CCScene::init());
		_bgLayer = BackgroundLayer::create();
		CC_BREAK_IF(!_bgLayer);
		this->addChild(_bgLayer);
		return true;
	}while(0);
	return false;
}