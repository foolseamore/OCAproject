#pragma once
#include "BaseScene.h"
#include "Player.h"
#include"Player2.h"
#include"UI.h"
#include "GameManager.h"
#include "enemyType1.h"
#include"enemyType2.h"
#include"enemyType3.h"

class PlayScene :
	public BaseScene
{
	int type1_size;
	int type2_size;
	int type3_size;
	bool AllKilled;

	int score;
	int g_now_wave;
	int g_new_wave;


public:
	PlayScene();
	~PlayScene();

	ULT *ultUI;
	HpUI *hpUI;
	Score *ScoreUI;
	Player *p1;
	Player2 *p2;
	

	void Init() override;
	void Update() override;
	void Exit();

private:

	//GÌµËÔ·
	void CaculateAngleE(enemyType1*b1, BaseObject*b2);
	//ÊÌµËÔ·
	void CaculateAngleB(BaseBullet *b1, BaseObject*b2);
	//|·»è
	void HitEnemyE(enemyType1*type1, EnemyBaseObject*typeother);
	void HitEnemyB(BaseBullet*b1, EnemyBaseObject*type);
	//HP¸é»è
	void CheckHpB(BaseBullet *b1);
	void CheckHpE(EnemyBaseObject *e1);
	//GÄ¶
	void ReBornEnemy(EnemyBaseObject*enemy);
	//Wave ÏX
	void WaveCheck( int type_size, EnemyBaseObject *enemy);



};

