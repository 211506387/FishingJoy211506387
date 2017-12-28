#include "FishLayer.h"

FishLayer::FishLayer(){
}

FishLayer::~FishLayer(){
	CC_SAFE_RELEASE(_fishes);
}

bool FishLayer::init(){
	do{
		CC_BREAK_IF(!CCLayer::init());
		_fishes = CCArray::createWithCapacity(FISH_MAX_COUNT);
		CC_SAFE_RETAIN(_fishes);
		for(int i = 0;i < FISH_MAX_COUNT;i++){
			int type = CCRANDOM_0_1() * k_Fish_Type_Count - 1;
			Fish* fish = Fish::create((FishType)type);
			_fishes->addObject(fish);
		}
		this->schedule(schedule_selector(FishLayer::addFish),3.0f);
		return true;
	}while(0);
	return false;
}

void FishLayer::addFish(float dt){
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	int countToAdd = CCRANDOM_0_1()*10 + 1;
	int count = 0;
	CCObject* obj;

	CCARRAY_FOREACH(_fishes,obj){
		Fish* fish = (Fish*)obj;
		if(fish->isRunning()){
			continue;
		}
		this->addChild(fish);
		fish->setPosition(ccp(CCRANDOM_0_1() * winSize.width, CCRANDOM_0_1() * winSize.height));
		count++;
		if(count == countToAdd){
			break;
		}
	}
}

CCArray* FishLayer::getFishes(){
	return _fishes;
}