// Copyright Metehan Tuncbilek, All Rights Reserved.

#ifndef VECTOR_H

#define VECTOR_H

#include <cmath>

template<typename T = float>
struct Vector3D
{
	// If it is not initialized, it is zero vector.
	Vector3D()
	{
		X = 0;
		Y = 0;
		Z = 0;
	}

	// Initialization constructor.
	Vector3D(T Tx, T Ty, T Tz)
	{
		X = (float)Tx;
		Y = (float)Ty;
		Z = (float)Tz;
	}

	float X;
	float Y;
	float Z;

	// Gives the distance from origin.
	float Length()
	{
		return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
	}

	// Rates the current vector's each element in between 0 and 1.
	Vector3D Normalize()
	{
		return Vector3D(X / Length(), Y / Length(), Z / Length());
	}

	// Gives the distance of 2 vector points.
	static float Distance(Vector3D &Vec1, Vector3D &Vec2)
	{
		return sqrt(pow((Vec2.X - Vec1.X), 2) + pow((Vec2.Y - Vec1.Y), 2) + pow((Vec2.Z - Vec1.Z), 2));
	}

	// Scalar multiplication method called Dot Product. Returns float.
	static float DotProduct(Vector3D &Vec1, Vector3D &Vec2)
	{
		return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y + Vec1.Z * Vec1.Z;
	}

	// 2 Dimensional CrossProduct returns normal vector of given two vectors.
	static Vector3D CrossProduct(Vector3D &Vec1, Vector3D &Vec2)
	{
		return Vector3D((Vec1.Y * Vec2.Z - Vec1.Z * Vec2.Y), (Vec1.X * Vec2.Z - Vec1.Z * Vec2.X),
			(Vec1.X * Vec2.Y - Vec1.Y * Vec2.X));
	}

	// Vector3 + Vector3. Each element sums with the other vector's related element.
	Vector3D operator+(Vector3D &Other) const
	{
		return Vector2D((X + Other.X), (Y + Other.Y), (Z + Other.Z));
	}

	// Vector3 + float. Add each element the float parameter.
	Vector3D operator+(T &Other) const
	{
		return Vector2D((X + Other), (Y + Other), (Z + Other));
	}

	// Vector3 * float. Multiplies each element with the float parameter.
	Vector3D operator*(T &Other) const
	{
		return Vector2D((X * Other), (Y * Other), (Z + Other));
	}

	// Vector3 * float. Divides each element with the float parameter.
	Vector3D operator/(T &Other) const
	{
		return Vector2D((X / Other), (Y / Other), (Z + Other));
	}
};

template<typename T = float>
struct Vector2D
{
	// If it is not initialized, it is zero vector.
	Vector2D()
	{
		X = 0;
		Y = 0;
	}

	// Initialization constructor.
	Vector2D(T Tx, T Ty)
	{
		X = (float)Tx;
		Y = (float)Ty;
	}

	float X;
	float Y;

	// Gives the distance from origin.
	float Length()
	{
		return sqrt(pow(X, 2) + pow(Y, 2));
	}

	// Rates the current vector's each element in between 0 and 1.
	Vector2D Normalize()
	{
		return Vector2D(X / Length(), Y / Length());
	}

	// Gives the distance of 2 vector points.
	static float Distance(Vector2D &Vec1, Vector2D &Vec2)
	{
		return sqrt(pow((Vec2.X - Vec1.X), 2) + pow((Vec2.Y - Vec1.Y), 2));
	}

	// Scalar multiplication method called Dot Product. Returns float.
	static float DotProduct(Vector2D &Vec1, Vector2D &Vec2)
	{
		return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y;
	}

	// 2 Dimensional CrossProduct returns the Z value.
	static float CrossProduct(Vector2D& Vec1, Vector2D& Vec2)
	{
		return Vec1.X * Vec2.Y - Vec1.Y * Vec2.X;
	}

	// Vector2 + Vector2. Each element sums with the other vector's related element.
	Vector2D operator+(Vector2D Other) const
	{
		return Vector2D((X + Other.X), (Y + Other.Y));
	}

	// Vector2 + float. Add each element the float parameter.
	Vector2D operator+(T Other) const
	{
		return Vector2D((X + Other), (Y + Other));
	}

	// Vector2 * float. Multiplies each element with the float parameter.
	Vector2D operator*(T Other) const
	{
		return Vector2D((X * Other), (Y * Other));
	}

	// Vector2 * float. Divides each element with the float parameter.
	Vector2D operator/(T Other) const
	{
		return Vector2D((X / Other), (Y / Other));
	}

	Vector2D operator+=(Vector2D Other)
	{
		X += Other.X;
		Y += Other.Y;
		return Vector2D(X,Y);
	}
};

typedef Vector3D<> Vector3;
typedef Vector2D<> Vector2;
#endif // !TVECTOR_H