#pragma once
#include "define.h"
#include "BaseObject.h"
class BaseScene
{
protected:

	/*float x, y;
	int img_c;
	Texture texture;*/

public:
	BaseScene();
	~BaseScene();
	/*void SetX(float inX) { x = inX; }
	void SetY(float inY) { y = inY; }
	float GetX() { return x; }
	float GetY() { return y; }*/

	//void DrawAnime(int max_frame, int frame, int speed, int sizex, int sizey,float ox,float oy);

	//virtual void Draw();

	
	virtual void Init();
	virtual void Update();
	virtual void Exit();

	
	
};

