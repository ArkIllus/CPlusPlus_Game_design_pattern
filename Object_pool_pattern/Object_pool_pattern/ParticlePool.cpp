#include "ParticlePool.h"
#include <cassert>

// ������״α�����ʱ�����е����Ӿ����ڿ��ã�not in use��״̬
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

// ����һ������particles_���飬�ҵ��׸����õ����ӡ�һ���ҵ����Ͱ�����ʼ�������أ�
// ע�⣺������汾��ʵ���У����û���ҵ����õ����ӣ����ٴ��������ӡ�
// 
// ȱ�㣺ʱ�临�Ӷ�O(n)
// �������������ܴ��Ҽ������������ʱ�������ӽ���ʮ�ֻ�����
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

// �����������б�free list��
// �������ά��һ��ָ��ÿ��δ��ʹ�õ����ӵ�ָ���б�����б���ܺͶ���صĶ�������һ����
// Q: ��β������ڴ�����������? 
// A: ʹ����Щδ�����õ���������! Ҳ����ʹ��union������
// ˵���������ļ��ɣ�������SGI�����ռ����������ڴ�أ�memory pool����Ҳ��ʹ��free list��
// 
// �ŵ㣺ʱ�临�Ӷ�O(1)
void ParticlePool::create(double x, double y, double xVel, double yVel, int lifetime)
{
	// Make sure the pool isn't full.
	// TODO: ����100�����ӻᱨ��
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
		// �����������һ֡�������Ͱ�����ӻؿ��б�����ǰ��=�µ�ͷָ�롿
		if (particles_[i].animate()) {
			// Add this particle to the front of the list.
			particles_[i].setNext(firstAvailable_);
			firstAvailable_ = &particles_[i];
		}
	}
}
