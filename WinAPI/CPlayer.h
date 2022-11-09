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

	Vector m_vecMoveDir;
	Vector m_vecLookDir;
	bool m_bIsMove;

	float actionTimer;
	PlayerState State;

	float m_fSpeed = 600.0f;

	bool gravity;
	float gravityPower;
	bool islanding;
	bool jumpAction;
	float flyTimer;
	float unGravityTimer;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
	void CreateMissile();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;

	void WhereAmI();
	

};

