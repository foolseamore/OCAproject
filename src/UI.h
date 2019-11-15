#pragma once
#include "BaseScene.h"
#include "Time.h"
#include"HpUI.h"
#include "ULT.h"
#include "Score.h"
class UI :
	public BaseScene
{

	TimeUI *timeUI;
	HpUI *hpUI;
	//ULT *ultUI;
	Score *score;

public:
	UI();
	~UI();



	void Init() override;
	void Update() override;
	void Exit();
};

