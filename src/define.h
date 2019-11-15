#pragma once
#include <Siv3D.hpp>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <memory>
#include <iostream>
#include<Windows.h>
using namespace std;

#define WINDOW_W 900
#define WINDOW_H 750
#define GAME_WINDOW_W 600
#define GAME_WINDOW_H 600
#define PI 3.141562654f
#define TO_RAD(deg) deg/360*2*PI
#define TO_DEG(rad) rad/2/PI*360

#define ENEMY_TEXTURE 25
#define ENEMY_BULLET_MAX 20
#define TYPE1_MAX 5

#define PLAYER_SPEED 5.0
#define ENEMY_SPEED 5.0

#define BULLET_MAX 20

#define TYPE1_MAX 5
#define TYPE2_MAX 5
#define TYPE3_MAX 5


enum GameState
{
	Title,
	Play,
	End,

	GAME_STATE_MAX,

};

enum State
{
	LIVE = 50,
	DEAD = 51,
	BURN,
	REFLECT,
};

struct BaseData
{
	int cnt;
	Point pos;
};

