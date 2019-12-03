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
	SetTag(T_Enemy);
	wave = GameManager::Instance().GetWave();
	state = BORN;
	born_pos = ENEMY_BORNPOS;
	IsReflect = false;
	texture = GameManager::Instance().GetEnemy(1,Random(0,wave-1));
	//SetX(Random(100,500));
	//SetY(-100);
	img_c = 0;
	SetX(Random(0, ENEMY_COL)*ENEMY_SIZE + 36);
	SetY((Random(0, ENEMY_ROW)*ENEMY_SIZE + 24) - born_pos);
	speedx = 0;
	speedy = 2;
	

}
void enemyType1::Update()
{
	if (state == BORN)
	{
		DrawAnime(4, 10, 1, ENEMY_SIZE, ENEMY_SIZE);
		born_pos -= speedy;
		SetY(GetY() + speedy);
		if (born_pos == 0)
		{
			SetY(GetY());
			speedx = rand() % 12 - 6;
			speedy = rand() % 5 + 5;
			state = LIVE;
		}
	}
	if (state == LIVE||state==REFLECT)
	{
		DrawRect(ENEMY_SIZE, ENEMY_SIZE);
		DrawAnime(4, 10, 1, ENEMY_SIZE, ENEMY_SIZE);
		//”½ŽË
		CheckReflect(ENEMY_SIZE);
		x += speedx;
		y += speedy;
	}
	if (state == EXPLODE)
	{
		static int cnt = 0;
		cnt++;
		explode->Update();
		if (cnt * 5 >= explode->max_frame)
		{
			state = DEAD;
			delete explode;
		}
	}
}
	
void enemyType1::Exit()
{

}


void enemyType1::CheckReflect(int size)
{
	if (GetX() < 0 + size / 2 || GetX() >= GAME_WINDOW_W - 2 / size) speedx = -speedx;
	if (GetY() < 0 + size / 2)speedy = -speedy;
	if (GetY() >= GAME_DEAD_RANGE)
	{
		IsReflect = false;
		state = DEAD;
	}
}