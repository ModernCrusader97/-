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
}

int CBullet::Update(void)
{
	return 0;
}

int CBullet::Late_Update(void)
{
	return 0;
}

void CBullet::Render(HDC hDC)
{
}

void CBullet::Release(void)
{
}
