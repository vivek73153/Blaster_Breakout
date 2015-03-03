
#include "../Ball/Ball.h"

Ball::Ball() {
	velocity.speed = 10;
    
	velocity.x = 3 + rand() % 8;
    //    CCLOG("velocity X %f",velocity.x);
	if (rand() & 1)
		velocity.x = -velocity.x;
	velocity.y = -sqrt(velocity.speed * velocity.speed - velocity.x * velocity.x);
    //    CCLOG("velocity Y %f",velocity.y);
    
	frameLasted = 0;
	frozenFrameLasted = 0;
	skewFrameLasted = 0;
    m_numContacts = 0;
    ballSpr = NULL;
    fireBallSpr = NULL;
}

Ball::~Ball() {
	
}

Ball* Ball::createBall(std::string ballTypeToCreate) {
    
	Ball* ball = new Ball();
	if (ball && ball->initWithFile(ballTypeToCreate.c_str())) {
		return ball;
	}
	CC_SAFE_DELETE(ball);
	return NULL;
    
}


float Ball::getWidth() {
	return this->getTextureRect().getMaxY();
}

float Ball::getHeight() {
	return this->getTextureRect().getMaxX();
}

float Ball::getRadius() {
	return this->getTextureRect().getMaxX() / 2;
}

Velocity Ball::getVelocity() {
	return velocity;
}

Velocity Ball::setVelocity(Velocity v) {
	velocity = v;
}

b2Body* Ball::getBallBody() {
	return ballBody;
}
b2Body* Ball::getFireBallBody() {
	return fireBallBody;
}
void Ball::setFireBallBody(b2Body* ballBody)
{
    this->fireBallBody = ballBody;
}

void Ball::setBallBody(b2Body* ballBody) {
	this->ballBody = ballBody;
}

CCRect Ball::rect() {
    
	CCSize s = this->getContentSize();
	return CCRectMake(this->getPosition().x - s.width / 2,
                      this->getPosition().y - s.height / 2, s.width, s.height);
    
}

void Ball::setFrameLastedTo0() {
	frameLasted = 0;
}

void Ball::frameAddOne() {
	frameLasted++;
}

int Ball::getFrameLasted() {
	return frameLasted;
}

Ball::ballType Ball::getBallState() {
	return typeOfBall;
}

void Ball::setBallState(ballType ballOfTheType) {
	typeOfBall = ballOfTheType;
}

int Ball::getPriority() {
	priority = this->getPosition().y
    - CCDirector::sharedDirector()->getWinSize().height;
	priority += ballBody->GetLinearVelocity().y;
	return priority;
}

int Ball::getFrozenFrameLasted() {
	return frozenFrameLasted;
}

void Ball::setFrozenFrameTo0() {
	frozenFrameLasted = 0;
}

void Ball::skewFrameAddOne() {
	skewFrameLasted++;
}

int Ball::getSkewFrameLasted() {
	return skewFrameLasted;
}

void Ball::setSkewFrameLastedTo0() {
	skewFrameLasted = 0;
}
void Ball::UnInit(b2World *removeFromWorld)
{
    //	m_layer->removeChild( brickSprites, true );
    ballSpr->removeFromParentAndCleanup(true);
    removeFromWorld->DestroyBody(ballBody);
}
//Bouncing against a vertical line.
void Ball::verticalBounce(float pAngle)
{
    if(angle == 0.0f || angle == 180.0f)
        angle += -180.0f;
    else
        angle = 180.0f - angle;
    bouncing(angle);
}

//Bouncing against a horizontal line.
void Ball::horizontalBounce(float pAngle)
{
    if(angle == 0.0f || angle == 180.0f)
        angle += -180.0f;
    else
        angle = 360.0f - angle;
    bouncing(angle);
}

//Shared bouncing function
void Ball::bouncing(float pAngle)
{
    if(angle < 0.0f) angle += 360.0f;
    if(angle > 360.0f) angle -= 360.0f;
    
    this->angleRad = this->angle * M_PI/180.0f;
    this->velocityX = cos(this->angleRad) * this->speed;
    this->velocityY = sin(this->angleRad) * this->speed;
}

CCSprite* Ball::getBallSprite()
{
    return ballSpr;
}

void Ball::setBallSpr(CCSprite *ballSprite )
{
    ballSpr = ballSprite;
}

CCSprite* Ball::getFireBallSprite()
{
    return fireBallSpr;
}

void Ball::setFireBallSpr(CCSprite *firedBall)
{
    fireBallSpr = firedBall;
}

void Ball::update(b2Body *fireballBodyForMove,CCSprite *fireSpr)
{
    fireBallBody = fireballBodyForMove;
    fireBallSpr = fireSpr;
    if( fireBallBody != NULL)
    {
        b2Vec2 gv = fireballBodyForMove->GetLinearVelocity();
        float gs = gv.x * gv.x + gv.y * gv.y*10;
      
        b2Vec2 *gf = new b2Vec2(gv.x, gv.y);
        fireballBodyForMove->SetLinearVelocity(*gf);
    }
}
