#include "Explosion.h"
#include "GameManager.h"


Explosion::Explosion()
{
	
}


Explosion::~Explosion()
{
}

void Explosion::Init(int kind)
{
	select_effect = kind;
	texture = GameManager::Instance().GetExplode(kind);
	
}
void Explosion::Update()
{
	switch (select_effect)
	{
	case 0:max_frame = 20; DrawAnime(max_frame, 5, 2, 48, 48); break;
	case 1:max_frame = 15; DrawAnime(max_frame, 5, 2, 48, 48); break;
	case 2:max_frame = 23; DrawAnime(max_frame, 5, 2, 48, 48); break;
	case 3:max_frame = 13; DrawAnime(max_frame, 5, 2, 48, 48); break;
	case 4:max_frame = 68; DrawAnime(max_frame, 5, 4, 100, 105); break;
	default: break;
	}
	
}
void Explosion::Exit()
{

}