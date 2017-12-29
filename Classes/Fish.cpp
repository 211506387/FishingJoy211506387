#include "Fish.h"

enum{
	k_Action_Animate =0,
	k_Action_MoveTo
};

Fish::Fish(){
}

Fish::~Fish(){
}

bool Fish::init(FishType type/* = k_Fish_Type_SmallFish*/){
	do{
		CC_BREAK_IF(!CCNode::init());
		if (type < k_Fish_Type_SmallFish || type >= k_Fish_Type_Count){
			type = k_Fish_Type_SmallFish;
		}
		_type = type;
		CCString* animationName = CCString::createWithFormat("fish_animation_%02d", _type + 1);
		CCAnimation* animation = CCAnimationCache::sharedAnimationCache()->animationByName(animationName->getCString());
		CC_BREAK_IF(!animation);
		CCAnimate* animate = CCAnimate::create(animation);
		_fishSprite = CCSprite::create();
		this->addChild(_fishSprite);
		_fishSprite->runAction(CCRepeatForever::create(animate));
		return true;
	}while(0);
	return false;
}

Fish* Fish::create(FishType type/* = k_Fish_Type_SmallFish*/){
	Fish* fish = new Fish;
	if(fish && fish->init(type)){
		fish->autorelease();
		return fish;
	}else{
		CC_SAFE_DELETE(fish);
		return NULL;
	}
}

int Fish::getScore(){
	return 100;
}

int Fish::getSpeed(){
	return 200;
}

CCRect Fish::getCollisionArea(){
	CCPoint position = getParent()->convertToWorldSpace(this->getPosition());
	CCSize size = _fishSprite->getContentSize();
	return CCRect(position.x - size.width / 2, position.y - size.height/2, size.width, size.height);
}

void Fish::beCaught(){
	stopActionByTag(k_Action_MoveTo);
	CCDelayTime* delayTime = CCDelayTime::create(1.0f);
	CCCallFunc* callFunc = CCCallFunc::create(this,callfunc_selector(Fish::beCaught_CallFunc));
	CCSequence* sequence = CCSequence::create(delayTime,callFunc,NULL);
	CCBlink* blink = CCBlink::create(1.0f,8);
	CCSpawn* spawn = CCSpawn::create(sequence, blink, NULL);
	_fishSprite->runAction(spawn);
}

void Fish::beCaught_CallFunc(){
	if(this->isRunning()){
		this->getParent()->removeChild(this,false);
	}
}

void Fish::moveTo(CCPoint targetPoint){
	CCPoint point =getParent()->convertToWorldSpace(this->getPosition());
	float swimmingTime = ccpDistance(targetPoint,point)/getSpeed();
	CCMoveTo* moveTo = CCMoveTo::create(swimmingTime,targetPoint);
	CCCallFunc* callFunc =CCCallFunc::create(this,callfunc_selector(Fish::moveEnd));
	CCSequence* sequence =CCSequence::create(moveTo,callFunc,NULL);
	sequence->setTag(k_Action_MoveTo);
	this->runAction(sequence);
}

void Fish::moveEnd(){
	if(isRunning()){
		getParent()->removeChild(this,false);
	}
}

void Fish::reset(){
	this->setRotation(0);
	this->setVisible(true);
}

CCSize Fish::getSize()
{
	return _fishSprite->displayFrame()->getRect().size;

}