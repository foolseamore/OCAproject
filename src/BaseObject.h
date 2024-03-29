#pragma once
#include"define.h"

class BaseObject
{
protected:
	int tag;
	
	
	

public:

	RectF rect;
	Circle circle;
	float x, y;
	Texture texture;
	int img_c;
	

	BaseObject();
	~BaseObject();
	void SetX(float inX) { x = inX; }
	void SetY(float inY) { y = inY; }
	float GetX() { return x; }
	float GetY() { return y; }
	int GetImg_C() { return img_c; }
	void SetTag(int tags) { tag = tags; }
	int GetTag() { return tag; }
	RectF GetRect() { return rect; }
	void DrawRect(int sizex,int sizey);
	void DrawCircle(int sizex);
	void DrawAnime(int max_frame, int frame, int speed, int sizex, int sizey);
	void RangeCheck();
	


	
	virtual void Init();
	virtual void Update();
	virtual void Exit();

};

