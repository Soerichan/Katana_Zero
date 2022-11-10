#include "framework.h"
#include "CBackGround.h"
#include "CImage.h"

CBackGround::CBackGround()
{
	m_pImage = nullptr;

	m_layer = Layer::Tile;
	m_strName = L"¸Ê";
}

CBackGround::~CBackGround()
{
}



void CBackGround::SetImage(CImage* Image)
{
	m_pImage = Image;
}

CImage* CBackGround::GetImage()
{
	return m_pImage;
}

void CBackGround::Init()
{
}

void CBackGround::Update()
{ 
}

void CBackGround::Render()
{
	if (nullptr != m_pImage)
	{
		RENDER->Image(GetImage(),0,0,GetImage()->GetWidth(), GetImage()->GetHeight());
	}
}

void CBackGround::Release()
{
}
