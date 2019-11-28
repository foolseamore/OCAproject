#pragma once
#include "singleton.h"
#include "BaseObject.h"
class Player :
	public BaseObject,public Singleton<Player>
	
{
public:
	Player();
	~Player();

	bool isCombine = false;
	State state;

	
	void Init() override;
	void Update() override;
	void Exit() override;
	void Key_Op();
	

private :

	void DrawRectP(int sizex,int sizey);
	
};

