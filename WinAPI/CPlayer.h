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


	/*void SetMyPosition(CPlayer* player);*/
	void SetMyPosition(Vector vec);
	void SetMyCurAnimation(CAnimation* Ani);
	void SetMyCurFrame(UINT Frame);
	CAnimator* GetAnimator();

	void PlayerRebound();
private:
	CSound* m_pReplaySound;
	CSound* m_pDoor_KickSound;
	CSound* m_pKatanaSound;
	CSound* m_pCronosSound;
	CSound* m_pRollSound;
	CSound* m_pPickUpSound;
	CSound* m_pDieSound;
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

	PlayerState State;
	
	float actionTimer;
	float m_fSpeed = 600.0f;



	
	float RollTimer;
	float gravityPower;
	float m_fBatteryTimer;
	float resistance;
	float AttackAngle;
	float AfterAttackTimer;
	
	float flyTimer;
	
	float m_fDieTimer;
	float m_fDoorTimer;
	float AttackTimer;
	float unGravityTimer;

	float velocity;
	float accel;
	float JumpTimer;
	
	float FlipTimer;
	float WallGrabTimer;
	float FlipDir;

	bool FlipAction;
	bool jumpAction;
	bool IsRolling;

	bool IsAttacking;
	bool OnSlope;
	bool m_bIsMove;
	bool IsHit;
	bool islanding;
	bool gravity;
	bool RightAttack;
	bool IsCronos;
	bool Struggle;
	Vector AttackPos;

	CCollider* Isgrabed;

	int m_iBattery;

	wstring m_strSubWeapon;


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
	/*void SaveMemento(Vector  Playerpos);*/
	void SaveMemento(CPlayer*  Player);
	void SetMementoAnimation(CAnimation* Animation, UINT Frame);
	void SetMementoPos(Vector pos);
	Memento* GetMemento();
	bool m_bReplay;
	float m_fMementoTimer;
	float m_fReplayTimer;
	Vector StartPos;
	CPlayer* StartPlayer;

};

