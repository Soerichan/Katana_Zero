#include "framework.h"
#include "CBoss.h"

CBoss::CBoss()
{
}

CBoss::~CBoss()
{
}

void CBoss::Skill01()
{
}

void CBoss::Skill02()
{
}

void CBoss::Skill03()
{
}

void CBoss::Skill04()
{
}

void CBoss::Attack()
{
}

void CBoss::Init()
{
    CMonster::Init();
    m_pWalkImage= RESOURCE->LoadImg(L"BossWalk", L"Image\\Boss\\Walk.png");
    m_pBlockImage = RESOURCE->LoadImg(L"BossBlock", L"Image\\Boss\\Block.png");
    m_pThrowImage = RESOURCE->LoadImg(L"BossThrow", L"Image\\Boss\\Throw.png");
    m_pLundgeImage = RESOURCE->LoadImg(L"BossLundge", L"Image\\Boss\\Lundge.png");
    m_pJumpImage = RESOURCE->LoadImg(L"BossJumpe", L"Image\\Boss\\Jump.png");
    m_pHurtImage = RESOURCE->LoadImg(L"BossHurt", L"Image\\Boss\\Hurt.png");
    m_pStruggleImage = RESOURCE->LoadImg(L"BossStruggle", L"Image\\Boss\\Struggle.png");
    m_pRecoverImage = RESOURCE->LoadImg(L"BossRecover", L"Image\\Boss\\Recover.png");
    m_pAnimator = new CAnimator;



    m_pAnimator->CreateAnimation(L"BossWalkRight", m_pWalkImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 10);
    m_pAnimator->CreateAnimation(L"BossWalkLeft", m_pWalkImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 10);

    m_pAnimator->CreateAnimation(L"BossBlockRight", m_pBlockImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 5,false);
    m_pAnimator->CreateAnimation(L"BossBlockLeft", m_pBlockImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 5,false);

    m_pAnimator->CreateAnimation(L"BossThrowRight", m_pThrowImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 9,false);
    m_pAnimator->CreateAnimation(L"BossThrowLeft", m_pThrowImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 9,false);

    m_pAnimator->CreateAnimation(L"BossLundgeRight", m_pLundgeImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 15,false);
    m_pAnimator->CreateAnimation(L"BossLundgeLeft", m_pLundgeImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f,15,false );

    m_pAnimator->CreateAnimation(L"BossJumpRight", m_pJumpImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 9,false);
    m_pAnimator->CreateAnimation(L"BossJumpLeft", m_pJumpImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 9,false);

    m_pAnimator->CreateAnimation(L"BossHurtRight", m_pHurtImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 6,false);
    m_pAnimator->CreateAnimation(L"BossHurtLeft", m_pHurtImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 6,false);

    m_pAnimator->CreateAnimation(L"BossStruggleRight", m_pStruggleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 2);
    m_pAnimator->CreateAnimation(L"BossStruggleLeft", m_pStruggleImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 2);

    m_pAnimator->CreateAnimation(L"BossRecoverRight", m_pRecoverImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 7,false);
    m_pAnimator->CreateAnimation(L"BossRecoverLeft", m_pRecoverImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 7,false);

    m_pAnimator->Play(L"BossWalkRight", false);
    AddComponent(m_pAnimator);
}

void CBoss::Update()
{
}

void CBoss::Render()
{
}

void CBoss::Release()
{
}

void CBoss::AnimatorUpdate()
{
}

void CBoss::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CBoss::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CBoss::OnCollisionExit(CCollider* pOtherCollider)
{
}
