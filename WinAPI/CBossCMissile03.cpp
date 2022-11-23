#include "framework.h"
#include "CBossCMissile03.h"

CBossCMissile03::CBossCMissile03()
{
	m_layer = Layer::EnemyMissile;
}

CBossCMissile03::~CBossCMissile03()
{
}

void CBossCMissile03::SetLundge(Vector vec)
{
	m_vecPos = vec;
}

void CBossCMissile03::AnimatorUpdate()
{
}

void CBossCMissile03::Init()
{
	AddCollider(ColliderType::Circle, Vector(30, 30), Vector(0, 0));
	m_fTimer = 1.6f;
}

void CBossCMissile03::Update()
{
	SetLundge(GAME->BossPos);

	m_fTimer -= DT;
	if (m_fTimer < 0)
	{
		DELETEOBJECT(this);
	}
}

void CBossCMissile03::Render()
{
}

void CBossCMissile03::Release()
{
}
