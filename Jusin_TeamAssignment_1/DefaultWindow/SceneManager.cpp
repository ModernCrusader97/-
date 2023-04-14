#include "stdafx.h"
#include "SceneManager.h"
#include "Managers.h"
#include "BaseScene.h"

void CSceneManager::Load_Scene(CBaseScene * _cNextScene)
{
	CManagers::instance().Release();
	m_cCurrentScene = _cNextScene;
	m_cCurrentScene->Initialize();
	//_cNextScene->Update();
}

void CSceneManager::Update_Scene()
{
	m_cCurrentScene->Update();
}

void CSceneManager::Late_Update_Scene()
{
	m_cCurrentScene->Late_Update();
}

void CSceneManager::Render_Scene(HDC hDC)
{
	m_cCurrentScene->Render(hDC);
}

TYPE_SCENE CSceneManager::GetSceneType(CBaseScene * _cScene)
{
	return _cScene->Get_Scene();
}

void CSceneManager::Release()
{
	if(m_cCurrentScene)
		m_cCurrentScene->Release();
}
