#pragma once
#include "CImageObject.h"
class CNoise :
    public CImageObject
{
public:
	CNoise();
	virtual ~CNoise();

	//void SetxDir(bool xDir);
private:
	//bool m_bToRight;
	CAnimator* m_pAnimator;

	float m_fTimer;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
};

