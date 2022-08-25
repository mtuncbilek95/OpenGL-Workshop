#ifndef INPUTVALUES_H

#define INPUTVALUES_H
#include "Core.h"

VertexData Vertices[] = 
{
    {{ 0.5f,  0.5f, 0.0f},	{1.0f, 0.0f, 0.0f},	{1.0f, 1.0f}},
    {{ 0.5f, -0.5f, 0.0f},	{0.0f, 1.0f, 0.0f},	{1.0f, 0.0f}},
    {{-0.5f, -0.5f, 0.0f},	{0.0f, 0.0f, 1.0f},	{0.0f, 0.0f}},
    {{-0.5f,  0.5f, 0.0f},	{1.0f, 1.0f, 0.0f},	{0.0f, 1.0f}}
};

uint Indices[] = 
{
    0,1,3,
    1,2,3
};

#endif  // ! INPUTVALUES_H