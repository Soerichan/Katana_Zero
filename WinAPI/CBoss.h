#pragma once
#include "CMonster.h"
class CBoss :
    public CMonster
{
    enum class BossState
    {   
        Idle,
        Block,
        Throw,
        Lundge,
        Jump,
        Skill04,
        Hurt,
        Struggle,
        Die,
    };
public:CBoss();
      virtual ~CBoss();

  private:
      CImage* m_pWalkImage;
      CImage* m_pBlockImage;
      CImage* m_pThrowImage;
      CImage* m_pLundgeImage;
      CImage* m_pJumpImage;
      CImage* m_pHurtImage;
      CImage* m_pStruggleImage;
      CImage* m_pRecoverImage;
      CAnimator* m_pAnimator;
      float m_fTimerIdle;
      float m_fTimerThrow;
      float m_fTimerLundge;
      float m_fTimerJump;
      float m_fTimerBlock;
      bool m_bCanHit;

      void Skill01();
      void Skill02();
      void Skill03();
      void Skill04();
      void Attack()	override;
      void Init() override;
      void Update() override;
      void Render() override;
      void Release() override;

      void AnimatorUpdate();

      void OnCollisionEnter(CCollider* pOtherCollider) override;
      void OnCollisionStay(CCollider* pOtherCollider) override;
      void OnCollisionExit(CCollider* pOtherCollider) override;

};

