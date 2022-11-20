#include "framework.h"
#include "CBossMissile01.h"

CBossMissile01::CBossMissile01()
{
}

CBossMissile01::~CBossMissile01()
{
}

void CBossMissile01::AnimatorUpdate()
{
}

void CBossMissile01::Init()
{
	m_layer = Layer::EnemyMissile;
	m_strName = L"Axe";
	m_vecScale = Vector(26, 80);
	m_pImage= RESOURCE->LoadImg(L"BossWalk", L"Image\\Boss\\spr_kissyface_axe_0.png");
	m_fTimer = 1.f;
	accel = 100;
	velocity = 100;
}

void CBossMissile01::Update()
{

}

void CBossMissile01::Render()
{
}

void CBossMissile01::Release()
{
}
