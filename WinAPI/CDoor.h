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
    float m_fOpenTimer;

    CAnimator* m_pAnimator;
    CImage* m_pCloseImage;
    CImage* m_pOpenImage;
    CImage* m_pAnimationImage;

   

    enum class DoorState
    {
        Close,
        Opening,
        Open
    };

private:
    DoorState m_State;
    bool m_bIsOpen;
    bool m_bUsed;

    

   void Init()  override;
   void Update()  override;
   void Render()  override;
   void Release()  override;

   void AnimatorUpdate();

   void OnCollisionEnter(CCollider* pOtherCollider) override;
};

