#pragma once

#include "Define.h"

class CObj;
class CBaseScene
{
public:
	CBaseScene();

	TYPE_SCENE		Get_Scene()								{ return m_eSceneType; }
	list<CObj*>*	Get_ObjList_ByType(TYPE_OBJ _eObjType)	{ return &m_ObjectList[static_cast<int>(_eObjType)]; }

	void			Set_SceneType(TYPE_SCENE _eSceneType) { m_eSceneType = _eSceneType; }
	
	// void Set_ObjectList(list<CObj*> _ObjectList[static_cast<int>(static_cast<int>((TYPE_OBJ::TYPE_END))], TYPE_OBJ _eType);
	void AddObjInGame(CObj* _cObj);

	virtual void Initialize();
	virtual void Update();
	virtual void Late_Update();
	virtual void Render(HDC hDC);
	virtual void Release();

	virtual ~CBaseScene();

protected:
	TYPE_SCENE	m_eSceneType;
	//CBaseScene* m_prevScene;
	list<CObj*> m_ObjectList[static_cast<int>(static_cast<int>(TYPE_OBJ::TYPE_END))];
};