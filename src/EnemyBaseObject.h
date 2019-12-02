#pragma once
#include "BaseObject.h"
class EnemyBaseObject :
	public BaseObject
{
protected:

	int wave;
	int tag;

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

	void SetTag(int tags) { tag = tags; }
	int GetTag() { return tag; }


};

