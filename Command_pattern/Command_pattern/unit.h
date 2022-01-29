#pragma once
#ifndef _UNIT_H_
#define _UNIT_H_

class Unit
{
	int x_;
	int y_;
public:
	Unit(): x_(0), y_(0) {}
	void moveTo(int x, int y) {
		x_ = x;
		y_ = y;
	}
	int x() { return x_; }
	int y() { return y_; }
};

Unit* unitInstance = new Unit(); //不太好

Unit* getSelectedUnit() {
	return unitInstance;
}

#endif // !_UNIT_H_
