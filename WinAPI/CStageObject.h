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

	Vector startpos;
	Vector endpos;
	float startPosx;
	float startPosy;
	float endPosx;
	float endPosx;



public:
	void SetType(TypeStageObject type);
	void SetPos(Vector startpos,Vector endpos);
	void SetPos(float startx, float starty, float endx, float endy);

	TypeStageObject GetType();
	int GetStageObjectPosX();
	int GetStageObjectPosY();
	int GetStageObjectIndex();


protected:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

