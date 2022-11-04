#pragma once
#include "CStageObject.h"
class CGround :
    public CStageObject
{
	
	public:
		CGround();
		virtual ~CGround();

	private:

		float startPosx;
		float startPosy;
		float endPosx;
		float endPosx;
		void Init() override;
		void Update() override;
		void Render() override;
		void Release() override;

	private:
		void OnCollisionEnter(CCollider* pOther) override;
		void OnCollisionStay(CCollider* pOther) override;
		void OnCollisionExit(CCollider* pOther) override;


};

