#pragma once
#include "CGameObject.h"
class CSmoke :
    public CGameObject
{
public:
    CSmoke();
    virtual ~CSmoke();

private:
    CImage* pImage;
    CSound* pSound;
    CAnimator* m_pAnimator;
    float m_fTimer;

    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;
    void AnimatorUpdate();
    void OnCollisionEnter(CCollider* pOtherCollider);
    void OnCollisionStay(CCollider* pOtherCollider);
    void OnCollisionExit(CCollider* pOtherCollider);
};

