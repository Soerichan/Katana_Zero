#pragma once
#include "CMissile.h"
class CBossCMissile02 :
    public CMissile
{
public: CBossCMissile02();
      virtual ~CBossCMissile02();

private:
    CImage* m_pImage;
    float m_fTimer;
    float accel;
    float velocity;
    bool m_bRight;
    void AnimatorUpdate() override;
    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;
};

