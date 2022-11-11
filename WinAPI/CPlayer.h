#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

//========================================
//##		 플레이어 상태			##
//========================================

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
	Die

};

class CPlayer : public CGameObject
{
public:
	CPlayer();
	virtual ~CPlayer();

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

	float WallGrabTimer;
	CCollider* Isgrabed;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void Jump();

	void AnimatorUpdate();
	void CreateMissile();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;

	void WhereAmI();
	void WhereWasI();
	

};

