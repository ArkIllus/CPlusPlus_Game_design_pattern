#pragma once
#ifndef _GENRIC_POOL_H_
#define _GENRIC_POOL_H_

// 通用的对象池类
// 通过对象与对象池的解绑，能够实现一个通用、可重用的对象池
template <class TObject>
class GenricPool {
public:
	//GenricPool();

	//void create(double x, double y, double xVel, double yVel, int lifetime);

	//void animate();

private:
	static const int POOL_SIZE = 100;

	TObject pool_[POOL_SIZE];
	bool inUse_[POOL_SIZE];
};

#endif // !_GENRIC_POOL_H_