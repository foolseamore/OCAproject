#include "BaseBullet.h"
#include "GameManager.h"



BaseBullet::BaseBullet()
{
}


BaseBullet::~BaseBullet()
{
}

void BaseBullet::Init(float getx, float gety, float movx, float movy)
{
	texture = GameManager::Instance().GetBullet();
	pos.x = getx;
	pos.y = gety;
	speedx = movx;
	speedy = movy;
	IsReflect = false;

}
void BaseBullet::Update(int kind)
{
	CheckReflect(14);
	
	BulletRender(kind);
	
}
void BaseBullet::Exit()
{

}


void BaseBullet::DrawRect(int size)
{
	rect = RectF(Arg::center = Vec2(pos.x, pos.y), size, size);
	//rect.draw(Palette::White);
}

void BaseBullet::BulletRender(int kind )
{
	if (flag == true)
	{
		DrawRect(14);

		switch (kind)
		{
		case 1:texture(126, 9, 14, 14).drawAt(pos.x, pos.y); break;
		case 2:texture(126, 29, 14, 14).drawAt(pos.x, pos.y); break;
		case 3:texture(126, 48, 14, 14).drawAt(pos.x, pos.y); break;
		case 4:texture(126, 67, 14, 14).drawAt(pos.x, pos.y); break;
		default:break;
		}

		pos.x += speedx;
		pos.y += speedy;
		

	}
	
}
void BaseBullet::CheckReflect(int size)
{
	if (pos.x <= 0 + size / 2 )
	{
		pos.x = size;
		speedx = -speedx;
		//IsReflect = true;
	}
	if (pos.x >= GAME_WINDOW_W - 2 / size)
	{
		pos.x = GAME_WINDOW_W-size;
		speedx = -speedx;
		//IsReflect = true;
	}
	if (pos.y < 0 - size / 2)
	{	
		flag = false;
		//IsReflect = true;
		
	}
	//if (pos.y >= 650) flag = false;

}