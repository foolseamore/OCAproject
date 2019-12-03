#include "Explosion.h"
#include "GameManager.h"


Explosion::Explosion()
{
	select_effect = Random(0, 3);
	texture = GameManager::Instance().GetExplode(select_effect);
}


Explosion::~Explosion()
{
}

void Explosion::Init()
{
	//max_frame = 0;
}
void Explosion::Update()
{
	switch (select_effect)
	{
	case 0:max_frame = 20; DrawAnime(max_frame, 5, 2, 48, 48); break;
	case 1:max_frame = 15; DrawAnime(max_frame, 5, 2, 48, 48); break;
	case 2:max_frame = 23; DrawAnime(max_frame, 5, 2, 48, 48); break;
	case 3:max_frame = 13; DrawAnime(max_frame, 5, 2, 48, 48); break;
	//case 4:max_frame = 68; DrawAnime(max_frame, 5, 1, 200, 209); break;
	default: break;
	}
	
}
void Explosion::Exit()
{

}