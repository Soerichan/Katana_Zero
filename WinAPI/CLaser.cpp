#include "framework.h"
#include "CLaser.h"

CLaser::CLaser()
{
	m_layer = Layer::Laser;
	m_strName = L"Laser";
	m_vecScale = Vector(2, 200);
	m_fTimer = 0.01f;
	m_fHitTimer = 1.0f;
	m_fRemodelingTimer = 1.f;
	
}

CLaser::~CLaser()
{
}

void CLaser::SetSwitchPos(Vector pos)
{
	m_vecSwitchPos = pos;
}

void CLaser::SetRight(bool Right)
{
	m_bRight = Right;
}

void CLaser::TurnOff()
{

}

void CLaser::AnimatorUpdate()
{
	wstring str = L"Laser";

	if (m_bHit==false)
	{
		str += L"Red";
	}
	else
	{
		str += L"Yellow";
	}
	m_pAnimator->Play(str, false);
}

void CLaser::SwitchLaser()
{
	if (m_State == LaserState::On)
	{
		m_bOff = true;
		m_State = LaserState::Off;
	}
	if (m_State == LaserState::Off)
	{
		m_bOff = false;
		m_State = LaserState::On;
		
	}
}

void CLaser::SetMove(bool move)
{
	m_bMove = true;
}

void CLaser::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CLaser::Init()
{	
	m_pLaserImage = RESOURCE->LoadImg(L"Laser", L"Image\\Laser\\Laser.png");
	//m_pLaserSwitchImage = RESOURCE->LoadImg(L"Laser", L"Image\\laserSwitch.png");
	//m_pLaserSwitch2Image = RESOURCE->LoadImg(L"Laser", L"Image\\laserSwitch2.png");
	//m_pSpace1Image = RESOURCE->LoadImg(L"Laser", L"Image\\space1.png");
//	m_pSpace2Image = RESOURCE->LoadImg(L"Laser", L"Image\\space2.png");
//
	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"LaserRed", m_pLaserImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 3);
	m_pAnimator->CreateAnimation(L"LaserYellow", m_pLaserImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 3);
		
	m_pAnimator->Play(L"LaserRed", true);
	AddComponent(m_pAnimator);
	//AddCollider(ColliderType::Rect, Vector(1, 200), Vector(0, 0));
	m_fMoveTimer = 8.f;


}

void CLaser::Update()
{
	if (m_fRemodelingTimer > -1)
	{
		m_fRemodelingTimer -= DT;
	}

	if (GAME->LaserOff==false)
	{
		m_State = LaserState::On;
	}
	else
	{
		m_State = LaserState::Off;
	}

	if (m_State == LaserState::On)
	{
		if (m_bMove == true)
		{
			m_fMoveTimer -= DT;
			if (m_fMoveTimer >= 4.f)
			{
				m_vecPos.x += 90 * DT;
			}
			else if(m_fMoveTimer < 4.f&& m_fMoveTimer >= 0)
			{
				m_vecPos.x -= 90 * DT;
			}
			else
			{
				m_fMoveTimer = 8.f;
			}
		}

		if(m_fRemodelingTimer<=0)
		AddCollider(ColliderType::Rect, Vector(1, 200), Vector(0, 0));

		m_fTimer = 0.01f;
		AnimatorUpdate();
	}
	if (m_State == LaserState::Off)
	{
		m_fTimer -= DT;
		if (m_fTimer <= 0)
		{
			
			RemoveCollider();
			m_pAnimator->Stop();
		}
	}

	if (m_bHit)
	{
		m_fHitTimer -= DT;

		if (m_fHitTimer <= 0)
		{
			m_bHit = false;
			m_fHitTimer = 1.0f;
		}
	}



}

void CLaser::Render()
{

}

void CLaser::Release()
{
}
