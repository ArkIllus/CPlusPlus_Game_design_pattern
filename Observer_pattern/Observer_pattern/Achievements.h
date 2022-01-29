#pragma once
#ifndef _ACHIEVEMENTS_H_
#define _ACHIEVEMENTS_H_

#include "Observer.h"
//#include "Entity.h"
//#include "Event.h"

// An Achievement
//class Achievement
//{
//
//};
enum class Achievement
{
	ACHIEVEMENT_FELL_OFF_BRIDGE,
	ACHIEVEMENT_FIRST_FLY,
};

// Achievements System (implement Observer interface)
class Achievements : public Observer
{
public:
	virtual void onNotify(const Entity& entity, Event event)
	{
		// 感觉这里用switch是有问题的
		switch (event) //表达式必须包含整数或枚举类型
		{
		case Event::EVENT_ENTITY_FELL:
			if (entity.isHero && heroIsOnBridge_)
			{
				unlock(Achievement::ACHIEVEMENT_FELL_OFF_BRIDGE);
			}
			break;
		case Event::EVENT_ENTITY_FLY:
			if (entity.isHero && heroIsFlying_)
			{
				unlock(Achievement::ACHIEVEMENT_FIRST_FLY);
			}
			break;
		// Handle other events ...
		// Update heroIsOnBridge_ ... ?????
		default:
			break;
		}
	}
private:
	void unlock(Achievement achievement)
	{
		// Unlock if not already unlocked
	}
	bool heroIsOnBridge_;
	bool heroIsFlying_;
};

#endif // !_ACHIEVEMENTS_H_

