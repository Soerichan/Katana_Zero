#pragma once
#include "CMissile.h"
class CBossCMissile03 :
    public CMissile
{
public:
    CBossCMissile03();
    virtual ~CBossCMissile03();
    void SetLundge(Vector vec);
private:
    float m_fTimer;

    void AnimatorUpdate() override;
    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;
};

