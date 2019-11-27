#pragma once
#include "BaseScene.h"
#include "Player.h"
#include"Player2.h"
#include"UI.h"
#include "GameManager.h"
#include "enemyType1.h"
#include"enemyType2.h"
#include"enemyType3.h"
#include "Boss.h"

class PlayScene :
	public BaseScene
{
	enum STAGE
	{
		BOSS=100,
		ENEMY,
	};
	STAGE stage;

	int type1_size;
	int type2_size;
	int type3_size;
	int Quanity;

	bool AllKilled_1;
	bool AllKilled_2;
	bool AllKilled_3;

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

	//ìGÇÃíµÇÀï‘Ç∑
	void CaculateAngleE(enemyType1*b1, BaseObject*b2);
	//ã ÇÃíµÇÀï‘Ç∑
	void CaculateAngleB(BaseBullet *b1, BaseObject*b2);
	//ì|Ç∑îªíË
	void HitEnemyE(enemyType1*type1, EnemyBaseObject*typeother);
	void HitEnemyB(BaseBullet*b1, EnemyBaseObject*type);
	//HPå∏ÇÈîªíË
	void CheckHpB(BaseBullet *b1);
	void CheckHpE(EnemyBaseObject *e1);
	//Wave ïœçX
	//void WaveCheck(bool live, EnemyBaseObject *enemy);



};

