#include "framework.h"
#include "CStageObject.h"

CStageObject::CStageObject()
{
	m_layer = Layer::StageObject;
	
}

CStageObject::~CStageObject()
{
}

void CStageObject::SetType(TypeStageObject type)
{
	m_type = type;
}



TypeStageObject CStageObject::GetType()
{
	return TypeStageObject();
}

int CStageObject::GetStageObjectPosX()
{
	return m_vecPos.x;
}

int CStageObject::GetStageObjectPosY()
{
	return m_vecPos.y;
}

int CStageObject::GetStageObjectIndex()
{
	return 0;
}

void CStageObject::Save(FILE* pFile)
{
	fwrite(&m_vecPos.x, sizeof(int), 1, pFile);
	fwrite(&m_vecPos.y, sizeof(int), 1, pFile);
	fwrite(&m_vecScale.x, sizeof(int), 1, pFile);
	fwrite(&m_vecScale.y, sizeof(int), 1, pFile);
	int type = (int)m_type;
	fwrite(&type, sizeof(int), 1, pFile);
}

void CStageObject::Load(FILE* pFile)
{
	fread(&m_vecPos.x, sizeof(int), 1, pFile);
	fread(&m_vecPos.y, sizeof(int), 1, pFile);
	fread(&m_vecScale.x, sizeof(int), 1, pFile);
	fread(&m_vecScale.y, sizeof(int), 1, pFile);
	int type;
	fread(&type, sizeof(int), 1, pFile);
	m_type = (TypeStageObject)type;
}

void CStageObject::Init()
{
}

void CStageObject::Update()
{
}

void CStageObject::Render()
{
	RENDER->FrameRect(
		m_vecPos.x,
		m_vecPos.y,
		m_vecPos.x + m_vecScale.x,
		m_vecPos.y + m_vecScale.y );
}

void CStageObject::Release()
{
}
