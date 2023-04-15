#include "stdafx.h"
#include "CollisionManager.h"


CCollisionManager::CCollisionManager()
{
}


void CCollisionManager::Release()
{

}

CCollisionManager::~CCollisionManager()
{
}
bool CCollisionManager::Collision_Rect(list<CObj*> Dst, list<CObj*>  Src)
{
	RECT	rc{};



	for (auto& Dest : Dst)
	{
		for (auto& Sour : Src)
		{
			if (IntersectRect(&rc, &Dest->Get_Rect(), &(Sour->Get_Rect())))
			{

				Dest->Set_Dead(true);
				return true;

			}
			else
				return false;
		}
	}
}
void CCollisionManager::Collision_Sphere(list<CObj*> Dst, list<CObj*> Src)
{
	for (auto& Dest : Dst)
	{
		for (auto& Sour : Src)
		{
			if (Check_Sphere(Dest, Sour))
			{
				Dest->Set_Dead(true);
				Sour->Set_Dead(true);
			}
		}
	}
}
bool CCollisionManager::Check_Sphere(CObj * pDst, CObj * pSrc)
{
	float	fWidth = fabs(pDst->Get_Info().fX - pSrc->Get_Info().fX);
	float	fHeight = fabs(pDst->Get_Info().fY - pSrc->Get_Info().fY);

	float	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	float	fRadius = (pDst->Get_Info().fCX + pSrc->Get_Info().fCX) * 0.5f;

	return fDiagonal <= fRadius;
}
