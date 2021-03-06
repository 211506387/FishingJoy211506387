#if !defined(_STATICDATA_H)
#define _STATICDATA_H

#include<string>
#include "cocos2d.h"
using namespace std;
USING_NS_CC;

#define STATIC_DATA_FILENAME "static_data.plist"
#define STATIC_DATA_STRING(key) StaticData::sharedStaticData()->stringValueFromKey(key)
#define STATIC_DATA_INT(key) StaticData::sharedStaticData()->intValueFromKey(key)
#define STATIC_DATA_FlOAT(key) StaticData::sharedStaticData()->floatValueFromKey(key)
#define STATIC_DATA_BOOL(key) StaticData::sharedStaticData()->booleanFromKey(key)
#define STATIC_DATA_POINT(key) StaticData::sharedStaticData()->pointFromKey(key)
#define STATIC_DATA_RECT(key) StaticData::sharedStaticData()->rectFromKey(key)
#define STATIC_DATA_SIZE(key) StaticData::sharedStaticData()->sizeFromKey(key)


class StaticData:
	public CCObject {
public:
	static StaticData* sharedStaticData();
	static void purge();
	int intValueFromKey(const string& key);
	const char* stringValueFromKey(const string& key);
	float floatValueFromKey(const string& key);
	bool booleanFromKey(const string& key);
	CCPoint pointFromKey(const string& key);
	CCRect rectFromKey(const string& key);
	CCSize sizeFromKey(const string& key);
protected:
	CCDictionary* _dictionary;
	string _staticFileName;
	bool init();
private:
	~StaticData();
	StaticData();
};

#endif  //_STATICDATA_H
