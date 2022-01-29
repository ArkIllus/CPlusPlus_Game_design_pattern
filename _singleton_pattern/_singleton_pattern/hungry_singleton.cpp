#include "hungry_singleton.h"
#include <iostream>
using namespace std;

// 【【注意】】：静态成员变量的初始化必须在.cpp里写，不能在.h里写，否则会报错：找到一个或多个多重定义的符号
// （类似全局变量，在main()程序开始时就构造，main()程序结束时才执行析构）
HungrySingleton* HungrySingleton::instance = new HungrySingleton();

void testHungrySingleton() {
	//Singleton s; //禁止构造
	//Singleton* s2 = new Singleton(); //禁止构造

	//Singleton s = &(Singleton::getInstance()); //表达式必须为左值或函数指示符

	cout << "在testHungrySingleton程序的开始" << endl;
	HungrySingleton::getInstance();
	HungrySingleton* s = HungrySingleton::getInstance(); //可以 //并没有构造
	cout << "在testHungrySingleton程序的结束" << endl;
}