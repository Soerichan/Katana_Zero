#pragma once
#include "CImageObject.h"
class CSubWeapon :
    public CImageObject
{
public:
    CSubWeapon();
    virtual ~CSubWeapon();
    void SetDir(Vector dir);
private:
    CSound* m_pSound;
    Vector m_vecDir;
    float m_fDistance;
    void Init() override;
    void Update() override;
    void Render() ;
    void Release() ;
    void OnCollisionEnter(CCollider* pOtherCollider) override;
};

