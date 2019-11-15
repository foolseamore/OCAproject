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
	state = LIVE;
	texture = GameManager::Instance().GetEnemy(3,0);
	SetX(150);
	SetY(100);
	img_c = 0;
	bullet_cnt = 0;
}
void enemyType3::Update()
{
	if (state == LIVE)
	{
		DrawRect(48, 48);
		DrawAnime(4, 10, 1, 48, 48);
		bullet_cnt++;
		if (bullet_cnt % 60 == 0)
		{
			for (int i = 0; i < BULLET_MAX; i++)
			{
				if (bullet[i].flag == false)
				{
					bullet[i].Init(GetX(), GetY(), rand() % 10 - 5, rand() % 5 + 5);
					bullet[i].flag = true;
					break;
				}
			}
		}
	}
	for (int i = 0; i < BULLET_MAX; i++)
	{
		bullet[i].Update(4);

	}
	
}
void enemyType3::Exit()
{

}