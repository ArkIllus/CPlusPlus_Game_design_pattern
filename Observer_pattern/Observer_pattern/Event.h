#pragma once
#ifndef _EVENT_H_
#define _EVENT_H_

//class Event
//{
//	int event_index;
//public:
//	Event(int x): event_index(x){}
//	int index() { return event_index; }
//};

// vs建议：Subject::notify中，枚举类型未设定范围，相比enum建议首选enum class
enum class Event
{
	EVENT_ENTITY_FELL,
	EVENT_ENTITY_FLY
};

#endif // !_EVENT_H_
