#pragma once
#include <Siv3D.hpp>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <memory>
#include <iostream>
#include<Windows.h>
using namespace std;

#define WINDOW_W		   900
#define WINDOW_H		   750
#define GAME_WINDOW_W      600
#define GAME_WINDOW_H      600
#define GAME_DEAD_RANGE    650
#define PI                 3.141562654f
#define TO_RAD(deg)        deg/360*2*PI
#define TO_DEG(rad)        rad/2/PI*360

#define ENEMY_TEXTURE      25
#define ENEMY_SIZE         48
#define ENEMY_BULLET_MAX   20
#define ENEMY_BORNPOS      240
#define ENEMY_SPEED        5.0
#define TYPE1_MAX		   5
#define TYPE2_MAX		   5
#define TYPE3_MAX		   5

#define ENEMY_ROW          4
#define ENEMY_COL          11

#define BOSS_SIZE_X        200
#define BOSS_SIZE_Y        128

#define PLAYER_SIZE_X      100
#define PLAYER_SIZE_Y      128
#define PLAYER_SPEED       10.0


#define BULLET_MAX		   20
#define BOSS_BULLET_MAX    200
#define BOSS_BULLET_SPEED  6




#define ONE_WAVE           40

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
	BORN,
	REFLECT,
	SKILL,
	EXPLODE,
};

enum TAG
{
	T_Enemy=100,
	T_Boss,
};


struct BaseData
{
	int cnt;
	Point pos;
};


