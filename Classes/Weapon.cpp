#include "Weapon.h"
#include "PersonalAudioEngine.h"

#define BULLET_COUNTS 10

Weapon::~Weapon(void)
{
	CC_SAFE_RELEASE(_bullets);
	CC_SAFE_RELEASE(_fishNets);
	CC_SAFE_RELEASE(_particles);
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

		_particles = CCArray::createWithCapacity(BULLET_COUNTS);
		CC_BREAK_IF(!_particles);
		CC_SAFE_RETAIN(_particles);

		for(int i = 0; i < BULLET_COUNTS; i++){
			Bullet* bullet = Bullet::create();
			_bullets->addObject(bullet);
			addChild(bullet);
			bullet->setVisible(false);
			
			FishNet* fishNet = FishNet::create();
			_fishNets->addObject(fishNet);
			addChild(fishNet);
			fishNet->setVisible(false);
			bullet->setUserObject(fishNet);

			CCParticleSystemQuad* particle = CCParticleSystemQuad::create("yuwanglizi.plist");
			particle->stopSystem();
			addChild(particle);
			_particles->addObject(particle);
			fishNet->setUserObject(particle);
		}
		return true;
	}while(0);
	return false;
}

void Weapon::changeCannon(CannonOperate operate){
	PersonalAudioEngine::getInstance()->playEffect(kEffectSwichCannon);
	int type = (int) _cannon->getType();
	type += operate;
	_cannon->setType((CannonType)type);
}

CCSize Weapon::getCannonSize(){
	return _cannon->getSize();
}

void Weapon::aimAt(CCPoint target){
	_cannon->aimAt(target);
}

void Weapon:: shootTo (CCPoint target){
	Bullet* bullet= getBulletToShoot();
	if(!bullet) return;
	CCPoint pointWorldSpace = getParent()->convertToWorldSpace(getPosition());
	float distance = ccpDistance(target, pointWorldSpace);
	if(distance > _cannon->getFireRange()){
		CCPoint normal = ccpNormalize(ccpSub(target, pointWorldSpace));
		CCPoint mult = ccpMult(normal, _cannon->getFireRange());
		target = ccpAdd(pointWorldSpace, mult);
	}
	bullet->flyTo(target, _cannon->getType());
}

Bullet* Weapon::getBulletToShoot(){
	CCObject* obj;
	CCARRAY_FOREACH(_bullets, obj){
		Bullet* bullet = (Bullet*)obj;
		if(!bullet->isVisible()){
			return bullet;
		}
	}
	return NULL;
}

CCRect Weapon::getCollisionArea(Bullet* bullet){
	FishNet* _fishNets = (FishNet*)bullet->getUserObject();
	if(_fishNets->isVisible()){
		return _fishNets->getCollisionArea();
	}
	return CCRectZero;
}

CannonType Weapon::getCannonType()
{
	return _cannon->getType();
}