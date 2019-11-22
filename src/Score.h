#pragma once
#include "define.h"
#include"BaseScene.h"
class Score: public BaseScene
{
	Texture enemykill_img;
	Texture number_img;

	BaseData g_score[4];

	

public:
	Score();
	~Score();

	int score;

	void Init();
	void Update();
	void Exit();

	

};

