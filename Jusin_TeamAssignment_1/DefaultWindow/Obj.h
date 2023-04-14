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
public:
	void set_Speed(float _fSpeed) { m_fSpeed = _fSpeed; }
	void SetPos(float fPosX, float FPosY) { m_tInfo.fX = fPosX; m_tInfo.fY = FPosY; };
	void SetDir(int _iDir) { m_iDir = _iDir; }
	RECT Get_Rect() { return m_tRect; }
	INFO Get_Info() { return m_tInfo; }
	void Set_Dead(bool _bDead) { m_bDead = _bDead; }
	void SetAngle(float	_fAngle) { m_fAngle = _fAngle; }
	void		Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }
protected:

	
	int m_iDir;
	bool m_bDead;
	float		m_fAngle;
	CObj*		m_pTarget;
	float		m_fDistance;
	int m_iLife;
};

