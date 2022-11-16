#include "framework.h"
#include "CBullet.h"

CBullet::CBullet()
{
	m_layer = Layer::EnemyMissile;
	m_strName = L"Bullet";
	m_pTimer = 0;
	m_fDegree = 0;
}

CBullet::~CBullet()
{
}

void CBullet::SetxDir(bool Dir)
{
	m_bRight = Dir;
}

void CBullet::Init()
{
	m_pImage = RESOURCE->LoadImg(L"Bullet", L"Image\\spr_bullet_0.png");



	m_pAnimator = new CAnimator;


	m_pAnimator->CreateAnimation(L"Bullet", m_pImage, Vector(0.f, 0.f), Vector(15.f, 2.f), Vector(300.f, 0.f), 10.f, 1, false);
	





	AddComponent(m_pAnimator);
	m_pTimer = 10.f;
	m_pAnimator->Play(L"Bullet", true);
	AddCollider(ColliderType::Rect, Vector(10, 10), Vector(0, 0));
}

void CBullet::Update()
{
	AnimatorUpdate();
	m_pTimer -= DT;
	if (m_pTimer <= 0)
	{
		DELETEOBJECT(this);
	}

	if (m_bRight)
	{
		m_vecPos.x += 100 * m_pTimer* DT;
	}
	else
	{
		m_vecPos.x -= 100 * m_pTimer* DT;
	}
}

void CBullet::Render()
{
}

void CBullet::Release()
{
}

void CBullet::AnimatorUpdate()
{
	wstring str = L"Bullet";
	m_pAnimator->Play(str, false);
}

void CBullet::OnCollisionEnter(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();

	//if (pTarget == L"KatanaSlash"||)
	//{
		DELETEOBJECT(this);
	//}
}
