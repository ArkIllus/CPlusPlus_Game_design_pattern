#include "lazy_singleton_static_local.h"
#include <iostream>
using namespace std;


void testLazySingleton_StaticLocal() {
	cout << "��testLazySingleton_StaticLocal����Ŀ�ʼ" << endl;
	LazySingleton_StaticLocal::getInstance();
	LazySingleton_StaticLocal* s = LazySingleton_StaticLocal::getInstance();
	cout << "��testLazySingleton_StaticLocal����Ľ���" << endl;
}