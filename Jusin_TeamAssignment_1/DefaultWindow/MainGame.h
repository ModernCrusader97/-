#pragma once

#include "Define.h"
#include "Player.h"
#include "Monster.h"
class CMainGame
{
public:
	void		Initialize(void);
	void		Update(void);
	void		Late_Update();
	void		Render();
	void		Release(void);

private:
	HDC			m_DC;
	CObj*		m_pPlayer;
	CObj*		m_cMouse;
	POINT		m_tMousePos;
	list<CObj*> m_BulletList;
	list<CObj*> m_LasorList;
	list<CObj*> m_EnemyBulletList;
	list<CObj*> m_ItemList;
	CObj* m_pItem;
	CObj* m_pMonster;
	CObj* m_pEliteMon;
	CObj* m_pTheBoss;
	/*void	Key_Input(void) {
		if (GetAsyncKeyState('R'))
		{
			if (!m_pPlayer)
			{
				m_pPlayer = new CPlayer;
				m_pPlayer->Initialize();
				dynamic_cast<CPlayer*>(m_pPlayer)->SetBullet(&m_BulletList);
				dynamic_cast<CPlayer*>(m_pPlayer)->SetLasor(&m_LasorList);
			}
		}
		if (GetAsyncKeyState('P'))
		{
			if (!m_pEliteMon)
			{
				m_pEliteMon = new CEliteMon;
				m_pEliteMon->Initialize();
				dynamic_cast<CEliteMon*>(m_pEliteMon)->SetBullet(&m_EnemyBulletList);
				m_pEliteMon->Set_Target(m_pPlayer);
			}
		}
	}*/
	int		m_iTheBossCount;

public:
	CMainGame();
	~CMainGame();
};

