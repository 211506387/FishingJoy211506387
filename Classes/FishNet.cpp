#include "FishNet.h"

FishNet::FishNet(){
}

FishNet::~FishNet(){
}

bool FishNet::init(){
	do{
		CC_BREAK_IF(!CCNode::init());
		CCString *fileName = CCString::createWithFormat("weapon_net_%03d.png",1);
		_fishNetSprite = CCSprite::createWithSpriteFrameName(fileName->getCString());
		_fishNetSprite->setAnchorPoint(ccp(0.5, 0.5));
		return true;
	}while(0);
	return false;
}