#pragma once
#include "Obj.h"
class CCollisionManager
{
public:
	CCollisionManager();

	void Release();
	~CCollisionManager();
	bool Collision_Rect(list<CObj*> Dst, list<CObj*> Src);//만나면 Dst만 쥬거버림
	void Collision_Sphere(list<CObj*> Dst, list<CObj*> Src);//만나면 둘다 주거버림
	bool Check_Sphere(CObj * pDst, CObj * pSrc);
	
};

