#pragma once
#include "define.h"
#include "BaseScene.h"
class HpUI:public BaseScene
{
	
	Texture number_img;
	Texture hp_img;
	Texture hpbar_img;
	Texture hpwords_img;
	int img_c;

	BaseData g_hp[3];

	Color rgb;

	int Game_hp;

public:

	HpUI();
	~HpUI();
	
	float damage;


	void Init();
	void Update();
	void Exit();

	void ColorControl();
	void DrawAnime(Texture texture,int max_frame, int frame, int speed,float scalerate, int sizex, float sizey,int getx,float gety);

	/*int GetHp() { return g_hp[2].cnt; }
	void SetHp(int sethp) { g_hp[2].cnt = sethp; }*/
};

