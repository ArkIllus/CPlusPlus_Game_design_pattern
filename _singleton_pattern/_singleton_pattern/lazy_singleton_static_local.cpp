#include "lazy_singleton_static_local.h"
#include <iostream>
using namespace std;


void testLazySingleton_StaticLocal() {
	cout << "在testLazySingleton_StaticLocal程序的开始" << endl;
	LazySingleton_StaticLocal::getInstance();
	LazySingleton_StaticLocal* s = LazySingleton_StaticLocal::getInstance();
	cout << "在testLazySingleton_StaticLocal程序的结束" << endl;
}