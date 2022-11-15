#pragma once
#include "CImageObject.h"
class CBluntEffect :
    public CImageObject
{
public:
	CBluntEffect();
	virtual ~CBluntEffect();

private:
	CAnimator* m_pAnimator;

	float m_fTimer;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
};

