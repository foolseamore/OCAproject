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

	void Init(int);
	void Update();
	void Exit();
};

