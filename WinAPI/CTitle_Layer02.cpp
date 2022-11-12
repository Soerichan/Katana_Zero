#include "framework.h"
#include "CTitle_Layer02.h"

CTitle_Layer02::CTitle_Layer02()
{
	m_layer = Layer::Player;
	m_strName = L"Title_Layer02";
}

CTitle_Layer02::~CTitle_Layer02()
{
}

void CTitle_Layer02::Init()
{
	m_pImage = RESOURCE->LoadImg(L"O", L"Image\\O3.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"O", m_pImage, Vector(0.f, 0.f), Vector(149.f, 209.f), Vector(149.f, 0.f), 0.1f, 11);
	m_pAnimator->Play(L"O", true);
	AddComponent(m_pAnimator);
}

void CTitle_Layer02::Update()
{
	AnimatorUpdate();
}

void CTitle_Layer02::Render()
{
}

void CTitle_Layer02::Release()
{
}

void CTitle_Layer02::AnimatorUpdate()
{
	wstring str = L"O";
	m_pAnimator->Play(str, false);
}
