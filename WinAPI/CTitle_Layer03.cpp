#include "framework.h"
#include "CTitle_Layer03.h"

CTitle_Layer03::CTitle_Layer03()
{
	m_layer = Layer::Player;
	m_strName = L"Title_Layer03";
}

CTitle_Layer03::~CTitle_Layer03()
{
}

void CTitle_Layer03::Init()
{
	/*m_pImageGRASS01 = RESOURCE->LoadImg(L"GRASS01", L"Image\\GRASS01.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"GRASS01", m_pImage, Vector(0.f, 0.f), Vector(1280.f, 510.f), Vector(1280.f, 0.f), 0.1f, 3);
	m_pAnimator->Play(L"GRASS01", true);

	m_pImageGRASS01 = RESOURCE->LoadImg(L"GRASS02", L"Image\\GRASS02.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"GRASS02", m_pImage, Vector(0.f, 0.f), Vector(1280.f, 510.f), Vector(1280.f, 0.f), 0.1f, 3);
	m_pAnimator->Play(L"GRASS02", true);

	m_pImageGRASS01 = RESOURCE->LoadImg(L"GRASS03", L"Image\\GRASS03.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"GRASS03", m_pImage, Vector(0.f, 0.f), Vector(1280.f, 510.f), Vector(1280.f, 0.f), 0.1f, 3);
	m_pAnimator->Play(L"GRASS03", true);

	m_pImageGRASS01 = RESOURCE->LoadImg(L"GRASS04", L"Image\\GRASS04.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"GRASS04", m_pImage, Vector(0.f, 0.f), Vector(1280.f, 510.f), Vector(1280.f, 0.f), 0.1f, 3);
	m_pAnimator->Play(L"GRASS04", true);*/

	m_pImage = RESOURCE->LoadImg(L"GRASS", L"Image\\GRASS.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation2(L"GRASS", m_pImage, Vector(0.f, 0.f), Vector(1280.f, 510.f), Vector(1280.f, 0.f), 0.1f, 4,3, 3);
	m_pAnimator->Play(L"GRASS", true);



	AddComponent(m_pAnimator);
}

void CTitle_Layer03::Update()
{
	AnimatorUpdate();
}

void CTitle_Layer03::Render()
{
}

void CTitle_Layer03::Release()
{
}

void CTitle_Layer03::AnimatorUpdate()
{
	wstring str = L"GRASS";
	m_pAnimator->Play(str, false);
}
