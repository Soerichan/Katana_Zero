#pragma once
#include "CGameObject.h"
class CImage;
class CBackGround :
    public CGameObject
{
public:
	CBackGround();
	virtual ~CBackGround();

	CBackGround* m_BackGround;

	CImage* m_pImage;
	void SetImage(CImage* image);
	CImage* GetImage();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

