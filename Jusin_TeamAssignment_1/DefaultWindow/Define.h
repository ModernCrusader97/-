#pragma once

#define			WINCX		800
#define			WINCY		600

#define			PURE		= 0

typedef struct tagInfo
{
	float	fX;
	float	fY;
	float	fCX;
	float	fCY;

}INFO;

template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

typedef enum class Obj_Type
{
	TYPE_PLAYER		= 0,
	TYPE_MONSTER	= 1,
	TYPE_BULLET		= 2,
	TYPE_ITEM		= 3,
	TYPE_ENEMYBULLET	=4,
	TYPE_END			= 5,

}TYPE_OBJ;

typedef enum class Scene_Type
{
	TYPE_STAGE_1	= 0,
	TYPE_STAGE_2	= 1,
	TYPE_STAGE_3	= 2,
	TYPE_STAGE_4	= 3,
	TYPE_END	= 4,

}TYPE_SCENE;

typedef enum class Obj_State
{
	STATE_DEFAULT = 0,
	STATE_DEAD = 1,
	STATE_END = 2,

}STATE;

extern HWND	g_hWnd;