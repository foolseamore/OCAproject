#pragma once
#include "BaseObject.h"
class Explosion :
	public BaseObject
{
	int select_effect;
	
public:
	Explosion();
	~Explosion();

	int max_frame;

	void SetE(int se) { select_effect = se; }

	void Init();
	void Update();
	void Exit();
};

