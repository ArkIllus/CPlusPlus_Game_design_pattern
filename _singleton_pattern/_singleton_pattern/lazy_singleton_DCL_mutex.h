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
//	//禁止外部访问instance
//	static LazySingleton_DCL_mutex* instance;
//	static mutex lock_;
//	//禁止构造、析构、拷贝构造、赋值运算符
//	LazySingleton_DCL_mutex() { cout << "构造懒汉（DCL+mutex）" << endl; }
//	~LazySingleton_DCL_mutex() { cout << "析构懒汉（DCL+mutex）" << endl; }
//	LazySingleton_DCL_mutex(const LazySingleton_DCL_mutex& temp) { cout << "拷贝构造" << endl; }
//	LazySingleton_DCL_mutex& operator= (const LazySingleton_DCL_mutex& temp) { cout << "赋值运算符" << endl; }
//	//mutex
//public:
//	static LazySingleton_DCL_mutex* getInstance() {
//		cout << "getInstance" << endl;
//		if (instance == nullptr) {
//			lock_guard<mutex> guard(lock_); //上锁
//			if (instance == nullptr) {
//				instance = new LazySingleton_DCL_mutex();
//				return instance;
//			}
//		}
//		return instance;
//	}
//	// 实现一个内嵌垃圾回收类
//	class CGarbo {
//	public:
//		~CGarbo()
//		{
//			cout << "析构CGarbo" << endl;
//			if (LazySingleton_DCL_mutex::instance) {
//				delete LazySingleton_DCL_mutex::instance;
//			}
//		}
//	};
//	// 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
//	static CGarbo Garbo;
//};
//// 【【注意】】：静态成员变量的初始化必须在.cpp里写，不能在.h里写
//
//void testLazySingleton_DCL_mutex();
//
//#endif // !_LAZY_SINGLETON_DCL_MUTEX_H_