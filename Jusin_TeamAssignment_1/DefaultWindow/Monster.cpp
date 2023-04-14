#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

void CMonster::Initialize(void)
{
	m_tInfo = { 100.f, 100.f, 50.f, 50.f };
	m_fSpeed = 3.f;
	m_iMoveforward = 50;
	m_fAngle = 350.f;
}


int CMonster::Update(void)
{
	if (m_bDead == true)
		return 1;
	/*float	fWidth = 0.f, fHeight = 0.f, fDiagonal = 0.f;
	float	fRadian = 0.f;


	fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);
	fRadian = acosf(fWidth / fDiagonal);
	m_fAngle = fRadian * 180.f / 3.141592f;

	if (m_pTarget->Get_Info().fY > m_tInfo.fY)
		m_fAngle *= -1.f;*/

	if (m_iMoveforward >= 0)
	{
		m_tInfo.fY += m_fSpeed;
		m_iMoveforward--;
	}
	else
	{
		m_tInfo.fX += m_fSpeed * cosf(m_fAngle * 3.141592f / 180.f);
		m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * 3.141592f / 180.f);

	}
	CObj::Update_Rect();
	return 0;
}

void CMonster::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TCHAR	szBuf[32] = L"Zero";
	DrawText(hDC, szBuf, lstrlen(szBuf), &m_tRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void CMonster::Release(void)
{
}

int CMonster::Late_Update(void)
{
	if (m_tInfo.fY < 60 || m_tInfo.fY>WINCY - 60 || m_tInfo.fX<60 || m_tInfo.fX>WINCX - 60)
	{
		m_bDead = true;
		return 1;
	}

	return 0;
}
