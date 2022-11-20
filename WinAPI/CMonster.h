#pragma once
#include "CGameObject.h"

class CMonster : public CGameObject
{
public:
	CMonster();
	virtual ~CMonster();

	void SetPatroller(bool Patroll);
	
	//Vector GetStair();
	//Vector GetStair2();
	//void SetStair(Vector Stair);
	//void SetStair2(Vector Stair);

protected:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	MonsterState m_mState;
	Vector m_vecFixedPosition;
	Vector m_vecLookDir;

	bool m_bIsMove;
	bool m_bPlayerIsSameFloor;
	/*bool m_bPlayerIsUpFloor;
	bool m_bPlayerIsDownFloor;*/
	bool m_bIsDie;
	bool Patroller;

	/*bool m_bEnterStair;*/

	float m_fSpeed = 500.0f;
	//Vector m_vecWhereIsStairUp;
	//Vector m_vecWhereIsStairDown;
	//Vector m_vecWhereIsStair2Up;
	//Vector m_vecWhereIsStair2Down;
	Vector m_vecWhereIsPlayer;

	float m_fIdleTimer;
	float m_fWalkTimer;
	float m_fWalkTimer2;
	float m_fAttackTimer;
	float m_fAfterAttackTimer;
	float m_fDieTimer;
	/*float m_fEnterStairTimer;*/
	
	float m_fAttentionTimer;
	//float IdleTimer;
	//float IdleTimer;

	float m_fRange;

	void VisualSensor();
	void Sight();
	void AuditorySensor();
	void Hearing();
	virtual void Attack()=0;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

