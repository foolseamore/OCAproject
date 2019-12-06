#include "Boss.h"
#include "GameManager.h"



Boss::Boss()
{
	explode = new Explosion;
}


Boss::~Boss()
{
	delete explode;
}

void Boss::Init()
{
	explode->Init(4);
	explode->SetTag(T_EXPLODE);
	SetTag(T_Boss);
	wave = GameManager::Instance().GetWave();
	state = BORN;
	born_pos = ENEMY_BORNPOS;
	texture = GameManager::Instance().GetBoss(wave-2);
	SetX(GAME_WINDOW_W / 2);
	SetY(100 - born_pos);
	speedx = 0;
	speedy = 2;
	bullet_cnt = 0;
	boss_attack = wave + 4;
	HP = 10*(wave);
	cool_time = 120 - wave * 5;
}
void Boss::Update()
{
	if (state == BORN)
	{
		if(wave<6) DrawAnime(4, 10, 1, BOSS_SIZE_X, BOSS_SIZE_Y);
		else DrawAnime(6, 10, 1, 256, 236);
		born_pos -= speedy;
		SetY(GetY() + speedy);
		if (born_pos == 0)
		{
			SetY(GetY());
			speedx = 5;
			speedy = 0;
			state = LIVE;
		}
	}
	if (state == LIVE)
	{
		bullet_cnt++;
		if(wave<6)DrawAnime(4, 10, 1, BOSS_SIZE_X, BOSS_SIZE_Y);
		else DrawAnime(6, 10, 1, 256, 236);
		DrawRect(BOSS_SIZE_X, BOSS_SIZE_Y);
		SetX(GetX() + speedx);
		
		if (x - BOSS_SIZE_X / 2 < 0 || x + BOSS_SIZE_X / 2 > GAME_WINDOW_W)
		{
			speedx *= -1;
		}

		if (bullet_cnt%cool_time == 0)
		{
			int  now_kind= Random(1, 4);

			for (int j = 0; j < boss_attack; j++)
			{
				
				for (int i = 0; i < BOSS_BULLET_MAX; i++)
				{

					if (bullet[i].flag == false)
					{
					
						deg = 30 + j*120 / (boss_attack -1);
						bullet[i].Init(GetX(), GetY(), BOSS_BULLET_SPEED*cosf(TO_RAD(deg)), BOSS_BULLET_SPEED*sinf(TO_RAD(deg)));
						bullet[i].flag = true;
						bullet[i].bullet_kind = now_kind;
						break;
					}
				}
			}
		}

		for (int i = 0; i < BOSS_BULLET_MAX; i++)
		{
			bullet[i].Update(bullet[i].bullet_kind);
		}

		if (HP == 0)
		{
			state = EXPLODE;
		}
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
void Boss::Exit()
{

}