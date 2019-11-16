#include "PlayScene.h"
#include "UI.h"

struct PlayerData
{
	Point pos;
	RectF rect;
};

PlayerData player[2];


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
	/*UI_ = new UI;
	UI_->Init();*/
	ultUI = new ULT;
	ultUI->Init();
	hpUI = new HpUI;
	hpUI->Init();
	

	p1 = new Player;
	p1->Init();
	p2 = new Player2;
	p2->Init();

	type1_size = Random(3, 5);
	type2_size = Random(3, 5);
	type3_size = Random(3, 5);

	e1 = new enemyType1[type1_size];
	e2 = new enemyType2[type2_size];
	e3 = new enemyType3[type3_size];
	/*e1 = new enemyType1;
	e2 = new enemyType2;
	e3 = new enemyType3;*/

	
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
	/*e1->Init();
	e2->Init();
	e3->Init();*/
	

}

void PlayScene::Update()
{
	//UI_->Update();
	

	Print << U"PlayScene";

	p1->Update();
	p2->Update();
	//e1->Update();	
	//e2->Update();
	//e3->Update();
	for (int i = 0; i < type1_size; i++)
	{
		e1[i].Update();
	}
	for (int i = 0; i < type2_size; i++)
	{
		e2[i].Update();
	}
	for (int i = 0; i < type3_size; i++)
	{
		e3[i].Update();
	}

	//”Â‚ªŒq‚ª‚Á‚Ä‚é‚©‚Ç‚¤‚©
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
	
	//”½Ëˆ—
	for (int i = 0; i < type1_size; i++)
	{
		CaculateAngleE(&e1[i], p1);
		CaculateAngleE(&e1[i], p2);
		CheckHpE(&e1[i]);

		for (int hitenemy = 0; hitenemy < type2_size; hitenemy++)
		{
			HitEnemyE(&e1[i], &e2[hitenemy]);
	
		}
		for (int hitenemy = 0; hitenemy < type3_size; hitenemy++)
		{
			HitEnemyE(&e1[i], &e3[hitenemy]);
		}
	}


	//CaculateAngleE(e1, p1);
	//CaculateAngleE(e1, p2);



	for (int i = 0; i < BULLET_MAX; i++)
	{
		for (int j = 0; j < type2_size; j++)
		{
			CaculateAngleB(&e2[j].bullet[i], p1);
			CaculateAngleB(&e2[j].bullet[i], p2);

			for (int hitenemy = 0; hitenemy < type2_size; hitenemy++)
			{
				HitEnemyB(&e2[j].bullet[i], &e2[hitenemy]);
			}
			for (int hitenemy = 0; hitenemy < type3_size; hitenemy++)
			{
				HitEnemyB(&e2[j].bullet[i], &e3[hitenemy]);
			}
		
		}
		for (int j = 0; j < type3_size; j++)
		{
			CaculateAngleB(&e3[j].bullet[i], p1);
			CaculateAngleB(&e3[j].bullet[i], p2);

			for (int hitenemy = 0; hitenemy < type2_size; hitenemy++)
			{
				HitEnemyB(&e3[j].bullet[i], &e2[hitenemy]);
			}
			for (int hitenemy = 0; hitenemy < type3_size; hitenemy++)
			{
				HitEnemyB(&e3[j].bullet[i], &e3[hitenemy]);
			}
		}

		/*CaculateAngleB(&e2->bullet[i], p1);
		CaculateAngleB(&e2->bullet[i], p2);
		CaculateAngleB(&e3->bullet[i], p1);
		CaculateAngleB(&e3->bullet[i], p2);

		HitEnemyB(&e2->bullet[i], e2);
		HitEnemyB(&e3->bullet[i], e2);
		HitEnemyB(&e2->bullet[i], e3);
		HitEnemyB(&e3->bullet[i], e3);*/


	}


	////“–‚½‚è”»’è
	//HitEnemyE(e1, e2);
	//HitEnemyE(e1, e3);

	////HPŒ¸‚é”»’è
	//CheckHpE(e1);
	//for (int i = 0; i < BULLET_MAX; i++)
	//{
	//	CheckHpB(&e2->bullet[i]);
	//	CheckHpB(&e3->bullet[i]);
	//}

	ultUI->Update();
	hpUI->Update();

}
void PlayScene::Exit()
{
	delete p1;
	delete p2;
	delete ultUI;
	delete hpUI;
}

void PlayScene::CaculateAngleE(enemyType1*enemy, BaseObject*player)
{
	if (enemy->rect.intersects(player->rect))
	{
		if (enemy->y+5 >= player->rect.y)
		{
			enemy->IsReflect = true;
			float dx = enemy->rect.x - (player->rect.x + 35) + (rand() % 40 - 20);
			float dy = enemy->rect.y - player->rect.y + (rand() % 20 - 10);
			float angle = TO_DEG(atan2f(dy, dx));// +(rand() % 20 - 10);
			enemy->speedx = 2 * ENEMY_SPEED * cosf(TO_RAD(angle));
			enemy->speedy = 2 * ENEMY_SPEED * sinf(TO_RAD(angle));
			ultUI->energy += 1;
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
			bullet->speedx = 2 * ENEMY_SPEED * cosf(TO_RAD(angle));
			bullet->speedy = 2 * ENEMY_SPEED * sinf(TO_RAD(angle));
			ultUI->energy += 1;
		}
	}
}

void PlayScene::HitEnemyE(enemyType1*type1, EnemyBaseObject*typeother)
{
	if (typeother->state==LIVE&&type1->IsReflect)
	{
		
		if (type1->rect.intersects(typeother->rect))
		{
			type1->state = DEAD;
			typeother->state = DEAD;
		
		}
	}
}

void PlayScene::HitEnemyB(BaseBullet*bullet, EnemyBaseObject*type)
{
	if (bullet->IsReflect&&type->state==LIVE)
	{
		if (bullet->rect.intersects(type->rect))
		{
			bullet->flag = false;
			type->state = DEAD;
			
		}
	}
}
void PlayScene::CheckHpB(BaseBullet *bullet)
{
	if (bullet->pos.y >= 650&& bullet->flag)
	{
		hpUI->damage += 1;
		hpUI->GetDamage = true;
		bullet->flag = false;
		bullet->IsReflect = false;
	}
}
void PlayScene::CheckHpE(EnemyBaseObject *enemy)
{
	if (enemy->y >= 650 && enemy->state == LIVE)
	{
		hpUI->damage += 1;
		hpUI->GetDamage = true;
		enemy->state = DEAD;
	}
}