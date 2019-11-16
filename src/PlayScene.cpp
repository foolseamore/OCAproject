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
	type3_size = Random(3, 5);//lk

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
	//e1->Init();
	//e2->Init();
	//e3->Init();
	

}

void PlayScene::Update()
{
	//UI_->Update();
	

	Print << U"PlayScene";

	p1->Update();
	p2->Update();
	/*e1->Update();	
	e2->Update();
	e3->Update();*/
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
	}
	//CaculateAngleE(e1, p1);
	//CaculateAngleE(e1, p2);

	for (int i = 0; i < BULLET_MAX; i++)
	{
		/*for (int j = 0; i < type2_size; j++)
		{
			CaculateAngleB(&e2[j].bullet[i], p1);
			CaculateAngleB(&e2[j].bullet[i], p2);
		}*/
		CaculateAngleB(&e2->bullet[i], p1);
		CaculateAngleB(&e2->bullet[i], p2);
		CaculateAngleB(&e3->bullet[i], p1);
		CaculateAngleB(&e3->bullet[i], p2);


		HitEnemyB(&e2->bullet[i], e2);
		HitEnemyB(&e3->bullet[i], e2);
		HitEnemyB(&e2->bullet[i], e3);
		HitEnemyB(&e3->bullet[i], e3);
	}

	//“–‚½‚è”»’è
	HitEnemyE(e1, e2);
	HitEnemyE(e1, e3);

	//HPŒ¸‚é”»’è
	CheckHpE(e1);
	for (int i = 0; i < BULLET_MAX; i++)
	{
		CheckHpB(&e2->bullet[i]);
		CheckHpB(&e3->bullet[i]);
	}

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

void PlayScene::CaculateAngleE(enemyType1*b1, BaseObject*b2)
{
	if (b1->rect.intersects(b2->rect))
	{

		if (b1->y >= b2->rect.y)

		{
			b1->IsReflect = true;
			float dx = b1->rect.x - (b2->rect.x + 35) + (rand() % 40 - 20);
			float dy = b1->rect.y - b2->rect.y + (rand() % 20 - 10);
			float angle = TO_DEG(atan2f(dy, dx));// +(rand() % 20 - 10);
			b1->speedx = 2 * ENEMY_SPEED * cosf(TO_RAD(angle));
			b1->speedy = 2 * ENEMY_SPEED * sinf(TO_RAD(angle));
			ultUI->energy += 1;
		}
	}
	
}
void PlayScene::CaculateAngleB(BaseBullet*b1, BaseObject*b2)
{
	if (b1->rect.intersects(b2->rect))

	{
		if (b1->pos.y >= b2->rect.y)
		{
			b1->IsReflect = true;
			float dx = b1->pos.x - (b2->rect.x + 40) + (rand() % 40 - 20);
			float dy = b1->pos.y - (b2->rect.y + 58) + (rand() % 20 - 10);
			float angle = TO_DEG(atan2f(dy, dx)) + (rand() % 20 - 10);
			b1->speedx = 2 * ENEMY_SPEED * cosf(TO_RAD(angle));
			b1->speedy = 2 * ENEMY_SPEED * sinf(TO_RAD(angle));
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

void PlayScene::HitEnemyB(BaseBullet*b1, EnemyBaseObject*type)
{
	if (b1->IsReflect&&type->state==LIVE)
	{
		if (b1->rect.intersects(type->rect))
		{
			b1->flag = false;
			type->state = DEAD;
			
		}
	}
}
void PlayScene::CheckHpB(BaseBullet *b1)
{
	if (b1->pos.y >= 650&&b1->flag)
	{
		hpUI->damage += 1;
		hpUI->GetDamage = true;
		b1->flag = false;
		b1->IsReflect = false;
	}
}
void PlayScene::CheckHpE(EnemyBaseObject *e1)
{
	if (e1->y >= 650 && e1->state == LIVE)
	{
		hpUI->damage += 1;
		hpUI->GetDamage = true;
	}
}