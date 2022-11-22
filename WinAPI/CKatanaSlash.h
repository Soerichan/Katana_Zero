#pragma once
#include "CMissile.h"
class CKatanaSlash :
    public CMissile
{
public:
	CKatanaSlash();
	virtual ~CKatanaSlash();

private:
	
	CSound* m_pSound;
	float m_pTimer;
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
	bool m_bBulletReflectChance;
	bool m_bReboundChance;
	

	void AnimatorUpdate() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
};

