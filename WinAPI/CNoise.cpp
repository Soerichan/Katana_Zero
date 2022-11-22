#include "framework.h"
#include "CNoise.h"

CNoise::CNoise()
{
	m_layer = Layer::Effect;
	m_strName = L"Noise";
	m_fTimer = 1.f;
}

CNoise::~CNoise()
{
}

void CNoise::Init()
{
	m_pImage = RESOURCE->LoadImg(L"NoiseImg", L"Image\\UI\\ReplayBG2.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"NoiseAnime", m_pImage, Vector(0.f, 0.f), Vector(3500.f, 2000.f), Vector(100.f, 0.f), 0.03f, 5,true);
	m_pAnimator->Play(L"NoiseAnime", true);
	AddComponent(m_pAnimator);
}

void CNoise::Update()
{
	AnimatorUpdate();
	if (GAME->isReplay == false)
	{
		DELETEOBJECT(this);
	}
}

void CNoise::Render()
{
}

void CNoise::Release()
{
}

void CNoise::AnimatorUpdate()
{
	wstring str = L"NoiseAnime";
	m_pAnimator->Play(str, false);
}
