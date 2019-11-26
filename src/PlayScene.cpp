#include "PlayScene.h"
#include "UI.h"



enemyType1 *e1;
enemyType2 *e2;
enemyType3 *e3;



PlayScene::PlayScene()
{
}


PlayScene::~PlayScene()
{

}

void PlayScene::Init()
{
	//ULT
	ultUI = new ULT;
	ultUI->Init();
	//HP
	hpUI = new HpUI;
	hpUI->Init();
	//score
	ScoreUI = new Score;
	ScoreUI->Init();
	

	p1 = new Player;
	p1->Init();
	p2 = new Player2;
	p2->Init();

	g_now_wave = GameManager::Instance().GetWave();


	type1_size = Random(g_now_wave, g_now_wave + 1);
	type2_size = Random(g_now_wave, g_now_wave + 1);
	type3_size = Random(g_now_wave, g_now_wave + 1);

	e1 = new enemyType1[type1_size];
	e2 = new enemyType2[type2_size];
	e3 = new enemyType3[type3_size];

	
	for (int i = 0; i < type1_size; i++)
	{
		e1[i].Init();
	}
	for (int i = 0; i < type2_size; i++)
	{
		e2[i].Init();
	}
	for (int i = 0; i < type3_size; i++)
	{
		e3[i].Init();
	}

}

void PlayScene::Update()
{
	Print << U"PlayScene";

	p1->Update();
	p2->Update();

	for (int i = 0; i < type1_size; i++)
	{
		e1[i].Update(); //更新
		ReBornEnemy(&e1[i]);  //再生
	}
	for (int i = 0; i < type2_size; i++)
	{
		e2[i].Update();//更新
		ReBornEnemy(&e2[i]);//再生
	}
	for (int i = 0; i < type3_size; i++)
	{
		e3[i].Update();//更新
		ReBornEnemy(&e3[i]);//再生
	}

	//板が繋がってるかどうか
	if (p1->GetX() >= p2->GetX() - 100)
	{
		p1->x = p2->x - 100;
		p1->isCombine = true;
		p2->isCombine = true;
		
	}
	else
	{
		p1->isCombine = false;
		p2->isCombine = false;
	}
	
	
	for (int i = 0; i < type1_size; i++)
	{
		//反射処理
		CaculateAngleE(&e1[i], p1);
		CaculateAngleE(&e1[i], p2);
		//HP減る判定
		CheckHpE(&e1[i]);

		for (int hitenemy = 0; hitenemy < type2_size; hitenemy++)
		{
			//当たり判定
			HitEnemyE(&e1[i], &e2[hitenemy]);
	
		}
		for (int hitenemy = 0; hitenemy < type3_size; hitenemy++)
		{
			//当たり判定
			HitEnemyE(&e1[i], &e3[hitenemy]);
		}
	}


	for (int i = 0; i < BULLET_MAX; i++)
	{
		for (int j = 0; j < type2_size; j++)
		{
			//反射処理
			CaculateAngleB(&e2[j].bullet[i], p1);
			CaculateAngleB(&e2[j].bullet[i], p2);
			//HP減る判定
			CheckHpB(&e2[j].bullet[i]);

			for (int hitenemy = 0; hitenemy < type2_size; hitenemy++)
			{
				//当たり判定
				HitEnemyB(&e2[j].bullet[i], &e2[hitenemy]);
			}
			for (int hitenemy = 0; hitenemy < type3_size; hitenemy++)
			{
				
				HitEnemyB(&e2[j].bullet[i], &e3[hitenemy]);
			}
		
		}
		for (int j = 0; j < type3_size; j++)
		{
			//反射処理
			CaculateAngleB(&e3[j].bullet[i], p1);
			CaculateAngleB(&e3[j].bullet[i], p2);
			//HP減る判定
			CheckHpB(&e3[j].bullet[i]);

			for (int hitenemy = 0; hitenemy < type2_size; hitenemy++)
			{
				HitEnemyB(&e3[j].bullet[i], &e2[hitenemy]);  //当たり判定
			}
			for (int hitenemy = 0; hitenemy < type3_size; hitenemy++)
			{
				HitEnemyB(&e3[j].bullet[i], &e3[hitenemy]);  //当たり判定
			}
		}
	}


	ultUI->Update();
	hpUI->Update();
	ScoreUI->Update();



	//g_new_wave = GameManager::Instance().GetWave();
	//if (g_now_wave != g_new_wave)
	//{
	//	delete[] e1;
	//	e1 = nullptr;
	//	e1 = new enemyType1[type1_size];
	//}

	WaveCheck(type1_size, e1);
	/*WaveCheck(type2_size, e2);
	WaveCheck(type3_size, e3);*/

}
void PlayScene::Exit()
{
	delete p1;
	delete p2;
	delete ultUI;
	delete hpUI;
	delete ScoreUI;
}

