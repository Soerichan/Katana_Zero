#include "framework.h"
#include "CGruntSlash.h"

CGruntSlash::CGruntSlash()
{
	m_layer = Layer::EnemyMissile;
	m_strName = L"GruntSlash";
	m_pTimer = 0;
	m_fDegree = 0;
}

CGruntSlash::~CGruntSlash()
{
}

void CGruntSlash::SetDir(bool Dir)
{
	m_bRight = Dir;
}

void CGruntSlash::Init()
{
	m_pImage = RESOURCE->LoadImg(L"GruntSlash", L"Image\\Grunt\\slash\\SLASH.png");



	m_pAnimator = new CAnimator;


	m_pAnimator->CreateAnimation(L"GruntSlashRight", m_pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);
	m_pAnimator->CreateAnimation(L"GruntSlashLeft", m_pImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);



	if (m_bRight == true)
	{
		m_pAnimator->Play(L"GruntSlashRight", true);
	}
	else
	{
		m_pAnimator->Play(L"GruntSlashLeft", true);
	}

	AddComponent(m_pAnimator);
	m_pTimer = 0.35f;
	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 0));
}

void CGruntSlash::Update()
{
	AnimatorUpdate();
	m_pTimer -= DT;
	if (m_pTimer <= 0)
	{
		DELETEOBJECT(this);
	}
}

void CGruntSlash::Render()
{
}

void CGruntSlash::Release()
{
}

void CGruntSlash::AnimatorUpdate()
{
	wstring str = L"GruntSlash";

	if (m_bRight==true)
	{
		str += L"Right";
	}
	else
	{
		str += L"Left";
	}
	m_pAnimator->Play(str, false);
}

void CGruntSlash::OnCollisionEnter(CCollider* pOtherCollider)
{
}
