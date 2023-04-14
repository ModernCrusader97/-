#include "stdafx.h"
#include "Mouse.h"


CMouse::CMouse()
{
}

CMouse::~CMouse()
{
	Release();
}

void CMouse::Initialize(void)
{
	m_tInfo.fCX = 20.f;
	m_tInfo.fCY = 20.f;
}

int CMouse::Update(void)
{
	POINT	pt{};

	// ���콺 Ŀ���� ��ġ ��ǥ�� ����
	GetCursorPos(&pt);

	// ��ü ��ũ�� �������� ���� ���콺 ��ǥ�� �츮�� ������ â ��ǥ �������� ��ȯ
	ScreenToClient(g_hWnd, &pt);

	m_tInfo.fX = (float)pt.x;
	m_tInfo.fY = (float)pt.y;

	ShowCursor(false);

	__super::Update_Rect();

	return 0;
}

int CMouse::Late_Update(void)
{
	return 0;
}

void CMouse::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

}

void CMouse::Release(void)
{
}
