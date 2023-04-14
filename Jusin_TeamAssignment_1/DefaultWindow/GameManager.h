#pragma once

class CObj;
class CGameManager
{
public:
	static CGameManager& instance()	// Singleton
	{
		if (nullptr == m_instance)
			m_instance = new CGameManager();
		return *m_instance;
	}

	void AddObject(list<CObj*> _ObjectList, CObj* _cObj);

private:
	CGameManager();
	static CGameManager* m_instance;
};