#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	TYPE_OBJ	Get_Type() { return m_eType; }


public:
	virtual void	Initialize(void)	PURE;
	virtual int		Update(void)		PURE;
	virtual int		Late_Update(void)	PURE;
	virtual void	Render(HDC hDC)		PURE;
	virtual void	Release(void)		PURE;

protected:
	void		Update_Rect(void);

protected:
	INFO		m_tInfo;
	float		m_fSpeed;
	
	TYPE_OBJ	m_eType;
	STATE		m_eState;
	RECT		m_tRect;
};

