#pragma once
#ifndef _HEROINESTATE_H_
#define _HEROINESTATE_H_

#include "Heroine.h"
#include "Input.h"
#include "DuckingState.h"
#include "StandingState.h"

// interface ״̬�ӿ� 
// ���ǳ�����?
class HeroineState {
public:
	// 7.5 ״̬����Ӧ�÷���������? ��2��������
	// 
	// ����һ����̬״̬��
	// ��һ��״̬����û���κ����ݳ�Ա����Ψһ�����ݳ�Ա�������ָ�룬�����þ�ֹ״̬
	// ����Ȼ�г�Ա����������chargeTime_��������ֻ��һ�����ǣ���Ȼ�����þ�ֹ״̬
	//static DuckingState ducking;
	//static StandingState standing;
	//static JumpingState jumping;
	//static DivingState diving;
	// ״̬�ı�ʱ��ֻҪ������״̬֮���л��Ϳ�����
	//
	// ��������ʵ����״̬
	// �г�Ա����������chargeTime_�����ж������
	// ��ʱ��ΪҪ������״̬/ɾ����״̬��Ҫ�ر�ע���ڴ���� 
public:
	virtual ~HeroineState() {}
	//virtual void handleInput(Heroine& heroine, Input input) {}
	virtual HeroineState* handleInput(Heroine& heroine, Input input) {}
	virtual void update(Heroine& heroine){}
	// entry �������״̬ʱִ�У�����������һ��״̬��ʲô��
	virtual void enter(Heroine& heroine) {}
};

#endif // !_HEROINESTATE_H_
