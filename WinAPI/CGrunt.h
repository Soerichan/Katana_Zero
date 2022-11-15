#pragma once
#include "CMonster.h"
class CGrunt :
    public CMonster
{
public:
	CGrunt();
	virtual ~CGrunt();

private:

	CAnimator* m_pAnimator;
	CImage* m_pIdleImage;
	CImage* m_pWalkImage;
	CImage* m_pRunImage;
	CImage* m_pAttackImage;
	CImage* m_pDieImage;
	CImage* m_pLaserImage;
	
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

