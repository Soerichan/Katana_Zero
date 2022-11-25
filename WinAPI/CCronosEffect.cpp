#include "framework.h"
#include "CCronosEffect.h"

CCronosEffect::CCronosEffect()
{
	m_layer = Layer::Cam;
	m_strName = L"CronosBG";
	m_pImage = nullptr;

}

CCronosEffect::~CCronosEffect()
{
}

void CCronosEffect::Init()
{
	m_pImage = RESOURCE->LoadImg(L"CronosBG", L"Image\\UI\\CronosBG.png");
}

void CCronosEffect::Update()
{
	if (GAME->isCronos == false)
	{
		DELETEOBJECT(this);
	}
}

void CCronosEffect::Render()
{
	RENDER->Image(m_pImage, PLAYERPOSITION.x - m_pImage->GetWidth() * 0.5f, PLAYERPOSITION.y - m_pImage->GetHeight() * 0.5f, PLAYERPOSITION.x + m_pImage->GetWidth() * 0.5f, PLAYERPOSITION.y + m_pImage->GetHeight() * 0.5f);
}

void CCronosEffect::Release()
{
}
