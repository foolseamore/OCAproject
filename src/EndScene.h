#pragma once
#include "BaseScene.h"
class EndScene :
	public BaseScene
{
public:
	EndScene();
	~EndScene();
	void Init() override;
	void Update() override;
	void Exit();
};

