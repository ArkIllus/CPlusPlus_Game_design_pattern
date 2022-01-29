#include "Particle.h"

void Particle::init(double x, double y, double xVel, double yVel, int lifetime)
{
	state_.live.x_ = x;
	state_.live.y_ = y;
	state_.live.xVel_ = xVel;
	state_.live.yVel_ = yVel;
	framesLeft_ = lifetime;
}

// �����������һ֡��������һ֡��inUse������true
bool Particle::animate()
{
	if (!inUse()) return false;

	--framesLeft_;
	state_.live.x_ += state_.live.xVel_;
	state_.live.y_ += state_.live.yVel_;
	return framesLeft_ == 0;
}
