#pragma once
#include "define.h"
#include "SceneManager.h"
#include "Singleton.h"
#include"ULT.h"

class GameManager :public Singleton<GameManager>
{
public:
	
	~GameManager();

	GameState gameState;

	void Init();
	void Update();
	void Exit();

	
	Texture GetTitle() { return title_img; }
	Texture GetTitleEarth(){return title_earth_img;}
	Texture GetBg() { return ginnga_t_img; }
	Texture GetStart() { return start_img; }
	Texture GetExit() { return exit_img; }
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
	Texture GetLight() { return light_img; }
	Texture GetRaser() { return raser_img; }

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

	Texture GetBoss(int g_wave)
	{
		return boss_img[g_wave];
	}
	Texture GetExplode(int rand)
	{
		return explosion_img[rand];
	}

	//score
	void SetScore(int sets) { score = sets; }
	void AddScore(int add) { score += add; }
	int GetScores() { return score; }
	//wave
	//void SetWave(int setw) { wave = setw/ONE_WAVE+1; }
	int GetWave() { return wave+score / ONE_WAVE; }
	//hp
	void SetHp(int seth) { hp = seth; }
	void DecreseHP(int damage) { hp -= damage; }
	int GetHp() { return hp; }
	//time
	void SetTime(int sett) { time = sett; }
	int GetTimes() { return time; }

private:
	friend class Singleton<GameManager>;
	GameManager();

	SceneManager* sceneManager;
	//title
	Texture title_img;
	Texture ginnga_t_img;
	Texture start_img;
	Texture exit_img;
	Texture title_earth_img;

	Texture player1_img, player2_img;
	Texture earth_img, ginnga_img;
	Texture light_img;
	Texture raser_img;

	Texture enemy_img_type1[TYPE1_MAX];
	Texture enemy_img_type2[TYPE2_MAX];
	Texture enemy_img_type3[TYPE3_MAX];
	Texture boss_img[6];


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

	//effect explosion
	Texture explosion_img[5];
	



	int score = 0; //score
	int wave = 1;  
	int hp = 100;
	int time = 180;



};

