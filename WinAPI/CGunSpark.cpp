#include "framework.h"
#include "CGunSpark.h"

CGunSpark::CGunSpark()
{
	m_layer = Layer::Effect;
	m_strName = L"GunSpark";
	m_fTimer = 0.8f;
}

CGunSpark::~CGunSpark()
{
}

void CGunSpark::SetxDir(bool xDir)
{
	m_bToRight = xDir;
}

void CGunSpark::Init()
{
	m_pImage = RESOURCE->LoadImg(L"GunSpark", L"Image\\EFFECT\\GUNSPARK.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"GunSparkToRight", m_pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"GunSparkToLeft", m_pImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);

	if (m_bToRight)
	{
		m_pAnimator->Play(L"GunSparkToRight", true);
	}
	else
	{
		m_pAnimator->Play(L"GunSparkToLeft", true);
		
	}


	AddComponent(m_pAnimator);
}

void CGunSpark::Update()
{
	AnimatorUpdate();
	m_fTimer -= DT;
	if (m_fTimer <= 0)
	{
		DELETEOBJECT(this);
	}
}

void CGunSpark::Render()
{
}

void CGunSpark::Release()
{
}

void CGunSpark::AnimatorUpdate()
{
	wstring str = L"GunSpark";

	if (m_bToRight)
	{
		str += L"ToRight";
	}
	else
	{
		str += L"ToLeft";
	}
	m_pAnimator->Play(str, false);
}
