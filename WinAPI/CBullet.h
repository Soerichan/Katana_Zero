#pragma once
#include "CMissile.h"
class CBullet :
    public CMissile
{
public:
	CBullet();
	virtual ~CBullet();

	void SetDir(bool Dir);
private:

	bool m_bRight;
	float m_pTimer;


	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;


	void AnimatorUpdate() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
};

