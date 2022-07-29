#pragma once

#include <type_traits>
#include <list>

typedef unsigned int uint;
typedef unsigned char Byte;

#define SIZE_FLOAT sizeof(float)

template<typename T = float>
struct Vector3d
{
	Vector3d(T Tx, T Ty, T Tz)
	{
		X = Tx;
		Y = Ty;
		Z = Tz;
	}

	T X;
	T Y;
	T Z;
};

template<typename T = float>
struct Vector2d
{
	Vector2d(T Tx, T Ty)
	{
		X = Tx;
		Y = Ty;
	}
	T x;
	T y;
};

typedef Vector3d<> Vector3;
typedef Vector2d<> Vector2;