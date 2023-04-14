#pragma once
#include "Obj.h"
class CBullet :
	public CObj
{
public:
	CBullet();
	virtual ~CBullet();

	// CObj��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int	 Update(void) override;
	virtual int	 Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
};

