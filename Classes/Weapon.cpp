#include "Weapon.h"

#define BULLET_COUNTS 10

Weapon::~Weapon(void)
{
	CC_SAFE_RELEASE(_bullets);
	CC_SAFE_RELEASE(_fishNets);
}

Weapon* Weapon::create(CannonType type/* = k_Cannon_Type_1*/){
	Weapon* weapon = new Weapon();
	if(weapon && weapon->init(type)){
		weapon->autorelease();
		return weapon;
	}else{
		CC_SAFE_DELETE(weapon);
		return NULL;
	}
}

bool Weapon::init(CannonType type/* = k_Cannon_Type_1*/){
	do{
		CC_BREAK_IF(!CCNode::init());
		_cannon = Cannon::create(type);
		CC_BREAK_IF(!_cannon);
		addChild(_cannon, 1);

		_bullets = CCArray::createWithCapacity(BULLET_COUNTS);
		CC_BREAK_IF(!_bullets);
		CC_SAFE_RETAIN(_bullets);

		_fishNets=CCArray::createWithCapacity(BULLET_COUNTS);
		CC_BREAK_IF(!_fishNets);
		CC_SAFE_RETAIN(_fishNets);

		for(int i = 0; i < BULLET_COUNTS; i++)
		{
			Bullet* bullet = Bullet::create();
			_bullets->addObject(bullet);
			addChild(bullet);
			bullet->setVisible(false);
			
			FishNet* fishNet = FishNet::create();
			_fishNets->addObject(fishNet);
			addChild(fishNet);
			fishNet->setVisible(false);
			bullet->setUserObject(fishNet);
		}
		return true;
	}while(0);
	return false;
}

void Weapon::changeCannon(CannonOperate operate)
{
	int type = (int) _cannon->getType();
	type += operate;
	_cannon->setType((CannonType)type);
}

CCSize Weapon::getCannonSize(){
	return _cannon->getSize();
}