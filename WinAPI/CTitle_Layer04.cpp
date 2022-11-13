#include "framework.h"
#include "CTitle_Layer04.h"

CTitle_Layer04::CTitle_Layer04()
{
	m_layer = Layer::Cursor;
	m_strName = L"Title_Layer04";
	
}

CTitle_Layer04::~CTitle_Layer04()
{
}

void CTitle_Layer04::Init()
{
	m_pImage = RESOURCE->LoadImg(L"KATANA", L"Image\\KATANA.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"KATANA", m_pImage, Vector(0.f, 0.f), Vector(340.f, 222.f), Vector(340.f, 0.f), 100.f,1,false);
	m_pAnimator->Play(L"KATANA", true);
	AddComponent(m_pAnimator);
}

void CTitle_Layer04::Update()
{
	AnimatorUpdate();
}

void CTitle_Layer04::Render()
{

}

void CTitle_Layer04::Release()
{
}

void CTitle_Layer04::AnimatorUpdate()
{
	wstring str = L"KATANA";
	m_pAnimator->Play(str, false);
}

