#include "framework.h"
#include "CCursor.h"

CCursor::CCursor()
{
	m_pImage = nullptr;

	m_layer = Layer::Cursor;
	m_strName = L"Ä¿¼­";
}

CCursor::~CCursor()
{
}

void CCursor::SetImage(CImage* image)
{
	m_pImage = image;
}

CImage* CCursor::GetImage()
{
	return m_pImage;
}

void CCursor::Init()
{
}

void CCursor::Update()
{
	m_vecPos = MOUSEWORLDPOS;
}

void CCursor::Render()
{
	
		if (nullptr != m_pImage)
	{
		RENDER->Image(GetImage(), m_vecPos.x-9, m_vecPos.y-9, m_vecPos.x+GetImage()->GetWidth(), m_vecPos.y+GetImage()->GetHeight());
	}
}

void CCursor::Release()
{
}
