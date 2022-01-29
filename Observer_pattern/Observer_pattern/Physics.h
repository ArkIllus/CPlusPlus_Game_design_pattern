#pragma once
#ifndef _PHYSICS_H_
#define _PHYSICS_H_

#include "Entity.h"
#include "Subject.h"

// 这个继承不太好，还可以改进
//class Physics: public Subject
//{
//public:
//	void updateEntity(Entity& entity){}
//};

class Physics
{
	Subject xxx; //一个Subject实例
	//TODO ??? 咋做
public:
	void updateEntity(Entity& entity) {}
};

#endif // !_PHYSICS_H_
