#include "framework.h"
#include "CAnimation.h"

#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CAnimator.h"
#include "CGameObject.h"

CAnimation::CAnimation()
{
	m_pAnimator = nullptr;

	m_strName = L"";
	m_pImage = nullptr;
	m_iCurFrame = 0;
	m_fAccTime = 0;
	m_bRepeat = true;
	
}

CAnimation::~CAnimation()
{
}

UINT CAnimation::GetCurFrame()
{
	return this->m_iCurFrame;
}

void CAnimation::SetCurFrame(UINT Frame)
{
	m_iCurFrame = Frame;
}

const wstring& CAnimation::GetName()
{
	return m_strName;
}

void CAnimation::SetName(const wstring& name)
{
	m_strName = name;
}

void CAnimation::Create(CImage* pImg, Vector lt, Vector slice, Vector step, float duration, UINT count, bool repeat,float dgree)
{
	m_pImage = pImg;	// 프레임 이미지가 모여있는 이미지 파일
	m_bRepeat = repeat;	// 반복여부

	// 바둑판식 프레임 이미지를 가리킬 위치를 저장
	// lt		: 프레임 이미지의 좌측상단 좌표
	// step		: 프레임 이미지의 간격
	// slice	: 프레임 이미지의 크기
	// duration : 프레임 이미지의 지속시간
	//dgree: 회전각도 0~360
	AniFrame frame;
	frame.dgree = dgree;
	for (UINT i = 0; i < count; i++)
	{
		frame.lt = lt + step * i;
		frame.slice = slice;
		frame.duration = duration;

		m_vecFrame.push_back(frame);
	}
}

void CAnimation::Create2(CImage* pImg, Vector lt, Vector slice, Vector step, float duration, UINT count, UINT floor, UINT floorcount, bool repeat)
{
	m_pImage = pImg;	// 프레임 이미지가 모여있는 이미지 파일
	m_bRepeat = repeat;	// 반복여부

	// 바둑판식 프레임 이미지를 가리킬 위치를 저장
	// lt		: 프레임 이미지의 좌측상단 좌표
	// step		: 프레임 이미지의 간격
	// slice	: 프레임 이미지의 크기
	// duration : 프레임 이미지의 지속시간
	AniFrame frame;
	for (UINT A = 0; A < floor; A++)
	{


		for (UINT i = 0; i < floorcount; i++)
		{
			frame.lt.x = lt.x + step.x * i;
			frame.lt.y = lt.y + step.y * i+(slice.y*A);
			frame.slice = slice;
			frame.duration = duration;

			m_vecFrame.push_back(frame);
		}


	}

	
}

void CAnimation::Replay()
{
	// 애니메이션 재시작 : 현재 프레임과 누적시간을 초기화
	m_iCurFrame = 0;
	m_fAccTime = 0;
}

void CAnimation::Init()
{
}

void CAnimation::Update()
{
	// 현재 플레이중인 프레임의 누적시간
	m_fAccTime += DT;

	// 누적시간이 현재 플레이중인 프레임의 지속시간보다 커졌을 경우
	// -> 다음 프레임을 보여줘야 하는 경우
	if (m_vecFrame[m_iCurFrame].duration < m_fAccTime)
	{
		m_iCurFrame++;	// 현재 플레이중인 프레임의 인덱스를 하나 증가
		m_fAccTime = 0;	// 현재 플레이중인 프레임의 누적시간 초기화

		// 만약 플레이중인 프레임이 마지막 프레임이었을 경우
		if (m_iCurFrame == m_vecFrame.size())
		{
			// 반복 애니메이션이라면 처음부터, 아니라면 마지막을 다시 재생
			if (m_bRepeat)	m_iCurFrame = 0;
			else			m_iCurFrame--;
		}
	}
}

void CAnimation::Render()
{
	Vector pos = m_pAnimator->GetOwner()->GetPos();	// 애니메이션이 그려질 위치 확인
	float angle = m_pAnimator->GetOwner()->GetAngle();	// 애니메이션이 그려질 위치 확인
	AniFrame frame = m_vecFrame[m_iCurFrame];		// 애니메이션이 그려질 프레임 확인

	Vector screen = CAMERA->WorldToScreenPoint(pos);

	// 프레임 이미지 그리기
	RENDER->FrameImage(
		m_pImage,
		pos.x - frame.slice.x * 0.5f,
		pos.y - frame.slice.y * 0.5f,
		pos.x + frame.slice.x * 0.5f,
		pos.y + frame.slice.y * 0.5f,
		frame.lt.x,
		frame.lt.y,
		frame.lt.x + frame.slice.x,
		frame.lt.y + frame.slice.y,
		1,
		angle
	);
}

void CAnimation::Release()
{
}
