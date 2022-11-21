#pragma once

class CAnimator;
class CImage;

struct AniFrame
{
	Vector	lt;
	Vector	slice;
	float	duration;
	float dgree;
};

class CAnimation
{
	friend CAnimator;
public:
	CAnimation();
	virtual ~CAnimation();

	UINT GetCurFrame();
	void SetCurFrame(UINT Frame);
private:
	CAnimator*			m_pAnimator;	// �ִϸ�����

	wstring				m_strName;		// �ִϸ��̼� �̸�
	CImage*				m_pImage;		// �ִϸ��̼� �̹���
	vector<AniFrame>	m_vecFrame;		// �ִϸ��̼��� ������ ������
	UINT				m_iCurFrame;	// ���� �÷������� �������� �ε���
	float				m_fAccTime;		// ���� �÷������� �������� �����ð�
	bool				m_bRepeat;		// �ִϸ��̼��� �ݺ� ����

	

public:
	const wstring& GetName();
	
private:
	void SetName(const wstring& name);

	void Create(CImage* pImg, Vector lt, Vector slice, Vector step, float duration, UINT count, bool repeat,float dgree=0);	// �ִϸ��̼� ����
	void Create2(CImage* pImg, Vector lt, Vector slice, Vector step, float duration, UINT count, UINT floor, UINT floorcount, bool repeat);	// �ִϸ��̼� ����2
	void Replay();	// �ִϸ��̼� ó������ �ٽ� ����

private:
	void Init();
	void Update();
	void Render();
	void Release();
};
