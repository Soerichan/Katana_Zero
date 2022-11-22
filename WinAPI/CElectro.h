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
	CImage* m_pImage;
	CImage* m_pImage2;
	CSound* m_pSound;
	CSound* m_pSound2;
	float m_fTimer;
	bool m_b1phase;
	bool m_b2phase;
	bool Die;
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void AnimatorUpdate();
};

