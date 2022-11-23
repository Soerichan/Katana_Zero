#include "framework.h"
#include "CBoss.h"
#include "CBossMissile01.h"
#include "CBossCMissile02.h"
#include "CBossCMissile03.h"

CBoss::CBoss()
{
    m_strName = L"Boss";
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

void CBoss::Throw()
{
    CBossMissile01* pBMissile01 = new CBossMissile01;
    if (m_vecLookDir.x==1)
    {
        pBMissile01->SetDir(Vector(1, 0));


    }
    else
    {
        pBMissile01->SetDir(Vector(-1, 0));
    }
    pBMissile01->SetPos(m_vecPos);
    ADDOBJECT(pBMissile01);
}

void CBoss::Lundge()
{
    CBossCMissile03* pBMissile03 = new CBossCMissile03;
    pBMissile03->SetPos(m_vecPos);
    ADDOBJECT(pBMissile03);
}

void CBoss::Jump()
{
    CBossCMissile02* pBMissile02 = new CBossCMissile02;
    pBMissile02->SetPos(m_vecPos);
    ADDOBJECT(pBMissile02);
}

void CBoss::WhereBoss()
{
    GAME->BossPos = m_vecPos;
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

    m_fTimerIdle=10.f;
    m_fTimerThrow = 4.f;
    m_fTimerLundge = 1.6f;
    m_fTimerJump = 4.f;
    m_fTimerBlock = 0.6f;
    m_fTimerHurt = 1.f;
    m_fTimerRecover = 0.7f;
    m_fTimerStruggle = 4.f;
    m_iStruggleCount = 0;

    srand(time(NULL));
    AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 0));

    m_pAxeSound = RESOURCE->LoadSound(L"AxeSound", L"Sound\\Axe.wav");
    m_pLundgeSound = RESOURCE->LoadSound(L"LundgeSound", L"Sound\\Lundge.wav");
}

void CBoss::Update()
{   
    WhereBoss();
    if (m_layer == Layer::Monster)
    {
        m_vecPos.y += 1.f;
    }

    AnimatorUpdate();
    if (State == BossState::Idle)
    {
        m_fIdleTimer -= DT;
        if (PLAYERPOSITION.x > m_vecPos.x)
        {
            if (PLAYERPOSITION.x > m_vecPos.x + 5)
            {
                m_vecPos.x += 50 * DT;
               
            }
            m_vecLookDir.x = +1;
        }
        else
        {
            if (PLAYERPOSITION.x < m_vecPos.x - 5)
            {
                m_vecPos.x -= 50 * DT;

            }
            
            m_vecLookDir.x = -1;
        }

        if (m_fIdleTimer <= 7.f)
        {
            int todo = rand() % 2;

            switch (todo)
            {
            case 0:
                State = BossState::Throw;
                SOUND->Play(m_pAxeSound,1.f, true);
                m_fIdleTimer = 10.f;
                Throw();
                break;
            case 1:
                State = BossState::Lundge;
               // m_strName = L"Lunge";
                Lundge();
                m_fIdleTimer = 10.f;
                break;
         
            }
        }
    }

    if (State == BossState::Throw)
    {
      
        m_fTimerThrow -= DT;
        if (m_fTimerThrow <= 0)
        {
            SOUND->Stop(m_pAxeSound);
            State = BossState::Idle;
            m_fTimerThrow = 4.f;
        }


    }

    if (State == BossState::Lundge)
    {
       // RemoveCollider();
    
      // m_layer = Layer::EnemyMissile;
       // AddCollider(ColliderType::Rect, Vector(40, 60), Vector(0, 0));

        if (m_vecLookDir.x == 1)
        {
            m_vecPos.x += 100*(3-m_fTimerLundge) * (3 - m_fTimerLundge) * DT;
        }
        else
        {
            m_vecPos.x -= 100 * (3 - m_fTimerLundge) * (3 - m_fTimerLundge) * DT;
        }

        m_fTimerLundge -= DT;

        if (m_fTimerLundge <= 0)
        {
           // RemoveCollider();
           // m_layer = Layer::Monster;
           // m_strName = L"Boss";
           // AddCollider(ColliderType::Rect, Vector(40, 60), Vector(0, 0));
            State = BossState::Idle;
            SOUND->Play(m_pLundgeSound, 1.f);
            m_fTimerLundge = 1.6f;
        }


    }

    if (State == BossState::Jump)
    {
       
        m_fTimerJump -= DT;



        if (m_fTimerJump >= 2.f)
        {
            m_vecPos.y -= 250 * DT * m_fTimerJump;
        }
        else if (m_fTimerJump < 2.f && m_fTimerJump>0.f)
        {
            m_vecPos.y += 100 * DT * m_fTimerJump;
        }
        else
        {
            SOUND->Stop(m_pAxeSound);
            State = BossState::Idle;
            m_fTimerJump = 4.f;
        }


    }

    if (State == BossState::Block)
    {
        
        m_fTimerBlock -= DT;
        if (m_fTimerBlock <= 0)
        {
            State = BossState::Idle;
            m_fTimerBlock = 0.6f;
        }


    }


    if (State == BossState::Hurt)
    {

        m_fTimerHurt -= DT;

        if (m_fTimerHurt >= 0.5f)
        {
            m_vecPos.x += -(m_vecLookDir.x) * 200 * DT;
        }

        if (m_fTimerHurt <= 0)
        {
            State = BossState::Recover;
            m_fTimerHurt = 1.f;
        }


    }

    if (State == BossState::Recover)
    {

        m_fTimerRecover -= DT;
        if (m_fTimerRecover <= 0)
        {
            State = BossState::Idle;
            m_fTimerRecover = 0.7f;
        }


    }

    if (State == BossState::Struggle)
    {

        m_fTimerStruggle -= DT;
        if (m_fTimerStruggle <= 0)
        {
            SOUND->Stop(m_pMetalCollisiionSound);
            GAME->isStruggleing = false;
            State = BossState::Recover;
            m_iStruggleCount++;
            m_fTimerStruggle = 4.f;
        }


    }

    if (m_iStruggleCount > 4)
    {
        State = BossState::Die;
        GAME->m_iDeadMonster++;
    }

    
}

