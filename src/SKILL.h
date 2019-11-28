#pragma once
#include "BaseObject.h"
class Skill :
	public BaseObject
{
	Texture raser_img;
	int charge_cnt;
	int shot_cnt;
	float rad;

public:
	Skill();
	~Skill();

	void Init();
	void Update(float ,float);
	void Exit();

	int GetShotCount() { return shot_cnt; }
};

