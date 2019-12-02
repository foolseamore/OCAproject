#include "TitleScene.h"
#include "GameManager.h"


TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	title_img = GameManager::Instance().GetTitle();
	earth_img = GameManager::Instance().GetTitleEarth();
	bg_img = GameManager::Instance().GetBg();
	start_img = GameManager::Instance().GetStart();
	exit_img = GameManager::Instance().GetExit();
	select_img = GameManager::Instance().GetEarthHp();
	select.pos.x = 310;
	select.pos.y = 500;
	select.cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		enemy[i].state = BORN;
		enemy[i].texture = GameManager::Instance().GetEnemy(1, i/2);
		enemy[i].SetX(Random(100,750));
        enemy[i].SetY(-100);
		enemy[i].speedy = 2;
		enemy[i].r_cnt = 0;
	}
	
}

void TitleScene::Update()
{
	select.cnt++;
	Print << U"TitleScene";
	bg_img.draw();
	earth_img.drawAt(WINDOW_W / 2, 300);
	for (int i = 0; i < 10; i++)
	{
		enemy[i].DrawAnime(4, 10, 1, ENEMY_SIZE, ENEMY_SIZE);

		if (enemy[i].state == BORN)
		{
			enemy[i].SetY(enemy[i].GetY() + enemy[i].speedy);

			if (enemy[i].GetY() >= 50)
			{
				enemy[i].speedx = rand() % 12 - 6;
				enemy[i].speedy = rand() % 5 + 5;
				enemy[i].state = LIVE;
			}
		}
		if (enemy[i].state == LIVE)
		{
			enemy[i].SetX(enemy[i].GetX() + enemy[i].speedx);
			enemy[i].SetY(enemy[i].GetY() + enemy[i].speedy);

			if (enemy[i].GetY() < +ENEMY_SIZE / 2 || enemy[i].GetY() > WINDOW_H - ENEMY_SIZE / 2)
			{
				enemy[i].speedy = -enemy[i].speedy;
				enemy[i].r_cnt += 1;
			}
			if (enemy[i].GetX() < +ENEMY_SIZE / 2 || enemy[i].GetX() > WINDOW_W - ENEMY_SIZE / 2)
			{
				enemy[i].speedx = -enemy[i].speedx;
				enemy[i].r_cnt += 1;
			}
			if (enemy[i].r_cnt == 5)
			{
				
				enemy[i].SetX(Random(100, 750));
				enemy[i].SetY(-100);
				enemy[i].speedy = 2;
				enemy[i].r_cnt = 0;
				enemy[i].state = BORN;
			}
		}
	}	
	
	title_img.drawAt(WINDOW_W / 2, 300,HSV(60,0.7,1));
	start_img.drawAt(WINDOW_W / 2, 500);
	exit_img.drawAt(WINDOW_W / 2, 600);
	select_img((select.cnt  % 73) * 64,0,64,64).scaled(0.6).drawAt(select.pos.x, select.pos.y);
	

	if (KeyDown.down())
	{
		select.pos.y = 600;
	}
	else if (KeyUp.down())
	{
		select.pos.y = 500;
	}
	if (KeyEnter.down())
	{
		if (select.pos.y == 500)
		{
			GameManager::Instance().gameState = Play;
		}
		else if (select.pos.y == 600)
		{
			System::Exit();
		}
	}
}
void TitleScene::Exit()
{

}