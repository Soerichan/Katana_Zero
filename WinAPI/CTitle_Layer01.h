#pragma once
#include "CImageObject.h"
class CImage;
class CAnimator;

class CTitle_Layer01 :
    public CImageObject
{
public:
	CTitle_Layer01();
	virtual ~CTitle_Layer01();

private:
	CAnimator* m_pAnimator;
	

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
};

