#include "Player2.h"
#include "GameManager.h"



Player2::Player2()
{
}


Player2::~Player2()
{
}

void Player2::Init()
{
	texture = GameManager::Instance().GetPlayer2();
	SetX(500);
	SetY(600);
	img_c = 0;


}
void Player2::DrawRectP(int sizex, int sizey)
{
	rect = RectF(Arg::center = Vec2(GetX(), GetY() - 58), sizex, sizey);
	//rect.draw(Palette::Green);
}

void Player2::Key_Op()
{
	if (KeyK.pressed() && isCombine == false)
	{
		x -= PLAYER_SPEED;
	}
	else if (KeyL.pressed())
	{
		isCombine = false;
		x += PLAYER_SPEED;	
	}

	
}

void Player2::Update()
{
	DrawRectP(100, 8);
	DrawAnime(5, 8, 1, 100, 128);
	Key_Op();
	
	RangeCheck();
	

}

void Player2::Exit()
{

}