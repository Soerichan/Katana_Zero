#pragma once
#include "CMissile.h"
class CKatanaSlashHigh :
    public CMissile
{

	public:
		CKatanaSlashHigh();
		virtual ~CKatanaSlashHigh();

	private:

		float m_pTimer;
		void Init() override;
		void Update() override;
		void Render() override;
		void Release() override;
		void AnimatorUpdate() override;
		void OnCollisionEnter(CCollider* pOtherCollider) override;
	

};

