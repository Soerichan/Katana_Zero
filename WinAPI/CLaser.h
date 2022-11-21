#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;

class CLaser :
    public CGameObject
{
    enum class LaserState
    {
        On,
        Off
    };

public:
    CLaser();
    virtual ~CLaser();
    void SetSwitchPos(Vector pos);
    void SetRight(bool Right);
    void TurnOff();
    void SwitchLaser();
    void SetMove();
private:
    bool m_bMove;
    float m_fMoveTimer;
    void AnimatorUpdate();
    CAnimator* m_pAnimator;
    Vector m_vecSwitchPos;
    bool m_bOff;
    bool m_bRight;
    bool m_bHit;
    LaserState m_State;
    float m_fTimer;
    Vector m_vecDistance;
    float m_fDistance;
    float m_fHitTimer;
    CImage* m_pLaserImage;
   // CImage* m_pLaserSwitchImage;
   // CImage* m_pLaserSwitch2Image;
   // CImage* m_pSpace1Image;
   // CImage* m_pSpace2Image;

   
    void   OnCollisionEnter(CCollider* pOtherCollider);

    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;
};

