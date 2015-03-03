#ifndef __Bullet_H__
#define __Bullet_H__
#include "Box2D/Box2D.h"
#include "cocos2d.h"

using namespace cocos2d;
class Bullet: public cocos2d::CCSprite
{
public:
	Bullet(void);
	~Bullet(void);
    
    void Init(cocos2d::CCNode* layer, b2World* world,CCSprite *spr,int BulletLife);
	void removeBulletFromParent();
    
	void Update();
	b2Body* bullet_body;
    void setColor(CCSprite *spr,int _life);
    b2Body* getBulletBody();
    void setBulletBody(b2Body* PaddleBody);
    float getRadius();
    float getWidth();
    float getHeight();
    
    CCSprite* getBulletSprite();
    void setBulletSpr(CCSprite *bulletFired);
    int m_numContacts;
    CCSprite* bullet_Sprite;
    //new implementation for contact state change
    void startContact() { m_numContacts++; }
    void endContact() { m_numContacts--; }
    
private:
	
	b2World* m_world;
	cocos2d::CCNode* m_layer;
};
#endif
