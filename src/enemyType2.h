#pragma once
#include "EnemyBaseObject.h"
#include "BaseBullet.h"
class enemyType2 :
	public EnemyBaseObject
{
	

	int bullet_cnt;
	int cool_time;

public:
	enemyType2();
	~enemyType2();

	BaseBullet bullet[BULLET_MAX];


	void Init() override;
	void Update() override;
	void Exit() override;
	

};

