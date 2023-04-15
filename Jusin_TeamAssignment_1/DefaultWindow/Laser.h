#pragma once
#include "Bullet.h"
class CLaser :
	public CBullet
{
public:
	CLaser();
	virtual ~CLaser();
	virtual void Render(HDC hDC) override;
	virtual void Initialize(void) override;
};

