#pragma once
#include "CGameObject.h"

class CLaserSwitch :
    public CGameObject
{
    enum class state
    {
        On,
        Off
    };

public:
    CLaserSwitch();
    virtual ~CLaserSwitch();


private:
    bool m_bOff;
    bool m_bRight;
    bool m_bCanHandle;
    state m_State;

    Vector m_vecDistance;
    float m_fDistance;

    CImage* m_pImage;
    CAnimator* m_pAnimator;
    void AnimatorUpdate();
    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;
};

