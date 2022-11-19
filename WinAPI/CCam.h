#pragma once
#include "CGameObject.h"
class CCam :
    public CGameObject
{
public: 
    CCam();
    virtual ~CCam();

private:
    CImage* pImage;
    CAnimator* m_pAnimator;
    bool m_bRed;

    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;
    void AnimatorUpdate();
    void OnCollisionEnter(CCollider* pOtherCollider);
    
    void OnCollisionExit(CCollider* pOtherCollider);
};

