#pragma once
#include "EnemyBaseObject.h"
#include "BaseBullet.h"
class enemyType2 :
	public EnemyBaseObject
{
	/*Texture bullet;
	Bullet e_bullet[10];*/

	int bullet_cnt;

public:
	enemyType2();
	~enemyType2();

	BaseBullet bullet[BULLET_MAX];
	int bullet_kind;

	//void BulletUpdate(int kind,Bullet *b1);



	void Init() override;
	void Update() override;
	void Exit() override;
	

};

