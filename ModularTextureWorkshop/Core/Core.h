#include <stdio.h>
#include "Vector.h"

#define WIDTH	600
#define HEIGHT	600

#define WINDOWNAME	"ModularTexture"

typedef signed char        int8;
typedef short              int16;
typedef int                int32;
typedef long long          int64;
typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;
typedef unsigned long long uint64;


struct VertexShader
{
	Vector3 Vertices;
	Vector3 Colors;
	Vector2 Textures;
};

VertexShader Baris[4] = 
{
	{{ 0.5f,  0.5f, 0.0f},	{1.0f, 0.0f, 0.0f},	{1.0f, 1.0f}},
	{{ 0.5f, -0.5f, 0.0f},	{0.0f, 1.0f, 0.0f},	{1.0f, 0.0f}},
	{{-0.5f, -0.5f, 0.0f},	{0.0f, 0.0f, 1.0f},	{0.0f, 0.0f}},
	{{-0.5f,  0.5f, 0.0f},	{1.0f, 1.0f, 0.0f},	{0.0f, 1.0f}}
}
