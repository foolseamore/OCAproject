#pragma once
#include "EnemyBaseObject.h"
class enemyType1 :
	public EnemyBaseObject
{
public:
	enemyType1();
	~enemyType1();

	bool IsReflect;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Exit() override;
private:

	void CheckReflect(int size);
};

