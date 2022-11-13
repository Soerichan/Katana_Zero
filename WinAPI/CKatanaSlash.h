#pragma once
#include "CMissile.h"
class CKatanaSlash :
    public CMissile
{
public:
	CKatanaSlash();
	virtual ~CKatanaSlash();

private:
	
	float m_pTimer;
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
};

