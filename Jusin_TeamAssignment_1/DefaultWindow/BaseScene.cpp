#include "stdafx.h"
#include "BaseScene.h"
#include "Player.h"
#include "Managers.h"

CBaseScene::CBaseScene()
{
}

//void CBaseScene::Set_ObjectList(list<CObj*> _ObjectList[TYPE_OBJ::TYPE_END], TYPE_OBJ _eType)
//{
//	for (int iType = 0; iType < TYPE_OBJ::TYPE_END; ++iType)
//		m_ObjectList[iType] = _ObjectList[iType];
//}

void CBaseScene::AddObjInGame(CObj* _cObj)
{
	for (int iType = 0; iType < static_cast<int>(TYPE_OBJ::TYPE_END); ++iType)
		if (iType == static_cast<int>(_cObj->Get_Type()))
			m_ObjectList[iType].push_back(_cObj);
}

void CBaseScene::Initialize()
{
	CObj* cPlayer = new CPlayer();
	cPlayer->Initialize();
	m_ObjectList[static_cast<int>(TYPE_OBJ::TYPE_PLAYER)].push_back(cPlayer);
}

void CBaseScene::Update()
{
	for (int iType = 0; iType < static_cast<int>(TYPE_OBJ::TYPE_END); ++iType)
		for (CObj* iter : m_ObjectList[iType])
			iter->Update();
}

void CBaseScene::Late_Update()
{
	for (int iType = 0; iType < static_cast<int>(TYPE_OBJ::TYPE_END); ++iType)
		for (CObj* iter : m_ObjectList[iType])
			iter->Late_Update();
}

void CBaseScene::Render(HDC hDC)
{
	TCHAR	szBuf[32] = L"";
	RECT	rc{ 10, 10, 80, 40 };
	swprintf_s(szBuf, L"Stage : %d", static_cast<int>(Get_Scene()) + 1);
	DrawText(hDC, szBuf, lstrlen(szBuf), &rc, DT_CENTER);

	for (int iType = 0; iType < static_cast<int>(TYPE_OBJ::TYPE_END); ++iType)
		for (CObj* iter : m_ObjectList[iType])
			iter->Render(hDC);
}

void CBaseScene::Release()
{
	for (int iType = 0; iType < static_cast<int>(TYPE_OBJ::TYPE_END); ++iType)
		for (CObj* iter : m_ObjectList[iType])
			iter->Release();
}

CBaseScene::~CBaseScene()
{
}