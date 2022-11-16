#pragma once
#include "CImageObject.h"
class CGunSpark :
    public CImageObject
{
public:
	CGunSpark();
	virtual ~CGunSpark();

	void SetxDir(bool xDir);
private:
	bool m_bToRight;
	CAnimator* m_pAnimator;

	float m_fTimer;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
};

