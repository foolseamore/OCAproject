#pragma once
#include "EnemyBaseObject.h"
#include "BaseBullet.h"
class Boss :
	public EnemyBaseObject
{
	int bullet_cnt;
	int HP;
	int cool_time;
	int boss_attack;



public:
	Boss();
	~Boss();

	BaseBullet bullet[BOSS_BULLET_MAX];
	float deg;

	void Init() override;
	void Update() override;
	void Exit() override;
	
	void HpDecrease(int a) { HP -= a; }
	int GetHP() { return HP; }

};

