#pragma once

class CCollisionManager;
class CSceneManager;
class CManagers
{
public:
	static CManagers& instance()	// Singleton
	{
		static CManagers*	m_instance = new CManagers();
		return *m_instance;
	}

	void Initialize();
	void Release();

	CCollisionManager* Collision() { return m_cCollision; }
	CSceneManager* Scene() { return m_cScene; }

private:
	CManagers();
	static CManagers*	m_instance;

	CCollisionManager*	m_cCollision;
	CSceneManager*		m_cScene;

	// ~CManagers();
};