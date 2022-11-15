#include "framework.h"
#include "CBluntEffect.h"

CBluntEffect::CBluntEffect()
{
	m_layer = Layer::Effect;
	m_strName = L"BluntEffect";
	m_fTimer = 0.7f;
}

CBluntEffect::~CBluntEffect()
{
}

void CBluntEffect::Init()
{
	m_pImage = RESOURCE->LoadImg(L"BluntEffect", L"Image\\EFFECT\\BLUNTEFFECT.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"BluntEffectLeft", m_pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 7);
	m_pAnimator->CreateAnimation(L"BluntEffectRight", m_pImage, Vector(300.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 7);

	if (GAME->RightAttack)
	{
		m_pAnimator->Play(L"BluntEffectLeft", true);
	}
	else
	{
		m_pAnimator->Play(L"BluntEffectRight", true);
	}
	

	AddComponent(m_pAnimator);
}

void CBluntEffect::Update()
{
	AnimatorUpdate();
	m_fTimer -= DT;
	if (m_fTimer <= 0)
	{
		DELETEOBJECT(this);
	}
}

void CBluntEffect::Render()
{
}

void CBluntEffect::Release()
{
}

void CBluntEffect::AnimatorUpdate()
{
	wstring str = L"BluntEffect";

	if (GAME->RightAttack)
	{
		str += L"Left";
	}
	else
	{
		str += L"Right";
	}
	m_pAnimator->Play(str, false);
}
