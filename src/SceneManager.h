#pragma once
#include "define.h"
#include "BaseScene.h"

enum Game_Scene
{
	g_Title,
	g_Game,
	g_UI,
	g_End,

	Scene_MAX,
};

class SceneManager
{
public:
	
	SceneManager();
	~SceneManager();

	

	void Init();
	void Update(int);
	void Exit();
	
private:

	BaseScene *scene[Scene_MAX];
	
};

