// 懒汉模式 需要时才创建单例
// 最简洁的写法：静态局部变量
// C++11规定了静态局部变量的内存模型，
//具体来说就是规定了当一个线程正在初始化一个变量时，其他线程必须等到初始化完成后才能访问该变量，
//因此在C++11之后这种写法是线程安全的

#pragma once
#ifndef _LAZY_SINGLETON_STATIC_LOCAL_H_
#define _LAZY_SINGLETON_STATIC_LOCAL_H_

#include <iostream>
using namespace std;

class LazySingleton_StaticLocal {
private:
	//禁止外部访问instance
	static LazySingleton_StaticLocal* instance; // 这行可有可无
	//禁止构造、析构、拷贝构造、赋值运算符
	LazySingleton_StaticLocal(){ cout << "构造懒汉（local static）" << endl; }
	~LazySingleton_StaticLocal(){ cout << "析构懒汉（local static）" << endl; }
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