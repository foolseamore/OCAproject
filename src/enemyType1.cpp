#include "enemyType1.h"
#include "GameManager.h"


enemyType1::enemyType1()
{
}


enemyType1::~enemyType1()
{
}

void enemyType1::Init()
{
	state = BORN;
	IsReflect = false;
	texture = GameManager::Instance().GetEnemy(1,0);
	SetX(Random(100,500));
	SetY(-100);
	img_c = 0;
	speedx = 0;
	speedy = 2;
	/*speedx = rand() % 10 - 5;
	speedy = rand() % 5 + 5;*/

}
void enemyType1::Update()
{
	if (state == BORN)
	{
		DrawAnime(2, 10, 1, 48, 48);
		y += speedy;
		if (GetY() >= 100)
		{
			SetY(GetY());
			speedx = rand() % 10 - 5;
			speedy = rand() % 5 + 5;
			state = LIVE;
		}
	}
	if (state == LIVE||state==REFLECT)
	{
		DrawRect(48, 48);
		DrawAnime(2, 10, 1, 48, 48);
		//”½ŽË
		CheckReflect(48);
		x += speedx;
		y += speedy;
	}
	}
	
void enemyType1::Exit()
{

}


void enemyType1::CheckReflect(int size)
{
	if (GetX() <= 0 + size / 2 || GetX() >= GAME_WINDOW_W - 2 / size) speedx = -speedx;
	if (GetY() <= 0 + size / 2)speedy = -speedy;
	if (GetY() >= 650)
	{
		IsReflect = false;
		state = DEAD;
	}
}