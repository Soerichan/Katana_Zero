#pragma once
#include "CMissile.h"
class CBossMissile01 :
    public CMissile
{
public: CBossMissile01();
      virtual ~CBossMissile01();

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

