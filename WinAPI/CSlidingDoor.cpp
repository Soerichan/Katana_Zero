#include "framework.h"
#include "CSlidingDoor.h"

CSlidingDoor::CSlidingDoor()
{
	m_layer = Layer::StageObject;
	m_strName = L"SlidingDoor";
}

CSlidingDoor::~CSlidingDoor()
{
}

void CSlidingDoor::Init()
{
	pImage = RESOURCE->LoadImg(L"SD", L"Image\\cam\\SlidingDoor.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"GreenSD", pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.2f, 3, false);
	m_pAnimator->CreateAnimation(L"RedSD", pImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.2f, 3, false);

	m_pAnimator->Play(L"GreenSD", true);


	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(30, 200), Vector(0, 0));
}

void CSlidingDoor::Update()
{
	AnimatorUpdate();

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
