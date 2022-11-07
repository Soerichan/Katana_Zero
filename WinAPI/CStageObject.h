#pragma once
#include "CGameObject.h"

class CImage;
class CScene;

class CStageObject :
    public CGameObject
{
	friend CScene;
public:
	CStageObject();
	virtual ~CStageObject();


protected:
	TypeStageObject m_type;

	CImage* m_pImage;
	UINT m_uiImageXCount;
	UINT m_uiImageYCount;

	UINT m_uiStageObjectPosX;
	UINT m_uiStageObjectPosY;
	UINT m_uiStageObjectIndex;

	



public:
	void SetType(TypeStageObject type);
	
	

	TypeStageObject GetType();
	int GetStageObjectPosX();
	int GetStageObjectPosY();
	int GetStageObjectIndex();

	void Save(FILE* pFile);
	void Load(FILE* pFile);

protected:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

