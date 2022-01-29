#pragma once
#ifndef _SLIME_H_
#define _SLIME_H_

#include "Monster.h"
#include <iostream>

class Slime : public Monster {
public:
	Slime() :health_(3), speed_(1) {} //默认构造函数
	Slime(int health, int speed) :health_(health), speed_(speed) {}
	//virtual Slime* clone() {
	virtual Monster* clone() {
		return new Slime(health_, speed_);
	}
	int gethealth() { return health_; }
	int getspeed() { return speed_; }
	void print() { std::cout << "health = " << gethealth() << ", speed = " << getspeed() << std::endl; }
private:
	int health_;
	int speed_;
};

#endif // !_SLIME_H_
