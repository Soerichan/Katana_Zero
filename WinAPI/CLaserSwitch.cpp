#include "framework.h"
#include "CLaserSwitch.h"

CLaserSwitch::CLaserSwitch()
{
	m_layer = Layer::Effect;
	m_strName = L"LaserSwitch";
	m_bOff = false;
}

CLaserSwitch::~CLaserSwitch()
{
}

void CLaserSwitch::AnimatorUpdate()
{
	wstring str = L"LaserSwitch";

	if (m_bRight)
	{
		str += L"Right";
	}
	else
	{
		str += L"Left";
	}

	if (m_bOff)
	{
		str += L"Off";
	}
	else
	{
		str += L"On";
	}


	if (m_bCanHandle)
	{
		str += L"CanHandle";
	}

	m_pAnimator->Play(str, false);
}

void CLaserSwitch::Init()
{
	m_pImage= RESOURCE->LoadImg(L"LaserSwitch", L"Image\\Laser\\LaserSwitch01.png");
	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"LaserSwitchRightOff", m_pImage, Vector(0.f, 0.f), Vector(100.f, 100.f), Vector(150.f, 0.f), 0.1f, 1,false);
	m_pAnimator->CreateAnimation(L"LaserSwitchRightOn", m_pImage, Vector(600.f, 0.f), Vector(100.f, 100.f), Vector(150.f, 0.f), 0.1f, 1,false);
	m_pAnimator->CreateAnimation(L"LaserSwitchRightOffCanHandle", m_pImage, Vector(150.f, 0.f), Vector(100.f, 100.f), Vector(150.f, 0.f), 1.f, 2);
	m_pAnimator->CreateAnimation(L"LaserSwitchRightOnCanHandle", m_pImage, Vector(750.f, 0.f), Vector(100.f, 100.f), Vector(150.f, 0.f), 1.f, 2);
	m_pAnimator->CreateAnimation(L"LaserSwitchLeftOff", m_pImage, Vector(0.f, 150.f), Vector(100.f, 100.f), Vector(150.f, 0.f), 0.1f, 1,false);
	m_pAnimator->CreateAnimation(L"LaserSwitchLeftOn", m_pImage, Vector(600.f, 150.f), Vector(100.f, 100.f), Vector(150.f, 0.f), 0.1f, 1,false);
	m_pAnimator->CreateAnimation(L"LaserSwitchLeftOffCanHandle", m_pImage, Vector(150.f, 150.f), Vector(100.f, 100.f), Vector(150.f, 0.f), 1.f, 2);
	m_pAnimator->CreateAnimation(L"LaserSwitchLeftOnCanHandle", m_pImage, Vector(750.f, 150.f), Vector(100.f, 100.f), Vector(150.f, 0.f), 1.f, 2);

	m_pAnimator->Play(L"LaserSwitchLeftOn", true);
	AddComponent(m_pAnimator);

	m_pLaserSound = RESOURCE->LoadSound(L"LaserOffSound", L"Sound\\LaserOff.wav");
	
}

void CLaserSwitch::Update()
{
	AnimatorUpdate();

	m_vecDistance = PLAYERPOSITION - m_vecPos;
	m_fDistance = m_vecDistance.Length();

	if (m_fDistance < 100.f)
	{
		m_bCanHandle = true;
	}
	else
	{
		m_bCanHandle = false;
	}

	if (BUTTONDOWN(VK_SPACE) && m_bCanHandle)
	{
		if (m_State == state::Off)
		{
			m_State = state::On;
			m_bOff = false;
			GAME->LaserOff = false;
		}
		else
		{
			m_State = state::Off;
			m_bOff = true;
			GAME->LaserOff = true;
			SOUND->Play(m_pLaserSound, 0.6f);
		}
	}
}

void CLaserSwitch::Render()
{
}

void CLaserSwitch::Release()
{
}
