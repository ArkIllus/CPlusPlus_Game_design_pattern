#pragma once
#ifndef _HEROINESTATE_H_
#define _HEROINESTATE_H_

#include "Heroine.h"
#include "Input.h"
#include "DuckingState.h"
#include "StandingState.h"

// interface 状态接口 
// 不是抽象类?
class HeroineState {
public:
	// 7.5 状态对象应该放在哪里呢? 有2种做法。
	// 
	// 做法一：静态状态：
	// ①一个状态对象没有任何数据成员，它唯一的数据成员就是虚表指针，可以用静止状态
	// ②虽然有成员变量（比如chargeTime_），但是只有一个主角，依然可以用静止状态
	//static DuckingState ducking;
	//static StandingState standing;
	//static JumpingState jumping;
	//static DivingState diving;
	// 状态改变时，只要在以上状态之间切换就可以了
	//
	// 做法二：实例化状态
	// 有成员变量（比如chargeTime_），有多个主角
	// 此时因为要创建新状态/删除旧状态，要特别注意内存管理 
public:
	virtual ~HeroineState() {}
	//virtual void handleInput(Heroine& heroine, Input input) {}
	virtual HeroineState* handleInput(Heroine& heroine, Input input) {}
	virtual void update(Heroine& heroine){}
	// entry （进入此状态时执行）（不关心上一个状态是什么）
	virtual void enter(Heroine& heroine) {}
};

#endif // !_HEROINESTATE_H_
