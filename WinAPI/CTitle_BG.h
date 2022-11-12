#pragma once
#include "CGameObject.h"
class CTitle_BG :
    public CGameObject
{
public:
	CTitle_BG();
	virtual ~CTitle_BG();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

