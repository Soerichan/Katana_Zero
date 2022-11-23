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
	bool Godmod;
	Vector PlayerPos;
	Vector PrevPlayerPos;
	Vector BossPos;
	wstring SubWeaponName;
	int Battery;
	int m_iDeadMonster;
	bool LaserOff;
	bool CamRed;
	bool InDanceFloor;
	bool isCronos;
	bool isReplay;
	bool isStruggleing;
	bool RightAttack;
	bool Remodeling;
	bool m_bClear;

	CSound* m_pBGM_Start_Sound;
	CSound* m_pBGM_Main_Sound;
	CSound* m_pBGM_BOSS_Sound;

	void PlayerSubWeapon();
	void PickUpProcess();
	void SubWeaponThrow();

	//void SaveMemento(Vector Playerpos);
	//Memento* GetMemento();
	/*bool m_bReplay;
	float m_fMementoTimer;*/

	PlayerState PlayerNowState;

};

#define GAME			CGameManager::GetInstance()
#define PLAYERPOSITION  CGameManager::GetInstance()->PlayerPos

