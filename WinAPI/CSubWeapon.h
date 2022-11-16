#pragma once
#include "CImageObject.h"
class CSubWeapon :
    public CImageObject
{
public:
    CSubWeapon();
    virtual ~CSubWeapon();
private:
    void Init() override;
    void Update() override;
    void Render() ;
    void Release() ;
};

