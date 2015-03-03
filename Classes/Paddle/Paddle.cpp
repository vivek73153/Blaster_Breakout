
#include "../Paddle/Paddle.h"

Paddle::Paddle() {

	paddleBodyDef.type = b2_dynamicBody;
	lengthState = normalPaddle;
	frameLasted = 0;

}

b2BodyDef* Paddle::getBodyDef() {
	return &paddleBodyDef;

}

Paddle::~Paddle() {
}

Paddle::lengthType Paddle::getLengthState() {
	return lengthState;
}

void Paddle::setLengthState(lengthType length) {
	lengthState = length;
}

void Paddle::setFrameLastedTo0() {
	frameLasted = 0;
}
int Paddle::getFrameLasted() {
	return frameLasted;
}
void Paddle::frameAddOne() {
	frameLasted++;
}

