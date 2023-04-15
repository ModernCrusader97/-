#include "stdafx.h"
#include "EliteMonster.h"
#include "Bullet.h"

CEliteMonster::CEliteMonster()
{
}


CEliteMonster::~CEliteMonster()
{
}
void CEliteMonster::Initialize(void)
{
	m_tInfo = { 300.f, 100.f, 75.f, 75.f };
	m_fSpeed = 2.f;
	m_iDir = 6;
	m_iLife = 20;
}
void CEliteMonster::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TCHAR	szBuf[32] = L"Bf109: ";
	TCHAR	szLife[32] = L"";
	_stprintf_s(szLife, TEXT("%d"), m_iLife);
	wcscat_s(szBuf, szLife);
	DrawText(hDC, szBuf, lstrlen(szBuf), &m_tRect, DT_CENTER | DT_NOCLIP);
}
int CEliteMonster::Update(void)
{

	if (m_bDead == true)
	{
		m_iLife--;
		m_bDead = false;
	}
	if (m_iLife == 0)
	{

		return 1;
	}
	float	fWidth = 0.f, fHeight = 0.f, fDiagonal = 0.f;
	float	fRadian = 0.f;

	fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);
	fRadian = acosf(fWidth / fDiagonal);
	fRadian = (2 * 3.141592f) - fRadian;
	m_fAngle = fRadian * 180.f / 3.141592f;
	if (m_iFireRate == 50)
	{
		m_pBullet->push_back(CreateBullet(1));
		m_pBullet->push_back(CreateBullet(0));
		m_pBullet->push_back(CreateBullet(-1));
		m_iFireRate = 0;
	}
	m_iFireRate++;
	if (m_iDir == 4)
		m_tInfo.fX -= m_fSpeed;
	if (m_iDir == 6)
		m_tInfo.fX += m_fSpeed;

	if (m_tInfo.fX < 100)
	{
		m_tInfo.fY += 50.f;
		m_iDir = 6;
	}
	else if (m_tInfo.fX>WINCX - 100)
	{
		m_tInfo.fY += 50.f;
		m_iDir = 4;
	}
	CObj::Update_Rect();
	return 0;
}
int CEliteMonster::Late_Update(void)
{
	
	return 0;
}
CObj* CEliteMonster::CreateBullet(int _iDirection)
{
	CObj* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->SetPos(m_tInfo.fX, m_tInfo.fY);
	pBullet->SetAngle(m_fAngle + _iDirection * 15);
	pBullet->set_Speed(5.f);
	return pBullet;

}

