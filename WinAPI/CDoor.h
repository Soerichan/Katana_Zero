#pragma once
#include "CGameObject.h"
class CDoor :
    public CGameObject
{
public:
    CDoor();
    virtual ~CDoor();

    bool GetCheckOpen();

    void Open();

    float m_fTimer;

    CAnimator* m_pAnimator;
    CImage* m_pCloseImage;
    CImage* m_pOpenImage;
    CImage* m_pAnimationImage;

    

private:
    bool m_bIsOpen;

   void Init()  override;
   void Update()  override;
   void Render()  override;
   void Release()  override;

   void AnimatorUpdate();

   void OnCollisionEnter(CCollider* pOtherCollider) override;
};

