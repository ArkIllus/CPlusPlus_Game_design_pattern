#include "hungry_singleton.h"
#include <iostream>
using namespace std;

// ����ע�⡿������̬��Ա�����ĳ�ʼ��������.cpp��д��������.h��д������ᱨ���ҵ�һ���������ض���ķ���
// ������ȫ�ֱ�������main()����ʼʱ�͹��죬main()�������ʱ��ִ��������
HungrySingleton* HungrySingleton::instance = new HungrySingleton();

void testHungrySingleton() {
	//Singleton s; //��ֹ����
	//Singleton* s2 = new Singleton(); //��ֹ����

	//Singleton s = &(Singleton::getInstance()); //���ʽ����Ϊ��ֵ����ָʾ��

	cout << "��testHungrySingleton����Ŀ�ʼ" << endl;
	HungrySingleton::getInstance();
	HungrySingleton* s = HungrySingleton::getInstance(); //���� //��û�й���
	cout << "��testHungrySingleton����Ľ���" << endl;
}