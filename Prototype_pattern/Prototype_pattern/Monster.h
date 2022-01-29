#pragma once
#ifndef _MONSTER_H_
#define _MONSTER_H_

// interface
// �������������һ������������Ϊ���麯�������������ǳ����ࡣ
class Monster
{
public:
	virtual ~Monster()
	{
	}
	virtual Monster* clone() = 0; //Pure virtual function
	virtual void print() = 0;
};

#endif // !_MONSTER_H_
