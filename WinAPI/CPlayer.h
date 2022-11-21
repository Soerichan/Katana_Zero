#pragma once
#include "CGameObject.h"
#include "framework.h"

#include "WinAPI.h"

class CareTaker;
class CImage;
class CAnimator;

//========================================
//##		 플레이어 상태			##
//========================================



class CPlayer : public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();


	void SetMyPosition(Vector Pos);
private:
	CAnimator* m_pAnimator;
	CImage* m_pIdleImage;
	CImage* m_pMoveImage;
	CImage* m_pAttackImage;
	CImage* m_pRollImage;
	CImage* m_pWallGrabImage;
	CImage* m_pStunImage;
	CImage* m_pFlipImage;
	CImage* m_pJumpImage;
	CImage* m_pFallImage;
	CImage* m_pDanceImage;
	CImage* m_pCrouchImage;
	CImage* m_pDoor_KickImage;
	CImage* m_pHurtCoverImage;
	CImage* m_pHurtFlyImage;
	CImage* m_pHurtGroundImage;
	CImage* m_pEarPhoneImage;
	CImage* m_pDieImage;

	Vector m_vecMoveDir;
	Vector m_vecLookDir;
	bool m_bIsMove;

	float actionTimer;
	PlayerState State;

	float m_fSpeed = 600.0f;

	bool OnSlope;

	
	bool gravity;
	float gravityPower;
	float resistance;
	bool islanding;
	
	float flyTimer;
	
	float unGravityTimer;

	float velocity;
	float accel;
	float JumpTimer;
	bool jumpAction;
	
	bool FlipAction;
	float FlipTimer;
	float WallGrabTimer;
	CCollider* Isgrabed;
	float FlipDir;

	bool IsRolling;
	float RollTimer;

	bool IsAttacking;
	bool IsHit;
	float AttackTimer;
	float AfterAttackTimer;
	bool RightAttack;
	float AttackAngle;
	Vector AttackPos;

	float m_fDieTimer;

	float m_fBatteryTimer;
	int m_iBattery;
	bool IsCronos;

	wstring m_strSubWeapon;

	float m_fDoorTimer;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void Jump();

	void Flip();

	void Roll();

	void Attack();

	void Throw();

	void Dance();

	void AnimatorUpdate();
	void CreateMissile();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;

	void WhereAmI();
	void WhereWasI();
	void WhatIsMyState();
	void MyBattery();
	void WhatIHave();
	

	
	//void SaveMemento(Vector  Playerpos);
	void SaveMemento(Vector  Playerpos);
	Memento* GetMemento();
	bool m_bReplay;
	float m_fMementoTimer;
	float m_fReplayTimer;
	Vector StartPos;

};

