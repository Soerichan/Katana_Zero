#pragma once

#include "resource.h"

//========================================
//##    ��������(�ν��Ͻ�, ������ �ڵ�)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;

//========================================
//##			������ ����				##
//========================================

#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//========================================
//##			���Ӿ� �׷�				##
//========================================

enum class GroupScene
{
	Title,

	TileTool,

	Scene_file,

	Scene000,

	Scene001,

	Scene002,

	Scene003,

	Scene004,

	Scene005,

	Scene006,

	Stage01,

	SceneEnding,

	Size,
};

//========================================
//##				���̾�				##
//========================================

enum class Layer
{
	Default,
	
	Tile,
	StageObject,
	Entrance,
	Laser,
	Corpse,
	SubWeapon,
	Door,
	SD,
	Cam,
	Monster,
	Player,
	EnemyMissile,
	Smoke,
	Effect,
	Missile,
	
	
	

	Ui,

	Cursor,

	Size,
};

//========================================
//##				Ÿ��					##
//========================================

enum class TypeTile
{
	None,
	Ground,
	Platform,
	Wall,

	Size,
};

//========================================
//##		 �������� ������Ʈ			##
//========================================

enum class TypeStageObject
{
	None,
	Ground,
	Wall,
	R_Hihg_Slope,
	L_Hihg_Slope,
	Platfoam,
	Door,
	MonsterSpawn,
	Throws,

	Size,
};

enum class PlayerState
{
	Idle,
	Run,
	Attack,
	Roll,
	WallGrab,
	Stun,
	Flip,
	Jump,
	Fall,
	Dance,
	Die,
	DoorKick

};

enum class MonsterState
{
	Idle,
	Attention,
	Chase,
	Attack,
	Aim,
	Fire,
	Down,
	StandUp,
	Laser,
	Die
};



