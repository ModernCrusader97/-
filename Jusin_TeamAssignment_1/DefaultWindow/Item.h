#pragma once
#include "Obj.h"
class CItem :
	public CObj
{
public:
	CItem();
	virtual ~CItem();

	// CObj��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int	 Update(void) override;
	virtual int	 Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
};

