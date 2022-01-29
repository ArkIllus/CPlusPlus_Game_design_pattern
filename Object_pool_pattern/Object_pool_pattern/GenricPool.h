#pragma once
#ifndef _GENRIC_POOL_H_
#define _GENRIC_POOL_H_

// ͨ�õĶ������
// ͨ�����������صĽ���ܹ�ʵ��һ��ͨ�á������õĶ����
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