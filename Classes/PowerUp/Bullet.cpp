#include "../PowerUp/Bullet.h"
#define PTM_RATIO 32

Bullet::Bullet(void)
{
	bullet_body = NULL;
	bullet_Sprite = NULL;
}


Bullet::~Bullet(void)
{
}

void Bullet::Init(cocos2d::CCNode* layer, b2World* world,CCSprite *spr,int BulletLife)
{
	m_world = world;
	m_layer = layer;
    bullet_Sprite = spr;
    bullet_Sprite->setTag(5);
    
    b2BodyDef ballBodyDef;
    ballBodyDef.type = b2_dynamicBody;
    ballBodyDef.position.Set(bullet_Sprite->getPosition().x / PTM_RATIO,
                             bullet_Sprite->getPosition().y / PTM_RATIO);
    ballBodyDef.userData = bullet_Sprite;
    ballBodyDef.gravityScale = 0.0f;
    this->setBulletBody(world->CreateBody(&ballBodyDef));
    this->getBulletBody()->SetUserData(bullet_Sprite);
    
	
    b2CircleShape circle;
    circle.m_radius = this->getRadius() / PTM_RATIO;
    
    //    b2FixtureDef ballFixtureDef;
    //    ballFixtureDef.shape = &circle;
    //    ballFixtureDef.density = 0.0f;
    //    ballFixtureDef.restitution = 0.0f;
    //    ballFixtureDef.friction = 0.0f;
    //	bullet_body->CreateFixture( &ballFixtureDef);
}

float Bullet::getRadius() {
	return this->getTextureRect().getMaxX() / 2;
}
float Bullet::getWidth() {
	return this->getTextureRect().getMaxY();
}

float Bullet::getHeight() {
	return this->getTextureRect().getMaxX();
}

void Bullet::removeBulletFromParent()
{
	bullet_Sprite->removeFromParentAndCleanup(true);
	m_world->DestroyBody(bullet_body);
}

void Bullet::setColor(CCSprite *spr,int life){
    switch (life) {
        case 1:
            //Orange
            //           spr->setColor(ccc3(236,87,44));
            spr->setColor(ccc3(210,105,30));
            break;
        case 2:
            //Red
            //            spr->setColor(ccc3(246,142,40));
            spr->setColor(ccc3(255,255,0));
            
            break;
        case 3:
            //Grey
            //            spr->setColor(ccc3(173 ,173 ,173));
            spr->setColor(ccc3(112,128,144));
            
            break;
    }
}

CCSprite* Bullet::getBulletSprite() {
	return bullet_Sprite;
}

void Bullet::setBulletSpr(CCSprite* bulletSpr) {
	this->bullet_Sprite = bulletSpr;
}


b2Body* Bullet::getBulletBody() {
	return bullet_body;
}

void Bullet::setBulletBody(b2Body* bulletBody) {
	this->bullet_body = bulletBody;
}

void Bullet::Update()
{
    //	if( bullet_body != NULL && bullet_Sprite != NULL )
    //	{
    //		bullet_Sprite->setPosition(ccp(bullet_body->GetPosition().x ,
    //                                  bullet_body->GetPosition().y * PTM_RATIO));
    ////		bullet_Sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(bullet_body->GetAngle()));
    //	}
}