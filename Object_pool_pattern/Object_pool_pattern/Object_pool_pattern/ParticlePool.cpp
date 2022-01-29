#include "ParticlePool.h"
#include <cassert>

// 对象池首次被创建时，所有的粒子均处于可用（not in use）状态
ParticlePool::ParticlePool()
{
	// The first one is Available
	firstAvailable_ = &particles_[0];

	// Each particle points to the next;
	for (int i = 0; i < POOL_SIZE - 1; i++)
	{
		particles_[i].setNext(&particles_[i + 1]);
	}

	// The last one terminates the list.
	particles_[POOL_SIZE - 1].setNext(nullptr);
}

// 方法一：遍历particles_数组，找到首个可用的粒子。一旦找到，就把它初始化并返回；
// 注意：在这个版本的实现中，如果没有找到可用的粒子，则不再创建新粒子。
// 
// 缺点：时间复杂度O(n)
// 假设这个池数组很大且几乎已满，则此时创建粒子将会十分缓慢。
//void PartilcePool::create(double x, double y, double xVel, double yVel, int lifetime)
//{
//	for (int i = 0; i < POOL_SIZE; i++)
//	{
//		if (!particles_[i].inUse())
//		{
//			particles_[i].init(x, y, xVel, yVel, lifetime);
//			return;
//		}
//	}
//}

// 方法二：空闲表（free list）
// 如果单独维护一个指向每个未被使用的粒子的指针列表，这个列表可能和对象池的对象数组一样大。
// Q: 如何不牺牲内存解决性能问题? 
// A: 使用那些未被利用的粒子自身! 也就是使用union联合体
// 说明：常见的技巧，比如在SGI二级空间配置器的内存池（memory pool）中也有使用free list。
// 
// 优点：时间复杂度O(1)
void ParticlePool::create(double x, double y, double xVel, double yVel, int lifetime)
{
	// Make sure the pool isn't full.
	// TODO: 超过100个粒子会报错
	assert(firstAvailable_ != nullptr);

	// Remove it from the available list.
	Particle* newParticle = firstAvailable_;
	firstAvailable_ = newParticle->getNext();

	newParticle->init(x, y, xVel, yVel, lifetime);
}

void ParticlePool::animate()
{
	for (int i = 0; i < POOL_SIZE; i++)
	{
		// 如果粒子在这一帧死掉，就把它添加回空闲表【的最前面=新的头指针】
		if (particles_[i].animate()) {
			// Add this particle to the front of the list.
			particles_[i].setNext(firstAvailable_);
			firstAvailable_ = &particles_[i];
		}
	}
}
