#include "FishingJoyData.h"

static FishingJoyData* _sharedFishingJoyData = NULL;

FishingJoyData::FishingJoyData(){
}

FishingJoyData::~FishingJoyData(){
}

void FishingJoyData::purge(){
	CC_SAFE_RELEASE_NULL(_sharedFishingJoyData);
}

void FishingJoyData::flush(){
	CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
	userDefault->setBoolForKey("isBeginer",_isBeginer);
	userDefault->setBoolForKey("music",_isMusic);
	userDefault->setBoolForKey("sound",_isSound);
	userDefault -> setIntegerForKey("gold", _gold);
	userDefault -> flush();
}

void FishingJoyData::reset(){
	this->setGold(100);
	this->setIsBeginer(false);
	this->setIsMusic(true);
	this->setIsSound(true);
}

bool FishingJoyData::init(){
	_isBeginer = CCUserDefault::sharedUserDefault()->getBoolForKey("isBeginer",true);
	if(_isBeginer){
		this->reset();
		this->flush();
	}else{
		CCUserDefault* userDefault = CCUserDefault::sharedUserDefault();
		this -> setGold(userDefault -> getDoubleForKey("gold"));
		this -> setIsMusic(userDefault -> getBoolForKey("music"));
		this -> setIsSound(userDefault -> getBoolForKey("sound"));
	}
	return true;
}

FishingJoyData* FishingJoyData::getInstance()
{
	if(NULL == _sharedFishingJoyData )
	{
		_sharedFishingJoyData  = new FishingJoyData();
		_sharedFishingJoyData  -> init();
	}
	return _sharedFishingJoyData ;
}

void FishingJoyData::destoryInstance()
{
	CC_SAFE_DELETE(_sharedFishingJoyData );
}

void FishingJoyData::alterGold(int delta){
	int gold = this->getGold();
	gold += delta;
	this->setGold(gold);
	this->flush();
}