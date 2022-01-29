#pragma once
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

// 粒子类
class Particle {
	// 可以通过声明友元，并把下面的构造函数私有化，实现保证对象只能通过对象池创建
	//friend class ParitclePool;
public:
	// 默认构造函数将粒子初始化为“未使用”状态
	Particle(): framesLeft_(0){}

	// init()将其状态设置为“使用中”
	void init(double x, double y, double xVel, double yVel, int lifetime);

	// 粒子随着时间播放动画，并逐帧调用函数animate()
	// 如果粒子在这一帧死掉（上一帧还inUse）返回true
	bool animate();

	bool inUse() const { return framesLeft_ > 0; }

	Particle* getNext() const { return state_.next; }
	void setNext(Particle* next) {
		state_.next = next;
	}

private:
	int framesLeft_;
	//double x_, y_;
	//double xVel_, yVel_;

	// 空闲表（free list），使用union联合体节省内存
	union {
		// state when it's in use.
		struct {
			double x_, y_, xVel_, yVel_;
		}live;

		// state when it's available(not in use).
		Particle* next; // 存储指向下一个可用粒子的指针
	}state_;
};

#endif // !_PARTICLE_H_
