#include "stdafx.h"
#include "MainGame.h"
#include "Managers.h"
#include "SceneManager.h"
#include "Mouse.h"
#include "BaseScene.h"
#include "StageScene1.h"

CMainGame::CMainGame()
	: m_pPlayer(nullptr)
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_DC = GetDC(g_hWnd);

	CStageScene1* cStage1 = new CStageScene1;

	CManagers::instance().Initialize();
	CManagers::instance().Scene()->Load_Scene(cStage1);

	/*if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}*/

	m_cMouse = new CMouse;
	m_cMouse->Initialize();
}

void CMainGame::Update(void)
{
	//m_pPlayer->Update();
	if (m_pMonster)
	{
		if (m_pMonster->Update() == 1)
		{
			Safe_Delete<CObj*>(m_pMonster);
		}
	}
	CManagers::instance().Scene()->Update_Scene();
	m_cMouse->Update();
}

void CMainGame::Late_Update()
{
	CManagers::instance().Scene()->Late_Update_Scene();

}

void CMainGame::Render()
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	CManagers::instance().Scene()->Render_Scene(m_DC);
	if (m_pMonster) {
		m_pMonster->Render(m_DC);
	}
	//m_pPlayer->Render(m_DC);

	m_cMouse->Render(m_DC);
}

void CMainGame::Release(void)
{
	Safe_Delete<CObj*>(m_pPlayer);
	ReleaseDC(g_hWnd, m_DC);
	
}

