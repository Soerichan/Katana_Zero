#include "framework.h"
#include "CSmokePipe.h"
#include "CSmoke.h"

CSmokePipe::CSmokePipe()
{
	m_layer = Layer::Monster;
	m_strName = L"Pipe";
	m_fTimer = 0.1f;
}

CSmokePipe::~CSmokePipe()
{
}

void CSmokePipe::Init()
{
	pImage = RESOURCE->LoadImg(L"Pipe", L"Image\\Smoke\\Pipe.png");
	m_pAnimator = new CAnimator;
	
	m_pAnimator->CreateAnimation(L"Pipe", pImage, Vector(300.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.2f, 1, false);

	m_pAnimator->CreateAnimation(L"PipeCrushed", pImage, Vector(450.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.2f, 1, false);

	m_pAnimator->Play(L"Pipe", true);


	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 0));
}

void CSmokePipe::Update()
{
	AnimatorUpdate();

	//if (m_bCrushed)
	//{
	//	m_fTimer -= DT;

	//	if (m_fTimer <= 0)
	//	{
	//		CSmoke* pSmoke1 = new CSmoke;
	//		pSmoke1->SetPos(m_vecPos.x - 200, m_vecPos.y + 100);
	//		ADDOBJECT(pSmoke1);
	//		CSmoke* pSmoke1 = new CSmoke;
	//		pSmoke1->SetPos(m_vecPos.x, m_vecPos.y + 150);
	//		ADDOBJECT(pSmoke1);
	//		CSmoke* pSmoke1 = new CSmoke;
	//		pSmoke1->SetPos(m_vecPos.x + 200, m_vecPos.y + 100);
	//		ADDOBJECT(pSmoke1);
	//	}
	//}
}

void CSmokePipe::Render()
{
}

void CSmokePipe::Release()
{
}

void CSmokePipe::AnimatorUpdate()
{
	wstring str = L"Pipe";

	if (m_bCrushed)
	{
		str += L"Crushed";
	}
	m_pAnimator->Play(str, false);
}

void CSmokePipe::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetOwner()->GetLayer() == Layer::Missile)
	{
		m_bCrushed = true;
		CSmoke* pSmoke1 = new CSmoke;
		pSmoke1->SetPos(m_vecPos.x - 200, m_vecPos.y + 100);
		ADDOBJECT(pSmoke1);
		CSmoke* pSmoke2 = new CSmoke;
		pSmoke2->SetPos(m_vecPos.x, m_vecPos.y + 150);
		ADDOBJECT(pSmoke2);
		CSmoke* pSmoke3 = new CSmoke;
		pSmoke3->SetPos(m_vecPos.x + 200, m_vecPos.y + 100);
		ADDOBJECT(pSmoke3);
	}
}

void CSmokePipe::OnCollisionStay(CCollider* pOtherCollider)
{
	
}

void CSmokePipe::OnCollisionExit(CCollider* pOtherCollider)
{
}
