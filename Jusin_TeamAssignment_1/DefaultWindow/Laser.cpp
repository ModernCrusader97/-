#include "stdafx.h"
#include "Laser.h"


CLaser::CLaser()
{
}


CLaser::~CLaser()
{
}
void CLaser::Initialize(void)
{
	m_tInfo.fCX = 5.f;
	m_tInfo.fCY = 50.f;
	m_fSpeed = 10.f;
}
void CLaser::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}
