#include "framework.h"
#include "CBossCMissile02.h"

CBossCMissile02::CBossCMissile02()
{
	m_layer = Layer::EnemyMissile;
}

CBossCMissile02::~CBossCMissile02()
{
}

void CBossCMissile02::AnimatorUpdate()
{
}

void CBossCMissile02::Init()
{
	m_strName = L"Axe2";
	m_vecScale = Vector(26, 80);
	m_pImage = RESOURCE->LoadImg(L"AxeJump", L"Image\\Boss\\spr_kissyface_axe_0.png");
	m_fTimer = 4.f;
	accel = 100;
	velocity = 100;
	AddCollider(ColliderType::Circle, Vector(50, 50), Vector(0, 0));
}

void CBossCMissile02::Update()
{	

	m_vecPos.x += 30 * DT;
	m_vecPos.y = (sqrt(100 - (m_vecPos.x - GAME->BossPos.x) * (m_vecPos.x - GAME->BossPos.x)) + GAME->BossPos.y)*DT;

	m_fTimer -= DT;
	m_fDegree += 700 * DT;

	if (m_fTimer <= 0)
	{
		DELETEOBJECT(this);
	}
}

void CBossCMissile02::Render()
{
}

void CBossCMissile02::Release()
{
}
