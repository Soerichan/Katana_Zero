#pragma once
#include "CGameObject.h"
class CBackGround :
    public CGameObject
{
public:
	CBackGround();
	virtual ~CBackGround();

	CBackGround* m_BackGround;

	void Load(wstring Key, wstring Path);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

