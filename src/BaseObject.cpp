#include "BaseObject.h"



BaseObject::BaseObject()
{
}


BaseObject::~BaseObject()
{
}

void BaseObject::Init()
{

}

void BaseObject::DrawRect(int sizex,int sizey)
{
	rect = RectF(Arg::center = Vec2(GetX(), GetY() ), sizex, sizey);
	//rect.draw(Palette::Green);
}
void BaseObject::DrawCircle(int sizex)
{
	circle = Circle(Arg::center = Vec2(GetX(), GetY()), sizex);
	
}

void BaseObject::DrawAnime(int max_frame, int frame, int speed, int sizex, int sizey)
{
	int scale = 1;

	if (tag == T_EXPLODE)
	{
		scale = 2;
	}

	img_c = img_c + speed;

	texture((img_c / frame) % max_frame*sizex, 0, sizex, sizey).scaled(scale).drawAt(GetX(), GetY());

}

void BaseObject::RangeCheck()
{
	if (x <= 50) x = 50;
	if (x > GAME_WINDOW_W - 50)x = GAME_WINDOW_W - 50;
	
}


void BaseObject::Update()
{

}
void BaseObject::Exit()
{

}