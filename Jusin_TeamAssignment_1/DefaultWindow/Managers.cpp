#include "stdafx.h"
#include "Managers.h"
#include "CollisionManager.h"
#include "SceneManager.h"

CManagers::CManagers()
{
}

void CManagers::Initialize()
{
	m_cScene		= new CSceneManager;
	m_cCollision	= new CCollisionManager;
}

void CManagers::Release()
{
	m_cCollision->Release();
	m_cScene->Release();
}
