#pragma once
#include "CImageObject.h"
class CSpark :
    public CImageObject
{
	
	public:
		CSpark();
		virtual ~CSpark();

		void SetxDir(bool xDir);
	private:
		bool m_bToRight;
		CAnimator* m_pAnimator;

		float m_fTimer;

		void Init() override;
		void Update() override;
		void Render() override;
		void Release() override;

		void AnimatorUpdate();
	

};

