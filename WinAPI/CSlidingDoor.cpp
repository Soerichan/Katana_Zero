#include "framework.h"
#include "CSlidingDoor.h"

CSlidingDoor::CSlidingDoor()
{
	m_layer = Layer::Cam;
	m_strName = L"Wall";
	m_fTimer = 0.01f;
}

CSlidingDoor::~CSlidingDoor()
{
}

void CSlidingDoor::Init()
{
	pImage = RESOURCE->LoadImg(L"SD", L"Image\\cam\\SlidingDoor.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"GreenSD", pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8, false);
	m_pAnimator->CreateAnimation(L"RedSD", pImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 5, false);

	m_pAnimator->Play(L"GreenSD", true);


	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(30, 200), Vector(0, 0));
}

void CSlidingDoor::Update()
{
	AnimatorUpdate();

	if (GAME->CamRed)
	{
		m_bRed = true;
		m_fTimer = 0.01f;
		AddCollider(ColliderType::Rect, Vector(30, 200), Vector(0, 0));
	}
	else
	{
		m_bRed = false;
		m_fTimer -= DT;

		if(m_fTimer <= 0)
		{
			RemoveCollider();
		}
	}

}

void CSlidingDoor::Render()
{
}

void CSlidingDoor::Release()
{
}

void CSlidingDoor::AnimatorUpdate()
{
	wstring str = L"";
	if (GAME->CamRed)
	{
		str += L"Red";
	}
	else
	{
		str += L"Green";
	}
	str += L"SD";
	m_pAnimator->Play(str, false);
}
