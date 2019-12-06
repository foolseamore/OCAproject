#include "enemyType2.h"
#include "GameManager.h"


enemyType2::enemyType2()
{
	explode = new Explosion;
}


enemyType2::~enemyType2()
{
	delete explode;
}

void enemyType2::Init()
{
	explode->Init(Random(0, 3));
	
	SetTag(T_Enemy);
	wave = GameManager::Instance().GetWave();
	state = BORN;
	born_pos = ENEMY_BORNPOS;
	texture = GameManager::Instance().GetEnemy(2,Random(0,wave-1));
	SetX(Random(0, ENEMY_COL)*ENEMY_SIZE + 36);
	SetY((Random(0, ENEMY_ROW)*ENEMY_SIZE+24)-born_pos);
	img_c = 0;
	bullet_cnt = 0;
	cool_time = 50;
	speedy = Random(3,6);
}

void enemyType2::Update()
{
	if (state == BORN)
	{
		DrawAnime(2, 10, 1, ENEMY_SIZE, ENEMY_SIZE);
		born_pos -= speedy;
		SetY(GetY() + speedy);
		if (born_pos == 0)
		{
			SetY(GetY());
			speedy = 0;
			state = LIVE;
		}
	}
	if (state == LIVE)
	{
		bullet_cnt++;
		DrawRect(ENEMY_SIZE, ENEMY_SIZE);
		DrawAnime(2, 10, 1, ENEMY_SIZE, ENEMY_SIZE);

		
		if (bullet_cnt % cool_time == 0)
		{
			int attack = Random(0,1);
			if (attack == 0)
			{
				for (int i = 0; i < BULLET_MAX; i++)
				{
					if (bullet[i].flag == false)
					{
						bullet[i].Init(GetX(), GetY(), 0, Random(5, 8));
						bullet[i].flag = true;
						bullet[i].bullet_kind = Random(1, 2);
						break;

					}
				}
			}
		}
	}

	for (int i = 0; i < BULLET_MAX; i++)
	{
		bullet[i].Update(bullet[i].bullet_kind);
	}
	if (state == EXPLODE)
	{
		explode->SetX(GetX());
		explode->SetY(GetY());
		explode->Update();

		if (explode->GetImg_C() / 5 + 1 >= explode->max_frame)
		{
			state = DEAD;
		}
	}
}
void enemyType2::Exit()
{
	
}
