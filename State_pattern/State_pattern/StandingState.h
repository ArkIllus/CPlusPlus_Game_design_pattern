#pragma once
#ifndef _STANDINGSTATE_H_
#define _STANDINGSTATE_H_

#include "HeroineState.h"
#include "Heroine.h"
#include "DuckingState.h"
#include <iostream>
using namespace std;

// վ��״̬
class StandingState : public HeroineState {
public:
	StandingState() {}
	//virtual void handleInput(Heroine& heroine, Input input) {
	// ��������ʵ����״̬
	virtual HeroineState* handleInput(Heroine& heroine, Input input) {
		if (input == PRESS_DOWN) { // �л������״̬
			// other code...
			return new DuckingState();
		}
		// ���ִ�״̬
		return nullptr;
	}
	virtual void update(Heroine& heroine) {
	}
	// entry �������״̬ʱִ�У�����������һ��״̬��ʲô��
	virtual void enter(Heroine& heroine) {
		heroine.setGraphics(IMAGE_STAND);
		printf("current image is: STAND");
	}
};

#endif // !_STANDINGSTATE_H_
