#pragma once
#include "define.h"
class BaseBullet
{
	Texture texture;

public:

	RectF rect;
	Point pos;
	float speedx, speedy;
	bool flag = false;
	bool IsReflect;
	int bullet_kind;

	BaseBullet();
	~BaseBullet();

	void Init(float getx,float gety,int movx,int movy);
	void Update(int kind,int type);
	void Exit();
	void DrawRect(int size);

private:
	void CheckReflect(int size,int type);
	void BulletRender(int kind );
	
};

