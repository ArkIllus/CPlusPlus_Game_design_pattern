#pragma once
#ifndef _DUCKINGSTATE_H_
#define _DUCKINGSTATE_H_

#include "HeroineState.h"
#include "Heroine.h"
#include <iostream>
using namespace std;

constexpr int MAX_CHARGE_TIME = 3;

// ���״̬
class DuckingState : public HeroineState {
public:
	DuckingState():chargeTime_(0){}
	//virtual void handleInput(Heroine& heroine, Input input) {
	// ��������ʵ����״̬
	virtual HeroineState* handleInput(Heroine& heroine, Input input) {
		if (input == RELEASE_DOWN) {
			// �л���վ��״̬
			return new StandingState();
		}
		// ���ִ�״̬
		return nullptr;
	}
	virtual void update(Heroine& heroine) {
		++chargeTime_;
		if (chargeTime_ > MAX_CHARGE_TIME) {
			heroine.superBomb(); //������
		}
	}
	// entry�������״̬ʱִ�У�����������һ��״̬��ʲô��
	virtual void enter(Heroine& heroine) {
		heroine.setGraphics(IMAGE_DUCK);
		printf("current image is: DUCK");
	}
private:
	int chargeTime_; //�������ĳ���ʱ�� //����������ٷ�������Heroine�����ǳ���
};

#endif // !_DUCKINGSTATE_H_
