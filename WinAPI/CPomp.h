#pragma once
#include "CMonster.h"
class CPomp :
    public CMonster
{
	CAnimator* m_pAnimator;
	CImage* m_pIdleImage;
	CImage* m_pWalkImage;
	CImage* m_pRunImage;
	CImage* m_pAttackImage;
	CImage* m_pAimImage;
	CImage* m_pDieImage;
	CImage* m_pDownImage;

	float m_fAimTimer;
	float m_fAttackTimer;

	void Attack()	override;
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

