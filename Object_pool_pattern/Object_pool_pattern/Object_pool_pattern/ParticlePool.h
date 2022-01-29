#pragma once
#ifndef _PARTICLE_POOL_H_
#define _PARTICLE_POOL_H_

#include "Particle.h"

// �������
class ParticlePool {
public:
	// ������״α�����ʱ�����е����Ӿ����ڿ��ã�not in use��״̬
	ParticlePool();

	void create(double x, double y, double xVel, double yVel, int lifetime);

	void animate();

private:
	// ������ʵ���У�����洢���ӵ�����Ĵ�С���������б�Ӳ����̶���
	// ��ȻҲ����ͨ�����ݸ����Ĵ�Сʹ�ö�̬���飬����ʹ��ֵĩ����������塣
	static const int POOL_SIZE = 100;
	Particle particles_[POOL_SIZE];

	Particle* firstAvailable_; // ׷�ٿ��б����������б���ͷָ��
};

#endif // !_PARTICLE_POOL_H_
