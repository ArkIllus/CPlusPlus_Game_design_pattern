#pragma once
#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include "Observer.h"

#define MAX_OBSERVERS 100

class Subject
{
private:
	//观察者列表:
	//实现1.数组or可变数组
	//Observer* observers_[MAX_OBSERVERS]; //or use vector
	//int numObservers_;
	//实现2.使用单向/双向链表:
	Observer* head_;

	//TODO:这样做的问题：一个观察者在任意时刻只可以观察一个被观察者对象（？？？）

public:
	Subject():head_(nullptr){}
	void addObserver(Observer* observer)
	{
		//方式1.添加到头
		observer->next_ = head_;
		head_ = observer;
		//方式2.添加到尾部...
	}
	void removeObserver(Observer* observer)
	{
		//从头到尾遍历一遍
		if (head_ == observer)
		{
			head_ = head_->next_;
			observer->next_ = nullptr;
			return;
		}

		Observer* current = head_;
		while (current != observer)
		{
			if (current->next_ == observer)
			{
				current->next_ = observer->next_;
				observer->next_ = nullptr;
				return;
			}
			current = current->next_;
		}
	}
protected:
	// vs建议：枚举类型未设定范围，相比enum建议首选enum class
	// 所以Event改为enum class
	// TODO:考虑观察者们在notify()中修改观察者列表的情况

	//实现1.数组or可变数组
	//void notify(const Entity& entity, Event event)
	//{
	//	for (int i = 0; i < numObservers_; i++)
	//	{
	//		observers_[i]->onNotify(entity, event);
	//	}
	//}
	//实现2.使用单向/双向链表:
	void notify(const Entity& entity, Event event)
	{
		Observer* observer = head_;
		while (observer != nullptr)
		{
			observer->onNotify(entity, event);
			observer = observer->next_;
		}
	}
};

#endif // !_SUBJECT_H_
