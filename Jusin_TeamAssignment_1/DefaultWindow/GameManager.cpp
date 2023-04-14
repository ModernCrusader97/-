#include "stdafx.h"
#include "GameManager.h"
#include "Obj.h"
#include "define.h"

void CGameManager::AddObject(list<CObj*> _ObjectList, CObj* _cObj)
{
	_ObjectList.push_back(_cObj);
}

CGameManager::CGameManager()
{
}