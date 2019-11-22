#pragma once
#include "BaseObject.h"
class EnemyBaseObject :
	public BaseObject
{
protected:

	int wave;

public:

	EnemyBaseObject();
	~EnemyBaseObject();

	float rot;
	float speedx, speedy;
	State state;
	int born_pos;

	void Init() override;
	void Update() override;
	void Exit() override;
};

