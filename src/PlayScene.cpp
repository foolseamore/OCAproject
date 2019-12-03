#include "PlayScene.h"
#include "UI.h"

enemyType1 *e1;
enemyType2 *e2;
enemyType3 *e3;
Boss *boss;

PlayScene::PlayScene()
{
}


PlayScene::~PlayScene()
{

}

void PlayScene::Init()
{
	stage = ENEMY;
	//ULT
	ultUI = new ULT;
	ultUI->Init();
	skill = new Skill;
	skill->Init();
	//HP
	hpUI = new HpUI;
	hpUI->Init();
	//score
	ScoreUI = new Score;
	ScoreUI->Init();
	
	//player
	p1 = new Player;
	p1->Init();
	p2 = new Player2;
	p2->Init();

	//敵の数
	g_now_wave = GameManager::Instance().GetWave();
	Quanity = g_now_wave + 3; 

	//enemy
	e1 = new enemyType1[Quanity];
	e2 = new enemyType2[Quanity];
	e3 = new enemyType3[Quanity];
	for (int i = 0; i < Quanity; i++)
	{
		e1[i].Init();
		e2[i].Init();
		e3[i].Init();
	}

	
}

void PlayScene::Update()
{
	g_new_wave = GameManager::Instance().GetWave();

	Print << U"PlayScene";
	Print << U"link : " << p1->isCombine;

	p1->Update();
	p2->Update();

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

	if (KeySpace.down() && ultUI->GetEnergy() == 30 && p1->isCombine)
	{
		p1->state = SKILL;
		p2->state = SKILL;
	}

	if (p1->state == SKILL && p2->state == SKILL)
	{
		skill->Update(p1->GetX(),p1->GetY());

		if (skill->GetShotCount() > 35)

		{
			for (int i = 0; i < Quanity; i++)
			{
				if (e1[i].state == LIVE)
				{
					GameManager::Instance().AddScore(1);
					e1[i].state = DEAD;

				}
				if (e2[i].state == LIVE)
				{
					GameManager::Instance().AddScore(1);
					e2[i].state = DEAD;
				}
				if (e3[i].state == LIVE)
				{
					GameManager::Instance().AddScore(1);
					e3[i].state = DEAD;
				}
			}
			ultUI->SetEnergy(0);
			delete skill;
			skill = new Skill;
			skill->Init();
			p1->state = LIVE;
			p2->state = LIVE;
		}
	}

	if (stage == ENEMY)
	{
		if (g_now_wave != g_new_wave && AllKilled_2 && AllKilled_3)
		{

			boss = new Boss;
			boss->Init();
			stage = BOSS;
		}

		AllKilled_1 = true;
		AllKilled_2 = true;
		AllKilled_3 = true;

		for (int i = 0; i < Quanity; i++)
		{
			e1[i].Update(); //更新			
			e2[i].Update();//更新
			e3[i].Update();//更新

			//反射処理
			CaculateAngleE(&e1[i], p1);
			CaculateAngleE(&e1[i], p2);
			//HP減る判定
			CheckHpE(&e1[i]);

			for (int hitenemy = 0; hitenemy < Quanity; hitenemy++)
			{
				//当たり判定
				HitEnemyE(&e1[i], &e2[hitenemy]);
				//当たり判定
				HitEnemyE(&e1[i], &e3[hitenemy]);

			}
			for (int j = 0; j < BULLET_MAX; j++)
			{
				//反射処理
				CaculateAngleB(&e2[i].bullet[j], p1);
				CaculateAngleB(&e2[i].bullet[j], p2);
				//HP減る判定
				CheckHpB(&e2[i].bullet[j]);

				//反射処理
				CaculateAngleB(&e3[i].bullet[j], p1);
				CaculateAngleB(&e3[i].bullet[j], p2);
				//HP減る判定
				CheckHpB(&e3[i].bullet[j]);

				for (int hitenemy = 0; hitenemy < Quanity; hitenemy++)
				{
					//当たり判定
					HitEnemyB(&e2[i].bullet[j], &e2[hitenemy]);
					HitEnemyB(&e2[i].bullet[j], &e3[hitenemy]);
					HitEnemyB(&e3[i].bullet[j], &e2[hitenemy]);  
					HitEnemyB(&e3[i].bullet[j], &e3[hitenemy]);  
				}

			}
			//enemy live check
			if (e1[i].state == BORN || e1[i].state == LIVE)
			{
				AllKilled_1 = false;
				//continue;
			}
			
			if (e2[i].state == BORN || e2[i].state == LIVE)
			{
				AllKilled_2 = false;
				//continue;
			}
			if (e3[i].state == BORN || e3[i].state == LIVE)
			{
				AllKilled_3 = false;
				//continue;
			}
			//enemy bullet flag check
			for (int j = 0; j < BULLET_MAX; j++)
			{
				if (e2[i].bullet[j].flag) AllKilled_2 = false;
				if (e3[i].bullet[j].flag) AllKilled_3 = false;
			}
		}

		//もし敵が全滅されたら、改めて作る
		if (g_now_wave == g_new_wave)
		{
			if (AllKilled_1)
			{
				delete[] e1;
				e1 = new enemyType1[Quanity];
				for (int i = 0; i < Quanity; i++)
				{
					e1[i].Init();
				}
			}
			if (AllKilled_2)
			{
				delete[] e2;
				e2 = new enemyType2[Quanity];
				for (int i = 0; i < Quanity; i++)
				{
					e2[i].Init();
				}
			}
			if (AllKilled_3)
			{
				delete[] e3;
				e3 = new enemyType3[Quanity];
				for (int i = 0; i < Quanity; i++)
				{
					e3[i].Init();
				}
			}
		}
	
	}
	//一定数の敵を倒したらボスが出る
	if (stage == BOSS)
	{
		boss->Update();

		if (KeySpace.down())
		{
			boss->state = DEAD;
		}
		if (boss->GetHP() == 0)
		{
			boss->state = DEAD;
		}

		for (int i = 0; i < BOSS_BULLET_MAX; i++)
		{
			CaculateAngleB(&boss->bullet[i], p1);
			CaculateAngleB(&boss->bullet[i], p2);
			CheckHpB(&boss->bullet[i]);
			HitEnemyB(&boss->bullet[i], boss);
		}

		if (boss->state == DEAD)
		{
			delete boss;
			delete[] e1;
			delete[] e2;
			delete[] e3;
			g_now_wave = g_new_wave;
			Quanity = g_now_wave + 3;
			e1 = new enemyType1[Quanity];
			e2 = new enemyType2[Quanity];
			e3 = new enemyType3[Quanity];
			for (int i = 0; i < Quanity; i++)
			{
				e1[i].Init();
				e2[i].Init();
				e3[i].Init();
			}
			stage = ENEMY;
		}
	}
	ultUI->Update();
	hpUI->Update();
	ScoreUI->Update();
}
void PlayScene::Exit()
{
	delete p1;
	delete p2;
	delete ultUI;
	delete hpUI;
	delete ScoreUI;
}

