#pragma once
#include "CMissile.h"
class CGruntSlash :
    public CMissile
{
public:
	CGruntSlash();
	virtual ~CGruntSlash();

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



