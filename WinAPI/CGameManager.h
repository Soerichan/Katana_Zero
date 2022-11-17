#pragma once
#include "WinAPI.h"
#include <queue>

class CGameManager:  public SingleTon<CGameManager>
{
	friend SingleTon<CGameManager>;
	friend CCore;

	CGameManager();
	virtual ~CGameManager();
	void Init();
	void Update();
	void Release();

	

public: 
	Vector PlayerPos;
	Vector PrevPlayerPos;
	int Battery;
	wstring SubWeaponName;
	
	void PlayerSubWeapon();
	void PickUpProcess();
	void SubWeaponThrow();



	PlayerState PlayerNowState;
	bool RightAttack;
};

#define GAME			CGameManager::GetInstance()
#define PLAYERPOSITION  CGameManager::GetInstance()->PlayerPos

