#pragma once
#include "CGameObject.h"
class CSlidingDoor :
    public CGameObject
{

public:
    
    CSlidingDoor();
      virtual ~CSlidingDoor();

private:
    CImage* pImage;
    CAnimator* m_pAnimator;
    bool m_bRed;
    float m_fTimer;

    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;
    void AnimatorUpdate();
};

