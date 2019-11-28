#include "Player.h"
#include "GameManager.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::Init()
{
	texture = GameManager::Instance().GetPlayer1();
	SetX(100);
	SetY(GAME_WINDOW_H);
	img_c = 0;
	state = LIVE;
	
	
}

void Player::DrawRectP(int sizex, int sizey)
{
	rect = RectF(Arg::center = Vec2(GetX(), GetY() - 56), sizex, sizey);
	//rect.draw(Palette::Green);
}

void Player::Key_Op()
{
	if (KeyA.pressed() && state==LIVE)
	{
		isCombine = false;
		SetX(GetX() - PLAYER_SPEED);
		
	}
	else if (KeyS.pressed() && isCombine == false)
	{
		SetX(GetX() + PLAYER_SPEED);
	}
}
void Player::Update()
{
	
	
	DrawAnime(5, 8, 1, PLAYER_SIZE_X, PLAYER_SIZE_Y);
	
	DrawRectP(100, 10);

	Key_Op();

	RangeCheck();

}

void Player::Exit()
{

}
