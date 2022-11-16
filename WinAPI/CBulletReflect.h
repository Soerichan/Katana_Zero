#pragma once
#include "CImageObject.h"
class CBulletReflect :
    public CImageObject
{
public:
	CBulletReflect();
	virtual ~CBulletReflect();

private:
	CAnimator* m_pAnimator;

	float m_fTimer;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
};

