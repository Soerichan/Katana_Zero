#pragma once
#include "CGameObject.h"
class CElectro :
    public CGameObject
{
 public:
    CElectro();
   virtual ~CElectro();

private:
	CAnimator* m_pAnimator;

	float m_fTimer;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();
};

