#pragma once
#include "Monster.h"
class CBossMonster :
	public CMonster
{
public:
	CBossMonster();
	~CBossMonster();
	void Initialize(void);
	void Render(HDC hDC);
	int Update(void);
	int Late_Update(void);
	CObj * CreateBullet(int Hand);
	void SetBullet(list<CObj*>* pBullet) { m_pBullet = pBullet; }
	list<CObj*>* m_pBullet;
private:
	int m_iFireRate;
	int m_iFireLimit;
	int m_iTermbetweenAttack;
};

