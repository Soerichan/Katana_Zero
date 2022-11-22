#include "framework.h"
#include "CNoAttack.h"

CNoAttack::CNoAttack()
{
	m_fTimer = 1.f;
	m_vecScale = { 28,28 };
	m_layer = Layer::Effect;
}

CNoAttack::~CNoAttack()
{
}

void CNoAttack::Init()
{
	m_pImage = RESOURCE->LoadImg(L"NoAttack", L"Image\\EFFECT\\noattack.png");
}

void CNoAttack::Update()
{
	m_fTimer -= DT;
	if (m_fTimer <= 0)
	{
		DELETEOBJECT(this);
	}
}

void CNoAttack::Render()
{
	RENDER->Image(m_pImage, PLAYERPOSITION.x - 14, PLAYERPOSITION.y - 54, PLAYERPOSITION.x + 14, PLAYERPOSITION.y - 26);
}

void CNoAttack::Release()
{
}
