#include "framework.h"
#include "CKatanaSlash.h"
#include "CBulletReflect.h"
#include"CBullet.h"



CKatanaSlash::CKatanaSlash()
{
	m_layer = Layer::Missile;
	m_strName = L"KatanaSlash";
	m_pTimer = 0;
	m_fDegree = 0;
	m_bBulletReflectChance = true;

}

CKatanaSlash::~CKatanaSlash()
{
}

void CKatanaSlash::Init()
{	
	

	m_pImage = RESOURCE->LoadImg(L"KatanaSlash", L"Image\\KatanaSlash.png");
	m_pSound = RESOURCE->LoadSound(L"MetalCollisionSound", L"Sound\\MetalCollision.wav");
	
	

	m_pAnimator = new CAnimator;

	
	m_pAnimator->CreateAnimation(L"KatanaSlashRight", m_pImage, Vector(0.f, 0.f), Vector(212.f, 64.f), Vector(400.f, 0.f), 0.07f, 5,false);
	m_pAnimator->CreateAnimation(L"KatanaSlashLeft", m_pImage, Vector(0.f, 200.f), Vector(212.f, 64.f), Vector(400.f, 0.f), 0.07f, 5,false);
	
	
	
	if (GAME->RightAttack == true)
	{
		m_pAnimator->Play(L"KatanaSlashRight", true);
	}
	else
	{
		m_pAnimator->Play(L"KatanaSlashLeft", true);
	}

	AddComponent(m_pAnimator);
	m_pTimer = 0.35f;
	AddCollider(ColliderType::Rect, Vector(250, 100), Vector(0, 0));

}

void CKatanaSlash::Update()
{
	AnimatorUpdate();
	m_pTimer -= DT;
	if (m_pTimer <= 0)
	{
		DELETEOBJECT(this);
	}
}

void CKatanaSlash::Render()
{
}

void CKatanaSlash::Release()
{
}

void CKatanaSlash::AnimatorUpdate()
{
	wstring str = L"KatanaSlash";
	
	if (GAME->RightAttack == true)
	{
		str += L"Right";
	}
	else
	{
		str += L"Left";
	}
	m_pAnimator->Play(str, false);
}

void CKatanaSlash::OnCollisionEnter(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();

	if (pTarget == L"Bullet"&& m_bBulletReflectChance)
	{
		CBulletReflect* pBulletReflect = new CBulletReflect;
		pBulletReflect->SetPos(m_vecPos.x, PLAYERPOSITION.y-15);
		ADDOBJECT(pBulletReflect);

		CBullet* pBullet = new CBullet;
		pBullet->SetPos(m_vecPos.x, PLAYERPOSITION.y - 15);
		pBullet->SetxDir(GAME->RightAttack);
		pBullet->SetLayer(Layer::Missile);
		ADDOBJECT(pBullet);

		m_bBulletReflectChance = false;
		
		SOUND->Play(m_pSound, 0.6f);
	}

	
}
