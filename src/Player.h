#pragma once
#include "BaseObject.h"
class Player :
	public BaseObject
{
public:
	Player();
	~Player();

	bool isCombine = false;

	
	void Init() override;
	void Update() override;
	void Exit() override;
	void Key_Op();
	

private :

	void DrawRectP(int sizex,int sizey);
	
};

