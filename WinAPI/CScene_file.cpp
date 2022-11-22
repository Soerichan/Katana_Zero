#include "framework.h"
#include "CScene_file.h"
#include "CCameraController.h"
#include "CZippo.h"

CScene_file::CScene_file()
{
	m_fFireTimer = 6.5f;
}

CScene_file::~CScene_file()
{
}

void CScene_file::Init()
{
	

	pImage01 = RESOURCE->LoadImg(L"JobFolderImage03", L"Image\\jobfolder\\BG.png");
	pImage02 = RESOURCE->LoadImg(L"JobFolderImage04", L"Image\\jobfolder\\Folder01.png");
	//pImage03

	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround_file", L"Image\\JobFolder\\BG1.png"));
	AddGameObject(m_pbackGround);

	CImageObject* pJobFolderImageObject01 = new CImageObject;
	CImage* pJobFolderImage01 = new CImage;
	pJobFolderImageObject01->SetImage(pJobFolderImage01 = RESOURCE->LoadImg(L"JobFolderImage01", L"Image\\jobfolder\\BG.png"));
	pJobFolderImageObject01->SetPos(640, 360);
	pJobFolderImageObject01->SetLayer(Layer::Laser);
	pJobFolderImageObject01->SetName(L"JobFolder01");
	pJobFolderImageObject01->SetScale(1280, 720);
	AddGameObject(pJobFolderImageObject01);



	CImageObject* pJobFolderImageObject02 = new CImageObject;
	CImage* pJobFolderImage02 = new CImage;
	pJobFolderImageObject02->SetImage(pJobFolderImage02 = RESOURCE->LoadImg(L"JobFolderImage02", L"Image\\jobfolder\\Folder01.png"));
	pJobFolderImageObject02->SetPos(640, 360);
	pJobFolderImageObject02->SetLayer(Layer::Tile);
	pJobFolderImageObject02->SetName(L"JobFolder02");
	pJobFolderImageObject02->SetScale(1108, 691);
	AddGameObject(pJobFolderImageObject02);

	CCameraController* pCamController = new CCameraController;

	AddGameObject(pCamController);

	m_pPaperSound = RESOURCE->LoadSound(L"PaperSound", L"Sound\\File.wav");
	m_pFireSound = RESOURCE->LoadSound(L"FireSound", L"Sound\\FileFire.mp3");
	m_pZippoSound = RESOURCE->LoadSound(L"ZippoSound", L"Sound\\Zippo.wav");
}

void CScene_file::Enter()
{
	CAMERA->readyTimer = 1.f;

	CAMERA->FadeIn(1.f);

	SOUND->Play(m_pPaperSound, 0.5f);
	
}

void CScene_file::Update()
{
	if (BUTTONDOWN(VK_SPACE))
	{
		m_bFire = true;
		CZippo* pZippo = new CZippo;
		pZippo->SetPos(1000, 600);
		ADDOBJECT(pZippo);
		SOUND->Play(m_pZippoSound);
	}

	if (m_bFire)
	{
		m_fFireTimer -= DT;
	}

	if (m_fFireTimer>2&&m_fFireTimer <= 4.f)
	{
		if (m_bFireSound == false)
		{
			SOUND->Play(m_pFireSound, 0.1f);
			m_bFireSound = true;
		}


	}
	if (m_fFireTimer<=2.f)
	{	
		SOUND->Stop(m_pFireSound);
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Scene000, 0.25f);
	}
	CAMERA->SetTargetPos({ 640,360 });
}

void CScene_file::Render()
{
	
	if (m_fFireTimer <= 4.f)
	{
		RENDER->Image(pImage02, 0, 0, WINSIZEX, WINSIZEY);



		RENDER->FillCircle(1067, 686, 620.f * (4.f - m_fFireTimer) + 4, Color(255, 255, 250, 1.f));

		RENDER->FillCircle(1067, 686, 600.f * (4.f - m_fFireTimer) + 2, Color(255, 205, 050, 1.f));


		/*if (m_fFireTimer <= 4.5f)
		{
			RENDER->FillCircle(1017, 686, 300.f * (5.f - m_fFireTimer)+4, Color(255, 255, 250, 1.f));
			RENDER->FillCircle(207, 656, 300.f * (5.f - m_fFireTimer)+4, Color(255, 255, 250, 1.f));
			RENDER->FillCircle(1067, 636, 300.f * (5.f - m_fFireTimer)+4, Color(255, 255, 250, 1.f));
		}*/

		RENDER->FillCircle(1067, 686, 600 * (4.f - m_fFireTimer), Color(0, 0, 0, 1.f));


		//if (m_fFireTimer <= 4.5f)
		//{
		   // RENDER->FillCircle(1017, 686, 300.f * (5.f - m_fFireTimer), Color(0, 0, 0, 1.f));
		   // RENDER->FillCircle(207, 656, 300.f * (5.f - m_fFireTimer), Color(0, 0, 0, 1.f));
		   // RENDER->FillCircle(1067, 636, 300.f * (5.f - m_fFireTimer), Color(0, 0, 0, 1.f));
		//}

		RENDER->Image(pImage01, 0, 0, WINSIZEX, WINSIZEY);

	}

	if(m_bFire==false)
  RENDER->Text(L"스페이스바를 눌러 문서를 파기", 900, 680, 1200, 710, Color(255, 255, 255, 1.f),20.f);



}

void CScene_file::Exit()
{
}

void CScene_file::Release()
{
}
