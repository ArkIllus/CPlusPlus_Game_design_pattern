// 饿汉模式
//（是线程安全的，一开始就会把这个类的单例创建出来，缺点是如果这个类比较大，而且长时间并不使用它，可能很浪费空间）

#pragma once
#ifndef _HUNGRY_SINGLETON_H_
#define _HUNGRY_SINGLETON_H_

#include <iostream>
using namespace std;

class HungrySingleton {
private:
	//static int m = 1;//static成员变量只能在类内声明，不能在类内初始化，除非是const static
	const static int n = 1;

	//禁止外部访问instance
	static HungrySingleton* instance;
	//禁止构造、析构、拷贝构造、赋值运算符
	HungrySingleton() { cout << "构造饿汉" << endl; }
	~HungrySingleton() { cout << "析构饿汉" << endl; }
	HungrySingleton(const HungrySingleton& temp);
	HungrySingleton& operator= (const HungrySingleton& temp);
public:
	static HungrySingleton* getInstance() {
		cout << "getInstance" << endl;
		return instance;
	}
};
// 【【注意】】：静态成员变量的初始化必须在.cpp里写，不能在.h里写，否则会报错：找到一个或多个多重定义的符号
// （类似全局变量，在main()程序开始时就构造，main()程序结束时才执行析构）

void testHungrySingleton();

#endif // !_HUNGRY_SINGLETON_H_