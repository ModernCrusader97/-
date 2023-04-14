#pragma once

#include "Define.h"
#include "Player.h"

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

public:
	CMainGame();
	~CMainGame();
};

