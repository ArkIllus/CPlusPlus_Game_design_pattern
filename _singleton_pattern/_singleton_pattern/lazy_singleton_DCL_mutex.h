//#pragma once
//#ifndef _LAZY_SINGLETON_DCL_MUTEX_H_
//#define _LAZY_SINGLETON_DCL_MUTEX_H_
//
//#include <iostream>
//#include <mutex>
//using namespace std;
//
//class LazySingleton_DCL_mutex {
//private:
//	//��ֹ�ⲿ����instance
//	static LazySingleton_DCL_mutex* instance;
//	static mutex lock_;
//	//��ֹ���졢�������������졢��ֵ�����
//	LazySingleton_DCL_mutex() { cout << "����������DCL+mutex��" << endl; }
//	~LazySingleton_DCL_mutex() { cout << "����������DCL+mutex��" << endl; }
//	LazySingleton_DCL_mutex(const LazySingleton_DCL_mutex& temp) { cout << "��������" << endl; }
//	LazySingleton_DCL_mutex& operator= (const LazySingleton_DCL_mutex& temp) { cout << "��ֵ�����" << endl; }
//	//mutex
//public:
//	static LazySingleton_DCL_mutex* getInstance() {
//		cout << "getInstance" << endl;
//		if (instance == nullptr) {
//			lock_guard<mutex> guard(lock_); //����
//			if (instance == nullptr) {
//				instance = new LazySingleton_DCL_mutex();
//				return instance;
//			}
//		}
//		return instance;
//	}
//	// ʵ��һ����Ƕ����������
//	class CGarbo {
//	public:
//		~CGarbo()
//		{
//			cout << "����CGarbo" << endl;
//			if (LazySingleton_DCL_mutex::instance) {
//				delete LazySingleton_DCL_mutex::instance;
//			}
//		}
//	};
//	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
//	static CGarbo Garbo;
//};
//// ����ע�⡿������̬��Ա�����ĳ�ʼ��������.cpp��д��������.h��д
//
//void testLazySingleton_DCL_mutex();
//
//#endif // !_LAZY_SINGLETON_DCL_MUTEX_H_