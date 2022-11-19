#pragma once
#include "CImageObject.h"
class CZippo :
    public CImageObject
{
public:
	CZippo();
	virtual ~CZippo();

private:
	CAnimator* m_pAnimator;

	float m_fTimer;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
};

