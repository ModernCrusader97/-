#pragma once
#include "Obj.h"
class CCollisionManager
{
public:
	CCollisionManager();

	void Release();
	~CCollisionManager();
	bool Collision_Rect(list<CObj*> Dst, list<CObj*> Src);//������ Dst�� ��Ź���
	void Collision_Sphere(list<CObj*> Dst, list<CObj*> Src);//������ �Ѵ� �ְŹ���
	bool Check_Sphere(CObj * pDst, CObj * pSrc);
	
};

