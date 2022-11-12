#include "framework.h"
#include "CTitle_Layer01.h"

CTitle_Layer01::CTitle_Layer01()
{
	m_layer = Layer::Player;
	m_strName = L"Title_Layer01";
}

CTitle_Layer01::~CTitle_Layer01()
{
}

void CTitle_Layer01::Init()
{
	m_pImage= RESOURCE->LoadImg(L"ZER", L"Image\\ZER6.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"ZER", m_pImage, Vector(0.f, 0.f), Vector(355.f, 206.f), Vector(355.f, 0.f), 0.01f, 5);
	m_pAnimator->Play(L"ZER", true);
	AddComponent(m_pAnimator);
}

void CTitle_Layer01::Update()
{
	AnimatorUpdate();
}

void CTitle_Layer01::Render()
{
}

void CTitle_Layer01::Release()
{
}

void CTitle_Layer01::AnimatorUpdate()
{
	wstring str = L"ZER";
	m_pAnimator->Play(str, false);
}
