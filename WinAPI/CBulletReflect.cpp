#include "framework.h"
#include "CBulletReflect.h"

CBulletReflect::CBulletReflect()
{
	m_layer = Layer::Effect;
	m_strName = L"BulletReflect";
	m_fTimer = 0.5f;
}

CBulletReflect::~CBulletReflect()
{
}

void CBulletReflect::Init()
{
	m_pImage = RESOURCE->LoadImg(L"BulletReflect", L"Image\\EFFECT\\BULLETREFLECT.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"BulletReflectLeft", m_pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 5);
	m_pAnimator->CreateAnimation(L"BulletReflectRight", m_pImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 5);

	if (GAME->RightAttack)
	{
		m_pAnimator->Play(L"BulletReflectLeft", true);
	}
	else
	{
		m_pAnimator->Play(L"BulletReflectRight", true);
	}


	AddComponent(m_pAnimator);
}

void CBulletReflect::Update()
{
	AnimatorUpdate();
	m_fTimer -= DT;
	if (m_fTimer <= 0)
	{
		DELETEOBJECT(this);
	}
}

void CBulletReflect::Render()
{
}

void CBulletReflect::Release()
{
}

void CBulletReflect::AnimatorUpdate()
{
	wstring str = L"BulletReflect";

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
