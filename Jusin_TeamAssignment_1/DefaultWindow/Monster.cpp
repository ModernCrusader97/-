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
	m_eState = STATE::STATE_DEFAULT;
}

int CMonster::Update(void)
{
	return 0;
}

int CMonster::Late_Update(void)
{
	return 0;
}

void CMonster::Render(HDC hDC)
{
}

void CMonster::Release(void)
{
}
