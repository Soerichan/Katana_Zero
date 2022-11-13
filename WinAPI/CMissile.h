#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;
class CMissile : public CGameObject
{
public:
	CMissile();
	virtual ~CMissile();

protected:
	Vector m_vecDir;
	float m_fVelocity;
	CAnimator* m_pAnimator;
	CImage* m_pImage;
	
	void virtual AnimatorUpdate()=0;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;

public:
	void SetDir(Vector dir);
	void SetVelocity(float velocity);
};