#pragma once
#include "CImageObject.h"
class CImage;
class CAnimator;

class CTitle_Layer04 :
	public CImageObject
{
public:
	CTitle_Layer04();
	virtual ~CTitle_Layer04();

private:
	CAnimator* m_pAnimator;


	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
};

