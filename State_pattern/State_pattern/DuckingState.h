#pragma once
#ifndef _DUCKINGSTATE_H_
#define _DUCKINGSTATE_H_

#include "HeroineState.h"
#include "Heroine.h"
#include <iostream>
using namespace std;

constexpr int MAX_CHARGE_TIME = 3;

// 躲避状态
class DuckingState : public HeroineState {
public:
	DuckingState():chargeTime_(0){}
	//virtual void handleInput(Heroine& heroine, Input input) {
	// 做法二：实例化状态
	virtual HeroineState* handleInput(Heroine& heroine, Input input) {
		if (input == RELEASE_DOWN) {
			// 切换到站立状态
			return new StandingState();
		}
		// 保持此状态
		return nullptr;
	}
	virtual void update(Heroine& heroine) {
		++chargeTime_;
		if (chargeTime_ > MAX_CHARGE_TIME) {
			heroine.superBomb(); //蓄力跳
		}
	}
	// entry（进入此状态时执行）（不关心上一个状态是什么）
	virtual void enter(Heroine& heroine) {
		heroine.setGraphics(IMAGE_DUCK);
		printf("current image is: DUCK");
	}
private:
	int chargeTime_; //蓄力跳的充能时间 //这个变量不再放在主角Heroine类里，这非常好
};

#endif // !_DUCKINGSTATE_H_
