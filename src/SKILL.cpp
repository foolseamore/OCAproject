#include "SKILL.h"
#include "GameManager.h"
#include "Player.h"


Skill::Skill()
{
}


Skill::~Skill()
{
}
void Skill::Init()
{
	texture = GameManager::Instance().GetLight();
	raser_img = GameManager::Instance().GetRaser();
	charge_cnt = 0;
	shot_cnt = 0;
	rad = -0.7f;
}
void Skill::Update(float px, float py)
{
	SetX(px + 50);
	SetY(py - 60);
	charge_cnt++;

	if (charge_cnt < 30) DrawAnime(5, 8, 2, 75, 75);
	else shot_cnt++;

	if (shot_cnt != 0 && shot_cnt < 60)
	{
		//raser_img((shot_cnt / 5) % 14 * 144, shot_cnt / 14 * 600, 144, 600).draw(Arg::bottomRight = Vec2(GetX() + 72, GetY() + 10));
		
		rad += 0.02f;
		raser_img((shot_cnt / 5) % 14 * 144, shot_cnt / 14 * 600, 144, 600).rotatedAt(72, 600,rad).drawAt(GetX(),GetY());
	}
}
void Skill::Exit()
{

}