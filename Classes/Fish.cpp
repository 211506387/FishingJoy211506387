#include "Fish.h"

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