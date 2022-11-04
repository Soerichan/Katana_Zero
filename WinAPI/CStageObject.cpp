#include "framework.h"
#include "CStageObject.h"

CStageObject::CStageObject()
{
}

CStageObject::~CStageObject()
{
}

void CStageObject::SetType(TypeStageObject type)
{
}

void CStageObject::SetPos(Vector startpos, Vector endpos)
{

}

void CStageObject::SetPos(float startx, float starty, float endx, float endy)
{
}

TypeStageObject CStageObject::GetType()
{
	return TypeStageObject();
}

int CStageObject::GetStageObjectPosX()
{
	return 0;
}

int CStageObject::GetStageObjectPosY()
{
	return 0;
}

int CStageObject::GetStageObjectIndex()
{
	return 0;
}

void CStageObject::Init()
{
}

void CStageObject::Update()
{
}

void CStageObject::Render()
{
}

void CStageObject::Release()
{
}
