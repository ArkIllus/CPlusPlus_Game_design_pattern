#pragma once
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

// ������
class Particle {
public:
	// Ĭ�Ϲ��캯�������ӳ�ʼ��Ϊ��δʹ�á�״̬
	Particle(): framesLeft_(0){}

	// init()����״̬����Ϊ��ʹ���С�
	void init(double x, double y, double xVel, double yVel, int lifetime);

	// ��������ʱ�䲥�Ŷ���������֡���ú���animate()
	// �����������һ֡��������һ֡��inUse������true
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

	// ���б�free list����ʹ��union�������ʡ�ڴ�
	union {
		// state when it's in use.
		struct {
			double x_, y_, xVel_, yVel_;
		}live;

		// state when it's available(not in use).
		Particle* next; // �洢ָ����һ���������ӵ�ָ��
	}state_;
};

#endif // !_PARTICLE_H_
