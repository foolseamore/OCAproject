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
	SetY(600);
	img_c = 0;
	
	
}

void Player::DrawRectP(int sizex, int sizey)
{
	rect = RectF(Arg::center = Vec2(GetX(), GetY() - 60), sizex, sizey);
	rect.draw(Palette::Green);
}

void Player::Key_Op()
{
	if (KeyA.pressed())
	{
		isCombine = false;
		x -= PLAYER_SPEED;
		
	}
	else if (KeyS.pressed() && isCombine == false)
	{
		x += PLAYER_SPEED;
	}
}
void Player::Update()
{
	DrawRectP(100, 3);
	
	DrawAnime(5, 8, 1, 100, 128);

	
	Key_Op();
	RangeCheck();
	
	


}

void Player::Exit()
{

}
