#pragma once
#include "BaseObject.h"
class EnemyBaseObject :
	public BaseObject
{
public:

	EnemyBaseObject();
	~EnemyBaseObject();

	float rot;
	float speedx, speedy;
	State state;
	

	void Init() override;
	void Update() override;
	void Exit() override;
};
