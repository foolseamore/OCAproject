#pragma once
#include "BaseScene.h"
class TitleScene :
	public BaseScene
{
public:
	TitleScene();
	~TitleScene();

	void Init() override;
	void Update() override;
	void Exit();
};

