#pragma once
#include "Model_Factory.h"
#include "Load_Image.h"
#include "Player.h"

class Drawing_Manager
{
public:
	Drawing_Manager(void);
	~Drawing_Manager(void);
	Drawing_Manager(Model_Factory Models_factory);
	void Update(Player player);
	void DrawPlayer();
	void DrawLifeBar(vec3 PlayerPosition, float PlayerLife, float PlayerMaxLife);
	void Draw_Head(float AngleStart);
	void Draw(float CurrentTime,float GameSpeed);
	void RenderCollision(vec3 Position);
	float BaseFactor;
	float GameSpeed;
	float CurrentTime;
	int ColorEyes[2];
	vec3 PlayerPosition;
	vec3 PlayerRotation;
	float PlayerLife;
	float PlayerMaxLife;

	Model_Factory Models_factory;
};

