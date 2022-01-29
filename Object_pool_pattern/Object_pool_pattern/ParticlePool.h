#pragma once
#ifndef _PARTICLE_POOL_H_
#define _PARTICLE_POOL_H_

#include "Particle.h"

// 对象池类
class ParticlePool {
public:
	// 对象池首次被创建时，所有的粒子均处于可用（not in use）状态
	ParticlePool();

	// 考虑重用现存的对象（对象有多种初始化函数）
	// 1.在对象池内部初始化对象
	void create(double x, double y, double xVel, double yVel, int lifetime);
	// 2.在对象池外初始化对象
	//Particle* create(){ //Return reference to available particle...}
	//调用时这样：
	//Particle* particle = pool.create();
	//if (particle != nullptr) {
	//	pool.create()->init(1, 2);
	//}
	//...
	//pool.create()->init(1, 2, 3);
	//...
	//pool.create()->init(1, 2, 3, 4);

	void animate();

private:
	// 本例的实现中，这个存储粒子的数组的大小在类声明中被硬编码固定，
	// 当然也可以通过根据给定的大小使用动态数组，或者使用值末班参数来定义。
	static const int POOL_SIZE = 100;
	Particle particles_[POOL_SIZE];

	Particle* firstAvailable_; // 追踪空闲表（可用粒子列表）的头指针
};

#endif // !_PARTICLE_POOL_H_
