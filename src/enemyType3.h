#pragma once
#include "EnemyBaseObject.h"
#include "BaseBullet.h"
class enemyType3 :
	public EnemyBaseObject
{
	//BaseBullet bullet[10];
	int bullet_cnt;

public:
	enemyType3();
	~enemyType3();

	BaseBullet bullet[BULLET_MAX];
	int bullet_kind;

	void Init() override;
	void Update() override;
	void Exit() override;
};

