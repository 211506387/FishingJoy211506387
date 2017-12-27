#include "Cannon.h"
#include <cmath>

using namespace std;

Cannon::Cannon(){
}

Cannon::~Cannon(){
}

bool Cannon::init(CannonType type/* = k_Cannon_Type_1*/){
	do{
		CC_BREAK_IF(!CCNode::init());
		_cannonSprite = CCArray::createWithCapacity(k_Cannon_Count);
		CC_SAFE_RETAIN(_cannonSprite);
		for(int i = k_Cannon_Type_1;i < k_Cannon_Count;i++){
			CCString* fileName = CCString::createWithFormat("actor_cannon1_%d1.png",i+1);
			CCSprite* cannonSprite = CCSprite::createWithSpriteFrameName(fileName->getCString());
			_cannonSprite->addObject(cannonSprite);
			cannonSprite->setAnchorPoint(ccp(0.5,0.26));
		}
		this->setType(type);
		return true;
	}while(0);
	return false;
}

void Cannon::setType(CannonType type){
	if(_type == type){
		return;
	}
	if(type < k_Cannon_Type_1){
		type = (CannonType)(k_Cannon_Count - 1);
	}else if(type > k_Cannon_Count - 1){
		type = k_Cannon_Type_1;
	}
	this->removeChildByTag(_type);
	CCSprite* sprite = (CCSprite*) _cannonSprite->objectAtIndex(type);
	this->addChild(sprite,0,type);
	_type = type;
}

Cannon* Cannon::create(CannonType type/* = k_Cannon_Type_1*/){
	Cannon* cannon = new Cannon();
	if(cannon && cannon->init(type)){
		cannon->autorelease();
		return cannon;
	}else{
		CC_SAFE_DELETE(cannon);
		return NULL;
	}
}

float Cannon::getFireRange(){
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	double temp = pow(winSize.width * 0.5,2) + pow(winSize.height * 0.5,2);
	double result = sqrt(temp);
	return result/7 * (_type + 1) + 500;
}

CannonType Cannon::getType()
{
	return _type;
}

CCSize Cannon::getSize()
{
	CCSprite* cannonSprite = (CCSprite*) _cannonSprite->objectAtIndex(_type);
	return cannonSprite->getContentSize();
}