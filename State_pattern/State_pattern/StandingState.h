#pragma once
#ifndef _STANDINGSTATE_H_
#define _STANDINGSTATE_H_

#include "HeroineState.h"
#include "Heroine.h"
#include "DuckingState.h"
#include <iostream>
using namespace std;

// 站立状态
class StandingState : public HeroineState {
public:
	StandingState() {}
	//virtual void handleInput(Heroine& heroine, Input input) {
	// 做法二：实例化状态
	virtual HeroineState* handleInput(Heroine& heroine, Input input) {
		if (input == PRESS_DOWN) { // 切换到躲避状态
			// other code...
			return new DuckingState();
		}
		// 保持此状态
		return nullptr;
	}
	virtual void update(Heroine& heroine) {
	}
	// entry （进入此状态时执行）（不关心上一个状态是什么）
	virtual void enter(Heroine& heroine) {
		heroine.setGraphics(IMAGE_STAND);
		printf("current image is: STAND");
	}
};

#endif // !_STANDINGSTATE_H_
