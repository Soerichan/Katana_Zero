#pragma once
#include "CImageObject.h"
class CImage;
class CAnimator;

class CTitle_Layer02 :
	public CImageObject
{
public:
	CTitle_Layer02();
	virtual ~CTitle_Layer02();

private:
	CAnimator* m_pAnimator;


	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
};