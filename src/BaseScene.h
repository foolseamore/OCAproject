#pragma once
#include "define.h"
#include "BaseObject.h"
class BaseScene
{
protected:


public:
	BaseScene();
	~BaseScene();

	virtual void Init();
	virtual void Update();
	virtual void Exit();

	void Decimal_Count(BaseData *number, int size, int target)
	{
		for (int i = 0; i < size; i++)
		{
			number[i].cnt = (target / (int)(pow(10, i))) % 10;
		}
	}
	
};

