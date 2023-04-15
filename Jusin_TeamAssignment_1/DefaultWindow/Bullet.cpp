#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
}

void CBullet::Initialize(void)
{
	m_eState = STATE::STATE_DEFAULT;
	m_tInfo.fCX = 10.f;
	m_tInfo.fCY = 10.f;
	m_fSpeed = 10.f;
}

int CBullet::Update(void)
{

	if (m_bDead == true)
		return 1;


	m_tInfo.fX += m_fSpeed * cos(m_fAngle * (3.141592 / 180.f));
	m_tInfo.fY -= (m_fSpeed * sin(m_fAngle * (3.141592 / 180.f)));
	CObj::Update_Rect();
	return 0;
}
int CBullet::Late_Update(void)
{
	if (m_tInfo.fY < 60 || m_tInfo.fY>WINCY - 60 || m_tInfo.fX<60 || m_tInfo.fX>WINCX - 60)
	{
		m_bDead = true;
	}
	return 0;

}
void CBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release(void)
{
}

