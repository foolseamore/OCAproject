#pragma once
#include "BaseScene.h"
class TitleScene :
	public BaseScene
{
	Texture title_img;
	Texture bg_img;
	Texture start_img;
	Texture exit_img;
	Texture select_img;
public:
	TitleScene();
	~TitleScene();

	void Init() override;
	void Update() override;
	void Exit();
};

