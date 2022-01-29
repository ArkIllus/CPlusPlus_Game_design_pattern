#pragma once
#ifndef _PARTICLE_POOL_H_
#define _PARTICLE_POOL_H_

#include "Particle.h"

// �������
class ParticlePool {
public:
	// ������״α�����ʱ�����е����Ӿ����ڿ��ã�not in use��״̬
	ParticlePool();

	// ���������ִ�Ķ��󣨶����ж��ֳ�ʼ��������
	// 1.�ڶ�����ڲ���ʼ������
	void create(double x, double y, double xVel, double yVel, int lifetime);
	// 2.�ڶ�������ʼ������
	//Particle* create(){ //Return reference to available particle...}
	//����ʱ������
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
	// ������ʵ���У�����洢���ӵ�����Ĵ�С���������б�Ӳ����̶���
	// ��ȻҲ����ͨ�����ݸ����Ĵ�Сʹ�ö�̬���飬����ʹ��ֵĩ����������塣
	static const int POOL_SIZE = 100;
	Particle particles_[POOL_SIZE];

	Particle* firstAvailable_; // ׷�ٿ��б����������б���ͷָ��
};

#endif // !_PARTICLE_POOL_H_
