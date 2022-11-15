#include "framework.h"
#include "CPompSlash.h"

CPompSlash::CPompSlash()
{
	m_layer = Layer::EnemyMissile;
	m_strName = L"PompSlash";
	m_pTimer = 0;
	m_fDegree = 0;
}

CPompSlash::~CPompSlash()
{
}

void CPompSlash::SetDir(bool Dir)
{
	m_bRight = Dir;
}

void CPompSlash::Init()
{
	m_pImage = RESOURCE->LoadImg(L"PompSlash", L"Image\\Pomp\\SLASH\\SLASH.png");



	m_pAnimator = new CAnimator;


	m_pAnimator->CreateAnimation(L"PompSlashRight", m_pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);
	m_pAnimator->CreateAnimation(L"PompSlashLeft", m_pImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);



	if (m_bRight == true)
	{
		m_pAnimator->Play(L"PompSlashRight", true);
	}
	else
	{
		m_pAnimator->Play(L"PompSlashLeft", true);
	}

	AddComponent(m_pAnimator);
	m_pTimer = 0.35f;
	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 0));
}

void CPompSlash::Update()
{
	AnimatorUpdate();
	m_pTimer -= DT;
	if (m_pTimer <= 0)
	{
		DELETEOBJECT(this);
	}
}

void CPompSlash::Render()
{
}

void CPompSlash::Release()
{
}

void CPompSlash::AnimatorUpdate()
{
	wstring str = L"PompSlash";

	if (m_bRight == true)
	{
		str += L"Right";
	}
	else
	{
		str += L"Left";
	}
	m_pAnimator->Play(str, false);
}

void CPompSlash::OnCollisionEnter(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();

	if (pTarget == L"KatanaSlash")
	{
		DELETEOBJECT(this);
	}
}
