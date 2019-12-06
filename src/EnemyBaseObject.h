#pragma once
#include "BaseObject.h"
#include "Explosion.h"
class EnemyBaseObject :
	public BaseObject
{
protected:

	int wave;
	
	Explosion *explode;

public:

	EnemyBaseObject();
	~EnemyBaseObject();

	float rot;
	float speedx, speedy;
	State state;
	int born_pos;
	int r_cnt;

	void Init() override;
	void Update() override;
	void Exit() override;

	


};

