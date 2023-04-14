#pragma once
#include "Obj.h"
class CMonster :
	public CObj
{
public:
	CMonster();
	virtual ~CMonster();

	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int	 Update(void) override;
	virtual int	 Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	int m_iMoveforward;
};

