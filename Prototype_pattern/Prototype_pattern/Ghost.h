#pragma once
#ifndef _GHOST_H_
#define _GHOST_H_
#include "Monster.h"
#include <iostream>

class Ghost : public Monster
{
public:
	Ghost():health_(5),speed_(2){} //默认构造函数
	Ghost(int health, int speed):health_(health),speed_(speed){}
	virtual Monster* clone()
	{
		return new Ghost(health_, speed_);
	}
	int gethealth() { return health_; }
	int getspeed() { return speed_; }
	void print() { std::cout << "health = " << gethealth() << ", speed = " << getspeed() << std::endl; }
private:
	int health_;
	int speed_;
};

#endif // !_GHOST_H_
