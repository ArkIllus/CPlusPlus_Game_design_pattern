// ����ģʽ
//�����̰߳�ȫ�ģ�һ��ʼ�ͻ�������ĵ�������������ȱ������������Ƚϴ󣬶��ҳ�ʱ�䲢��ʹ���������ܺ��˷ѿռ䣩

#pragma once
#ifndef _HUNGRY_SINGLETON_H_
#define _HUNGRY_SINGLETON_H_

#include <iostream>
using namespace std;

class HungrySingleton {
private:
	//static int m = 1;//static��Ա����ֻ�����������������������ڳ�ʼ����������const static
	const static int n = 1;

	//��ֹ�ⲿ����instance
	static HungrySingleton* instance;
	//��ֹ���졢�������������졢��ֵ�����
	HungrySingleton() { cout << "�������" << endl; }
	~HungrySingleton() { cout << "��������" << endl; }
	HungrySingleton(const HungrySingleton& temp);
	HungrySingleton& operator= (const HungrySingleton& temp);
public:
	static HungrySingleton* getInstance() {
		cout << "getInstance" << endl;
		return instance;
	}
};
// ����ע�⡿������̬��Ա�����ĳ�ʼ��������.cpp��д��������.h��д������ᱨ���ҵ�һ���������ض���ķ���
// ������ȫ�ֱ�������main()����ʼʱ�͹��죬main()�������ʱ��ִ��������

void testHungrySingleton();

#endif // !_HUNGRY_SINGLETON_H_