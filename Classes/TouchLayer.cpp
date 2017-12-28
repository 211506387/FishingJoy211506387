#include "TouchLayer.h"
#include "GameScene.h"

TouchLayer::TouchLayer(){
}

TouchLayer::~TouchLayer(){
}

void TouchLayer::registerWithTouchDispatcher(){
	CCDirector::sharedDirector() -> getTouchDispatcher() -> addTargetedDelegate(this, 0, true);
}

bool TouchLayer::init(){
	do{
		CC_BREAK_IF(!CCLayer::init());
		setTouchEnabled(true);
		return true;
	}while(0);
	return false;
}

bool TouchLayer::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent){
	GameScene* gameScene = getGameScene();
	CCPoint target = pTouch->getLocation();
	gameScene->cannonAimAt(target);
	return true;
}

void TouchLayer::ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent){
	GameScene* gameScene = getGameScene();
	CCPoint target = pTouch->getLocation();
	gameScene->cannonAimAt(target);
}

void TouchLayer::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent){
	GameScene* gameScene = getGameScene();
	CCPoint target = pTouch->getLocation();
	gameScene->cannonShootTo(target);
}

GameScene * TouchLayer::getGameScene(){
	return (GameScene *)getParent();
}