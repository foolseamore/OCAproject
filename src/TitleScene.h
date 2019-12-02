#pragma once
#include "BaseScene.h"
#include "EnemyBaseObject.h"
class TitleScene :
	public BaseScene
{
	Texture title_img;
	Texture earth_img;
	Texture bg_img;
	Texture start_img;
	Texture exit_img;
	Texture select_img;
	BaseData select;
	//Point select;

	EnemyBaseObject enemy[10];

public:
	TitleScene();
	~TitleScene();

	void Init() override;
	void Update() override;
	void Exit();
};

