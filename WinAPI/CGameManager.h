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
	bool LaserOff;
	bool CamRed;
	bool InDanceFloor;
	int m_iDeadMonster;
	bool isCronos;

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
	bool RightAttack;
	bool Remodeling;
	bool m_bClear;
};

#define GAME			CGameManager::GetInstance()
#define PLAYERPOSITION  CGameManager::GetInstance()->PlayerPos

