#pragma once
#include "..\Include\glew.h"
#include "..\Include\glut.h"
#include "vmath.h"

class StaticHandle
{
public:
	static GLuint rendering_program;
	static GLuint mv_location;
	static GLuint proj_location;
	static GLuint lookAtMatrix_Location;
	static float CurrentTime;
	static float Speed;
	static float GameSpeed;
	static mat4 mv_matrix;
	static mat4 proj_matrix;
	vec3 PlayerDirectionDamage;
	static vec3 Get_projected_Position(vec3 Position);
};

