#include "framework.h"
#include "CSpark.h"

CSpark::CSpark()
{
	m_layer = Layer::Cursor;
	m_strName = L"Spark";
	m_fTimer = 0.8f;
}

CSpark::~CSpark()
{
}

void CSpark::SetxDir(bool xDir)
{
	m_bToRight = xDir;
}

void CSpark::Init()
{
	m_pImage = RESOURCE->LoadImg(L"Spark", L"Image\\EFFECT\\SPARK.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"SparkToRight", m_pImage, Vector(300.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"SparkToLeft", m_pImage, Vector(300.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);

	if (m_bToRight)
	{
		m_pAnimator->Play(L"SparkToRight", true);
	}
	else
	{
		m_pAnimator->Play(L"SparkToLeft", true);

	}


	AddComponent(m_pAnimator);
}

void CSpark::Update()
{
	AnimatorUpdate();
	m_fTimer -= TIME->GetRealTime();
	if (m_fTimer <= 0)
	{
		DELETEOBJECT(this);
	}
}

void CSpark::Render()
{
}

void CSpark::Release()
{
}

void CSpark::AnimatorUpdate()
{
	wstring str = L"Spark";

	if (m_bToRight)
	{
		str += L"ToRight";
	}
	else
	{
		str += L"ToLeft";
	}
	m_pAnimator->Play(str, false);
}
