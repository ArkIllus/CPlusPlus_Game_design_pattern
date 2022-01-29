#pragma once
#ifndef _SPAWNER_H_
#define _SPAWNER_H_
#include "Monster.h"

// Interface
class SpawnerInterface
{
public:
	virtual ~SpawnerInterface(){}
	virtual Monster* spawnMonster() = 0;
};

// 非泛型
class Spawner: public SpawnerInterface
{
public:
	Spawner(Monster* prototype):prototype_(prototype){}
	Monster* spawnMonster()
	{
		return prototype_->clone();
	}
private:
	Monster* prototype_;
};

// 泛型
template <class T>
class SpawnerFor : public SpawnerInterface
{
public:
	SpawnerFor(Monster* prototype): prototype_(prototype){}
	virtual Monster* spawnMonster()
	{
		//return new T(); //调用默认构造函数
		return prototype_->clone();
	}
private:
	Monster* prototype_;
};

// 还可以改进，使用函数指针，舍弃针对每一实例类型的Clone方法
// 略。。。。。。

#endif // !_SPAWNER_H_