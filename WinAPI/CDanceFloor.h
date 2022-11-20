#pragma once
#include "CGameObject.h"
class CDanceFloor :
    public CGameObject
{
public:
    CDanceFloor();
    virtual ~CDanceFloor();
    void SetTwo(bool Istwo);

private:
    CAnimator* m_pAnimator;
    CImage* m_pImage;
    bool m_bTwo;
    void AnimatorUpdate();
    void Init() override;
    void Update() override;
    void Render() override;
    void Release() override;
    void OnCollisionEnter(CCollider* pOtherCollider) override;
    void OnCollisionStay(CCollider* pOtherCollider) override;
    void OnCollisionExit(CCollider* pOtherCollider) override;
};

