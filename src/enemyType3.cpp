#include "enemyType3.h"
#include "GameManager.h"


enemyType3::enemyType3()
{
}


enemyType3::~enemyType3()
{
	
}

void enemyType3::Init()
{
	state = BORN;
	born_pos = ENEMY_BORNPOS;
	texture = GameManager::Instance().GetEnemy(3,0);
	SetX(Random(0, 11)*ENEMY_SIZE + 36);
	SetY((Random(0, 4)*ENEMY_SIZE + 24) - born_pos);
	img_c = 0;
	bullet_cnt = 0;
	speedy = 2;
	speedy = Random(2, 5);
}
void enemyType3::Update()
{
	if (state == BORN)
	{
		DrawAnime(2, 10, 1, 48, 48);
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
		DrawRect(48, 48);
		DrawAnime(4, 10, 1, 48, 48);
		bullet_cnt++;
		if (bullet_cnt % 60 == 0)
		{
			int attack = Random(0, 1);
			if (attack == 0)
			{
				for (int i = 0; i < BULLET_MAX; i++)
				{
					if (bullet[i].flag == false)
					{
						bullet[i].Init(GetX(), GetY(), rand() % 10 - 5, rand() % 5 + 5);
						bullet[i].flag = true;
						bullet_kind = Random(1, 4);
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < BULLET_MAX; i++)
	{
		bullet[i].Update(bullet_kind);

	}
	
}
void enemyType3::Exit()
{

}