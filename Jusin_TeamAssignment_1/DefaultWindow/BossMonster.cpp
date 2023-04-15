#include "stdafx.h"
#include "BossMonster.h"
#include "Bullet.h"


CBossMonster::CBossMonster()
{
}


CBossMonster::~CBossMonster()
{
}
void CBossMonster::Initialize(void)
{
	m_tInfo = { 300.f, 150.f, 200.f, 200.f };
	m_fSpeed = 2.f;
	m_iDir = 6;
	m_iLife = 50;
	m_iFireRate = 0;
	m_iFireLimit = 0;
	m_fAngle = 0;
	m_iTermbetweenAttack = 0;
}
void CBossMonster::Render(HDC hDC)
{

	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TCHAR	szBuf[32] = L"Bismark: ";
	TCHAR	szLife[32] = L"";
	_stprintf_s(szLife, TEXT("%d"), m_iLife);
	wcscat_s(szBuf, szLife);
	DrawText(hDC, szBuf, lstrlen(szBuf), &m_tRect, DT_CENTER | DT_NOCLIP);
}
int CBossMonster::Update(void)
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
	if (m_iDir == 4)
		m_tInfo.fX -= m_fSpeed;
	if (m_iDir == 6)
		m_tInfo.fX += m_fSpeed;

	if (m_tInfo.fX < 150)
	{

		m_iDir = 6;
	}
	else if (m_tInfo.fX>WINCX - 150)
	{

		m_iDir = 4;
	}
	CObj::Update_Rect();
	return 0;
}
int CBossMonster::Late_Update(void)
{
	float	fWidth = 0.f, fHeight = 0.f, fDiagonal = 0.f;
	float	fRadian = 0.f;

	fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);
	fRadian = acosf(fWidth / fDiagonal);
	fRadian = (2 * 3.141592f) - fRadian;
	m_fAngle = fRadian * 180.f / 3.141592f;
	int iPattern = rand() % 100;
	iPattern = iPattern % 3;
	if (m_iTermbetweenAttack <= 50)
	{
		switch (iPattern)
		{
		case 2:
			if (m_iFireRate >= 10)
			{
				m_pBullet->push_back(CreateBullet(1));
				m_fAngle -= 15;
				m_pBullet->push_back(CreateBullet(1));
				m_fAngle += 30;
				m_pBullet->push_back(CreateBullet(1));
				m_iFireRate = 0;
			}
			m_iFireRate++;
			m_iTermbetweenAttack = 0;
			break;
		case 1:
			if (m_iFireRate >= 10)
			{
				m_fAngle = rand() % 90 + 225.f;
				m_pBullet->push_back(CreateBullet(-1));
				m_iFireRate = 0;
			}
			m_iFireRate++;

			m_iTermbetweenAttack = 0;
			break;

		case 0:
			if (m_iFireLimit >= 90)
			{
				for (int i = 0; i <= 24; i++)
				{
					m_pBullet->push_back(CreateBullet(1));
					m_iFireLimit = 0;
					m_fAngle += 15;
				}
			}
			m_iFireLimit++;
			m_iTermbetweenAttack = 0;

			break;

		}
		m_iTermbetweenAttack++;
	}
	return 0;
}
CObj* CBossMonster::CreateBullet(int _iHand)
{
	CObj* pBullet = new CBullet;
	pBullet->Initialize();
	pBullet->SetPos(m_tInfo.fX + 100 * _iHand, m_tInfo.fY);
	pBullet->SetAngle(m_fAngle);
	pBullet->set_Speed(2.f);
	return pBullet;
}