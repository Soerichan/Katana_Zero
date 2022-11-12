#pragma once
#include "CGameObject.h"

class CImage;

class CImageObject : public CGameObject
{
public:
	CImageObject();
	virtual ~CImageObject();

protected:
	CImage* m_pImage;

public:
	CImage* GetIamge();
	void SetImage(CImage* pImage);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

