#pragma once
#ifndef _INPUT_H_
#define _INPUT_H_

// 我自己瞎写的
class Input {
private:
	char _button;
public:
	Input(char ch): _button(ch){}
	bool operator==(const Input& tmp) {
		return _button == tmp._button;
	}
};

Input RELEASE_DOWN = Input('z');
Input PRESS_DOWN = Input('s');
Input PRESS_B = Input('b');

#endif // !_HEROINESTATE_H_