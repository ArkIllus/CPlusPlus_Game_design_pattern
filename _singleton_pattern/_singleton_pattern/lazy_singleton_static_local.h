// ����ģʽ ��Ҫʱ�Ŵ�������
// �����д������̬�ֲ�����
// C++11�涨�˾�̬�ֲ��������ڴ�ģ�ͣ�
//������˵���ǹ涨�˵�һ���߳����ڳ�ʼ��һ������ʱ�������̱߳���ȵ���ʼ����ɺ���ܷ��ʸñ�����
//�����C++11֮������д�����̰߳�ȫ��

#pragma once
#ifndef _LAZY_SINGLETON_STATIC_LOCAL_H_
#define _LAZY_SINGLETON_STATIC_LOCAL_H_

#include <iostream>
using namespace std;

class LazySingleton_StaticLocal {
private:
	//��ֹ�ⲿ����instance
	static LazySingleton_StaticLocal* instance; // ���п��п���
	//��ֹ���졢�������������졢��ֵ�����
	LazySingleton_StaticLocal(){ cout << "����������local static��" << endl; }
	~LazySingleton_StaticLocal(){ cout << "����������local static��" << endl; }
	LazySingleton_StaticLocal(const LazySingleton_StaticLocal& temp);
	LazySingleton_StaticLocal& operator=(const LazySingleton_StaticLocal& temp);
public:
	static LazySingleton_StaticLocal* getInstance() {
		cout << "getInstance" << endl;
		static LazySingleton_StaticLocal instance;
		return &instance;
	}
};

void testLazySingleton_StaticLocal();

#endif // !_LAZY_SINGLETON_STATIC_LOCAL_H_