void PlayScene::CaculateAngleE(enemyType1 *enemy, BaseObject *player)
{
	if (enemy->rect.intersects(player->rect) && enemy->state==LIVE)
	{
		if (enemy->y >= player->rect.y)
		{
			enemy->IsReflect = true;
			float dx = enemy->rect.x - (player->rect.x + 35) + (rand() % 40 - 20);
			float dy = enemy->rect.y - player->rect.y + (rand() % 20 - 10);
			float angle = TO_DEG(atan2f(dy, dx));
			enemy->speedx = 1.5 * ENEMY_SPEED * cosf(TO_RAD(angle));
			enemy->speedy = 1.5 * ENEMY_SPEED * sinf(TO_RAD(angle));
			if (enemy->speedy < 0)
			{
				ultUI->SetEnergy(ultUI->GetEnergy() + 1);
			}
		}
	}
}
void PlayScene::CaculateAngleB(BaseBullet *bullet, BaseObject *player)
{
	if (bullet->rect.intersects(player->rect))
	{
		if (bullet->pos.y >= player->rect.y && bullet->flag)
		{
			bullet->IsReflect = true;
			float dx = bullet->pos.x - (player->rect.x + 40) + (rand() % 40 - 20);
			float dy = bullet->pos.y - (player->rect.y + 58) + (rand() % 20 - 10);
			float angle = TO_DEG(atan2f(dy, dx)) + (rand() % 20 - 10);
			bullet->speedx = 1.5 * ENEMY_SPEED * cosf(TO_RAD(angle));
			bullet->speedy = 1.5 * ENEMY_SPEED * sinf(TO_RAD(angle));
			ultUI->SetEnergy(ultUI->GetEnergy() + 1);
		}
	}
}

void PlayScene::HitEnemyE(enemyType1 *type1, EnemyBaseObject *typeother)
{
	if (type1->rect.intersects(typeother->rect) && typeother->state == LIVE && type1->IsReflect)
	{
		GameManager::Instance().AddScore(2);
		type1->state = EXPLODE;
		typeother->state = DEAD;
	}
}

void PlayScene::HitEnemyB(BaseBullet *bullet, EnemyBaseObject *type)
{
	if (bullet->rect.intersects(type->rect) && bullet->IsReflect && type->state == LIVE && bullet->flag)
	{
		if (type->GetTag() == T_Enemy)
		{
			GameManager::Instance().AddScore(1);
			type->state = DEAD;
		}
		if (type->GetTag() == T_Boss)
		{
			boss->HpDecrease(1);
		}
		bullet->flag = false;
		
	}
}
void PlayScene::CheckHpB(BaseBullet *bullet)
{
	if (bullet->pos.y >= 650 &&  bullet->flag)
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
		enemy->state = EXPLODE;
	}
}



