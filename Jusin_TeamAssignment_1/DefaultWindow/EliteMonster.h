#pragma once
#include "Monster.h"
class CEliteMonster :
	public CMonster
{
public:
	CEliteMonster();
	~CEliteMonster();
	void Initialize(void);
	void Render(HDC hDC);
	int Update(void);
	int Late_Update(void);
	CObj * CreateBullet(int);
	void SetBullet(list<CObj*>* pBullet) { m_pBullet = pBullet; }
	list<CObj*>* m_pBullet;
private:
	int m_iFireRate;
};

