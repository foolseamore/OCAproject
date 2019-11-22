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
	number_img = GameManager::Instance().GetNumber();
	score = GameManager::Instance().GetScores();
	
	for (int i = 3; i >= 0; i--)
	{
		g_score[i].cnt = 0;
		g_score[i].pos.x = 844 - 38 * i;
		g_score[i].pos.y = 200;
	}
}

void Score::Update()
{
	score = GameManager::Instance().GetScores();
	
	/*for (int i = 0; i < 4; i++)
	{
		g_score[i].cnt = (score / (int)(pow(10, i))) % 10;
			
	}*/
	Decimal_Count(g_score, 4, score);

	enemykill_img.draw(600, 200);
	for (int i = 0; i < 4; i++)
	{
		number_img(38 * g_score[i].cnt, 38, 38).draw(g_score[i].pos.x, g_score[i].pos.y);
	}

}

void Score::Exit()
{

}