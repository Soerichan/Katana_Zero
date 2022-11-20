#pragma once
#include "CGameObject.h"
class CSmokePipe :
    public CGameObject
{
public:
    CSmokePipe();
    virtual ~CSmokePipe();

private:
    CImage* pImage;
    CAnimator* m_pAnimator;
    bool m_bCrushed;

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