void CBoss::Render()
{
}

void CBoss::Release()
{
}

void CBoss::AnimatorUpdate()
{
    wstring str = L"";
    str += L"Boss";
    switch (State)
    {
        
    case CBoss::BossState::Idle:
        str += L"Walk";
        break;
    case CBoss::BossState::Block:
        str += L"Block";
        break;
    case CBoss::BossState::Throw:
        str += L"Throw";
        break;
    case CBoss::BossState::Lundge:
        str += L"Lundge";
        break;
    case CBoss::BossState::Jump:
        str += L"Jump";
        break;
    case CBoss::BossState::Skill04:
        str += L"Skill04";
        break;
    case CBoss::BossState::Hurt:
        str += L"Hurt";
        break;
    case CBoss::BossState::Struggle:
        str += L"Struggle";
        break;
    case CBoss::BossState::Recover:
        str += L"Recover";
        break;
    case CBoss::BossState::Die:
        str += L"Hurt";
        break;

    }
    if (m_vecLookDir.x==+1)
    {
        str += L"Right";


    }
    else
    {
        str += L"Left";
    }
    m_pAnimator->Play(str, false);

}

void CBoss::OnCollisionEnter(CCollider* pOtherCollider)
{
    CMonster::OnCollisionEnter(pOtherCollider);
    wstring pTarget = pOtherCollider->GetObjName();
    if (pTarget ==L"KatanaSlash")
    {   
        if (State == BossState::Throw || State == BossState::Lundge || State == BossState::Jump)
        {
            if ((PLAYERPOSITION.x < m_vecPos.x&&m_vecLookDir.x==1)|| (PLAYERPOSITION.x > m_vecPos.x && m_vecLookDir.x == -1))
            {
                SOUND->Play(m_pKatanaHitSound, 1.f);
                State = BossState::Hurt;
            }
            else
            {
                if (m_vecLookDir.x == 1)
                {
                    m_vecLookDir.x = 1;
                    State = BossState::Block;
                    SOUND->Play(m_pMetalCollisiionSound, 1.f);
                }
                else
                {
                    m_vecLookDir.x = -1;
                    State = BossState::Block;
                    SOUND->Play(m_pMetalCollisiionSound, 1.f);
                }
            }
        }
        else if (State == BossState::Hurt)
        {
            SOUND->Play(m_pMetalCollisiionSound, 1.f,true);
            GAME->isStruggleing = true;
            State = BossState::Struggle;
        }
        else if (State == BossState::Die)
        {

        }
        else
        {
            if (m_vecLookDir.x == 1)
            {
                m_vecLookDir.x = -1;
                State = BossState::Block;
                SOUND->Play(m_pMetalCollisiionSound, 1.f);
            }
            else
            {
                m_vecLookDir.x = +1;
                State = BossState::Block;
                SOUND->Play(m_pMetalCollisiionSound, 1.f);
            }
        }
    }
   
}

void CBoss::OnCollisionStay(CCollider* pOtherCollider)
{
    CMonster::OnCollisionStay(pOtherCollider);
}

void CBoss::OnCollisionExit(CCollider* pOtherCollider)
{
    CMonster::OnCollisionExit(pOtherCollider);
}
