#include "enemyType2.h"
#include "GameManager.h"


enemyType2::enemyType2()
{
}


enemyType2::~enemyType2()
{
}

void enemyType2::Init()
{
	state = BORN;
	born_pos = ENEMY_BORNPOS;
	texture = GameManager::Instance().GetEnemy(2,0);
	SetX(Random(0, 11)*ENEMY_SIZE + 36);
	SetY((Random(0, 4)*ENEMY_SIZE+24)-born_pos);
	img_c = 0;
	bullet_cnt = 0;
	speedy = Random(2,5);

}

void enemyType2::Update()
{
	if (state == BORN)
	{
		DrawAnime(2, 10, 1, ENEMY_SIZE, ENEMY_SIZE);
		born_pos -= speedy;
		SetY(GetY() + speedy);
		if (born_pos==0)
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

		
		if (bullet_cnt % 60 == 0)
		{
			int attack = Random(0,1);
			if (attack == 0)
			{
				for (int i = 0; i < BULLET_MAX; i++)
				{
					if (bullet[i].flag == false)
					{
						bullet[i].Init(GetX(), GetY(), 0, Random(3, 5));
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
void enemyType2::Exit()
{
	
}
