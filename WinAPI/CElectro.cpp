#include "framework.h"
#include "CElectro.h"

CElectro::CElectro()
{
	m_layer = Layer::Monster;
	m_strName = L"Electro";
	m_fTimer = 3.0f;
}

CElectro::~CElectro()
{
}

void CElectro::Init()
{
	m_pImage = RESOURCE->LoadImg(L"ElectroImg", L"Image\\Electro.png");
	m_pImage2 = RESOURCE->LoadImg(L"Electro2Img", L"Image\\Electro2.png");
	m_pSound= RESOURCE->LoadSound(L"ElectroSound", L"Sound\\Kill.wav");



	m_pAnimator = new CAnimator;


	m_pAnimator->CreateAnimation(L"Electro", m_pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 15,false);
	m_pAnimator->CreateAnimation(L"Electro2", m_pImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 12,false);
	m_pAnimator->CreateAnimation(L"Electro23", m_pImage, Vector(1800.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 6,true);
	m_pAnimator->CreateAnimation(L"Electro23Die", m_pImage2, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 7,false);





	m_pAnimator->Play(L"Electro", true);


	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 0));
}

void CElectro::Update()
{
	AnimatorUpdate();

	m_fTimer -= DT;
	if (m_fTimer <= 1.5f&&m_b1phase==false)
	{
		m_b1phase = true;

	}
	

	if (m_fTimer <= 0.f && m_b2phase == false)
	{
		m_b2phase = true;
		m_vecPos.x -= 10 * DT;
		AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 0));
	}

	if (m_vecPos.x > 200)
	{
		m_vecPos.x -= 10 * DT;
	}
	
}

void CElectro::Render()
{
}

void CElectro::Release()
{
}

void CElectro::OnCollisionEnter(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();

	if (pTarget == L"Laser" || pOtherCollider->GetOwner()->GetLayer() == Layer::Missile)
	{
		
			SOUND->Play(m_pSound, 1.f);
			
			Die = true;
			GAME->m_iDeadMonster++;
		
	}
}

void CElectro::AnimatorUpdate()
{
	wstring str = L"Electro";

	if (m_b1phase)
	{
		str += L"2";
	}

	if (m_b2phase)
	{
		str += L"3";
	}

	if (Die)
	{
		str += L"Die";
	}
	m_pAnimator->Play(str, false);
}
