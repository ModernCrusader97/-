#include "stdafx.h"
#include "Item.h"


CItem::CItem()
{
}


CItem::~CItem()
{
}

void CItem::Initialize(void)
{
	m_eState = STATE::STATE_DEFAULT;
}

int CItem::Update(void)
{
	return 0;
}

int CItem::Late_Update(void)
{
	return 0;
}

void CItem::Render(HDC hDC)
{
}

void CItem::Release(void)
{
}