void PlayScene::CaculateAngleE(enemyType1*enemy, BaseObject*player)
{
	if (enemy->rect.intersects(player->rect))
	{
		if (enemy->y >= player->rect.y)
		{
			enemy->IsReflect = true;
			float dx = enemy->rect.x - (player->rect.x + 35) + (rand() % 40 - 20);
			float dy = enemy->rect.y - player->rect.y + (rand() % 20 - 10);
			float angle = TO_DEG(atan2f(dy, dx));// +(rand() % 20 - 10);
			//enemy->SetY(514);
			enemy->speedx = 1.5 * ENEMY_SPEED * cosf(TO_RAD(angle));
			enemy->speedy = 1.5 * ENEMY_SPEED * sinf(TO_RAD(angle));
			if (enemy->speedy < -0)
			{
				ultUI->SetEnergy(ultUI->GetEnergy() + 1);
			}
		}
		
	}
}
void PlayScene::CaculateAngleB(BaseBullet *bullet, BaseObject*enemy)
{
	if (bullet->rect.intersects(enemy->rect))
	{
		if (bullet->pos.y >= enemy->rect.y)
		{
			bullet->IsReflect = true;
			float dx = bullet->pos.x - (enemy->rect.x + 40) + (rand() % 40 - 20);
			float dy = bullet->pos.y - (enemy->rect.y + 58) + (rand() % 20 - 10);
			float angle = TO_DEG(atan2f(dy, dx)) + (rand() % 20 - 10);
			bullet->speedx = 1.5 * ENEMY_SPEED * cosf(TO_RAD(angle));
			bullet->speedy = 1.5 * ENEMY_SPEED * sinf(TO_RAD(angle));
			ultUI->SetEnergy(ultUI->GetEnergy() + 1);
		}
	}
}

void PlayScene::HitEnemyE(enemyType1*type1, EnemyBaseObject*typeother)
{


	if (type1->rect.intersects(typeother->rect) && typeother->state == LIVE && type1->IsReflect)
	{
		GameManager::Instance().AddScore();
		type1->state = DEAD;
		typeother->state = DEAD;

	}

}

void PlayScene::HitEnemyB(BaseBullet*bullet, EnemyBaseObject*type)
{

	if (bullet->rect.intersects(type->rect) && bullet->IsReflect&&type->state == LIVE)
	{
		GameManager::Instance().AddScore();
		bullet->flag = false;
		type->state = DEAD;

	}

}
void PlayScene::CheckHpB(BaseBullet *bullet)
{
	if (bullet->pos.y >= 650&& bullet->flag)
	{
     	hpUI->damage += 1;
		GameManager::Instance().DecreseHP(1);
		bullet->flag = false;
		bullet->IsReflect = false;
	}
}
void PlayScene::CheckHpE(EnemyBaseObject *enemy)
{
	if (enemy->y >= 650 && enemy->state == LIVE)
	{
		hpUI->damage += 1;
		GameManager::Instance().DecreseHP(1);
		enemy->state = DEAD;
	}
}

void PlayScene::ReBornEnemy(EnemyBaseObject *enemy)
{	
		if (enemy->state == DEAD)
		{
			enemy->Init();
		}

}

void PlayScene::WaveCheck(int type_size, EnemyBaseObject *enemy)
{
	g_new_wave = GameManager::Instance().GetWave();

	if (g_now_wave != g_new_wave)
	{
		delete[] enemy;
		enemy = nullptr;

		g_now_wave = g_new_wave;

		type_size = g_now_wave;

		
		enemy = new EnemyBaseObject[type_size];

	}
}