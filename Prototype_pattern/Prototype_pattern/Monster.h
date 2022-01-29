#pragma once
#ifndef _MONSTER_H_
#define _MONSTER_H_

// interface
// 如果类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类。
class Monster
{
public:
	virtual ~Monster()
	{
	}
	virtual Monster* clone() = 0; //Pure virtual function
	virtual void print() = 0;
};

#endif // !_MONSTER_H_
