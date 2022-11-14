#pragma once
#include "CMissile.h"
class CKatanaSlashLow :
    public CMissile
{
public:
	CKatanaSlashLow();
	virtual ~CKatanaSlashLow();

private:

	float m_pTimer;
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
	void AnimatorUpdate() override;
	void OnCollisionEnter(CCollider* pOtherCollider) override;
};

