#pragma once

#include "Define.h"

class CObj;
class CBaseScene;
class CManagers;
class CSceneManager
{
public:
	CSceneManager() :m_cCurrentScene(nullptr) {};

//	CBaseScene* LoadScene(CBaseScene* _cNextScene);
	void Load_Scene(CBaseScene* _cNextScene);
	void Update_Scene();
	void Late_Update_Scene();
	void Render_Scene(HDC hDC);
	TYPE_SCENE	GetSceneType(CBaseScene* _cScene);
//	void		ExitScene(CBaseScene* _prevScene) {}	// 이게 맞나..

	void		Release();

private:

private:
	CBaseScene*		m_cCurrentScene;
	list<CObj*>		m_ObjectList[static_cast<int>(TYPE_OBJ::TYPE_END)];
};

