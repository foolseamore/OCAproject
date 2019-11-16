#pragma once
#include "singleton.h"
#include "BaseObject.h"
class Player2 :
	public BaseObject,public Singleton<Player2>
{
public:
	Player2();
	~Player2();
	bool isCombine = false;


	void Init() override;
	void Update() override;
	void Exit() override;
	void Key_Op();
	

private:
	void DrawRectP(int sizex, int sizey);
};

