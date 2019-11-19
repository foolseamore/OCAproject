#pragma once
#include "define.h"
#include "SceneManager.h"
#include "Singleton.h"
#include"ULT.h"

class GameManager :public Singleton<GameManager>
{
public:
	
	~GameManager();

	int gameState;

	void Init();
	void Update();
	void Exit();

	
	
	Texture GetPlayer1() { return player1_img; }
	Texture GetPlayer2() { return player2_img; }
	Texture GetEarth() { return earth_img; }
	Texture GetGinnga() { return ginnga_img; }
	Texture GetBullet() { return bullet_img; }
	Texture GetNumber() { return number_img; }
	Texture GetScore() { return score_img; }
	Texture GetTime() { return time_img; }
	Texture GetEarthHp() { return earth_hp_img; }
	Texture GetHpBar() { return hpbar_img; }
	Texture GetHpWords() { return hpwords_img; }
	Texture GetUltWords() { return ultwords_img; }
	Texture GetEnergyBar() { return energybar_img; }
	Texture GetEnemyKilled() { return enemykilled_img; }

	Texture GetEnemy(int type, int a) 
	{
		switch (type)
		{
		case 1:return enemy_img_type1[a]; break;
		case 2:return enemy_img_type2[a]; break;
		case 3:return enemy_img_type3[a]; break;
		default: break;
		}
	}

	//score
	void SetScore(int sets) { score = sets; }
	int GetScores() { return score; }

private:
	friend class Singleton<GameManager>;
	GameManager();

	SceneManager* sceneManager;

	Texture player1_img, player2_img;
	Texture earth_img, ginnga_img;
	Texture enemy_img_type1[TYPE1_MAX];
	Texture enemy_img_type2[TYPE2_MAX];
	Texture enemy_img_type3[TYPE3_MAX];

	//Texture enemy_img[ENEMY_TEXTURE];
	Texture bullet_img;
	Texture number_img;
	Texture score_img;

	//UI Texture
	Texture time_img;
	Texture earth_hp_img;
	Texture hpbar_img;
	Texture hpwords_img;
	Texture ultwords_img;
	Texture energybar_img;
	Texture enemykilled_img;


	int score = 0;


};

