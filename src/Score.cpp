#include "Score.h"
#include "GameManager.h"


Score::Score()
{
}


Score::~Score()
{
}

void Score::Init()
{
	enemykill_img = GameManager::Instance().GetEnemyKilled();
}

void Score::Update()
{

	enemykill_img.draw(600, 200);

}

void Score::Exit()
{

}