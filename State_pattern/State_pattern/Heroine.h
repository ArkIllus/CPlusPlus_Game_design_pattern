#pragma once
#ifndef _HEROINE_H_
#define _HEROINE_H_

#include "HeroineState.h"

// ��ʱ��int��ʾ���ǵ�ͼ��Ϲд��
constexpr int IMAGE_STAND = 0;
constexpr int IMAGE_DUCK = 1;

// interface
class Heroine {
public:
	// Ĭ�Ϲ��캯������ʼ��״̬Ϊվ��
	Heroine(){
		//state_ = new StandingState();
		//state_->enter(*this);
		state_ = nullptr;
	}
	// ֱ�ӵ��õ�ǰ״̬�Ķ�Ӧ����
	virtual void handleInput(Heroine& heroine, Input input) {
		//state_->handleInput(heroine, input);
		// ��������ʵ����״̬
		HeroineState* state = state_->handleInput(*this, input);
		if (state != nullptr) {
			delete state_;
			state_ = state;
		}

		// Call the enter action on the new state
		state_->enter(*this);
	}
	virtual void update(Heroine& heroine) {
		state_->update(heroine);
	}
	
	void superBomb(){} //������

	//other methods...
	void setGraphics(int image){}
private:
	HeroineState* state_; //ָ��ǰ״̬��ָ��
};

#endif // !_HEROINE_H_
