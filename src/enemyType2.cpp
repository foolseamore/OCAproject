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
	texture = GameManager::Instance().GetEnemy(2,0);
	SetX(Random(100,600));
	SetY(-100);
	img_c = 0;
	bullet_cnt = 0;
	speedy = 2;

}

void enemyType2::Update()
{
	if (state == BORN)
	{
		DrawAnime(2, 10, 1, 48, 48);
		y += speedy;
		if (GetY() >= 100)
		{
			SetY(GetY());
			speedy = 0;
			state = LIVE;
		}
	}
	if (state == LIVE)
	{
		bullet_cnt++;
		DrawRect(48, 48);
		DrawAnime(2, 10, 1, 48, 48);

		
		if (bullet_cnt % 60 == 0)
		{
			for (int i = 0; i < BULLET_MAX; i++)
			{
				if (bullet[i].flag == false)
				{
					bullet[i].Init(GetX(), GetY(), 0, 5);
					bullet[i].flag = true;
					break;
					
				}
			}
		}
	}

	for (int i = 0; i < BULLET_MAX; i++)
	{
		bullet[i].Update(1);
	}
}
void enemyType2::Exit()
{
	
}
