#include "SimpleAudioEngine.h"

typedef enum{
	kEffectSwichCannon = 0,
	kEffectShoot,
	kEffectFishNet,
	kEffectCoins
}EffectType;

class PersonalAudioEngine:
	public CocosDenshion::SimpleAudioEngine{
public:
	static PersonalAudioEngine *getInstance();
	static void destoryIntance();
	void playBackgroundMusic(int type);
	void playEffect(EffectType type);
protected:
	bool init();
private:
	PersonalAudioEngine();
	~PersonalAudioEngine();
	PersonalAudioEngine(const PersonalAudioEngine& engine);
};