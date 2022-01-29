#pragma once
#ifndef _HEROINE_H_
#define _HEROINE_H_

#include "HeroineState.h"

// 暂时用int表示主角的图像，瞎写的
constexpr int IMAGE_STAND = 0;
constexpr int IMAGE_DUCK = 1;

// interface
class Heroine {
public:
	// 默认构造函数：初始化状态为站立
	Heroine(){
		//state_ = new StandingState();
		//state_->enter(*this);
		state_ = nullptr;
	}
	// 直接调用当前状态的对应方法
	virtual void handleInput(Heroine& heroine, Input input) {
		//state_->handleInput(heroine, input);
		// 做法二：实例化状态
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
	
	void superBomb(){} //蓄力跳

	//other methods...
	void setGraphics(int image){}
private:
	HeroineState* state_; //指向当前状态的指针
};

#endif // !_HEROINE_H_
