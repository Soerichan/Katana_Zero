#include "framework.h"
#include "CZippo.h"

CZippo::CZippo()
{
	m_layer = Layer::Effect;
	m_strName = L"BluntEffect";
	m_fTimer = 1.f;
}

CZippo::~CZippo()
{
}

void CZippo::Init()
{
	m_pImage = RESOURCE->LoadImg(L"ZIPPO", L"Image\\jobfolder\\ZIPPO.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"ZIPPO", m_pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.2f, 15,false);
	//m_pAnimator->CreateAnimation(L"BluntEffectRight", m_pImage, Vector(300.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 7);
	m_pAnimator->Play(L"ZIPPO", true);
	/*if (GAME->RightAttack)
	{
		
	}
	else
	{
		m_pAnimator->Play(L"BluntEffectRight", true);
	}*/


	AddComponent(m_pAnimator);
}

void CZippo::Update()
{
	AnimatorUpdate();
}

void CZippo::Render()
{
}

void CZippo::Release()
{
}

void CZippo::AnimatorUpdate()
{
	wstring str = L"ZIPPO";


	m_pAnimator->Play(str, false);
}
