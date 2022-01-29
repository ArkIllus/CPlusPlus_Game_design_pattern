#pragma once
#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "Entity.h"
#include "Event.h"

// C++ interface //观察者接口
class Observer
{
	friend class Subject; //
private:
	Observer* next_;
public:
	Observer():next_(nullptr){}
	virtual ~Observer(){}
	virtual void onNotify(const Entity& entity, Event event) = 0;
};

#endif // !_OBSERVER_H_
