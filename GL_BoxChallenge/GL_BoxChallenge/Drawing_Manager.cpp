#include "Drawing_Manager.h"


Drawing_Manager::Drawing_Manager(void)
{
}


Drawing_Manager::~Drawing_Manager(void)
{
}

Drawing_Manager::Drawing_Manager(Model_Factory Models_factory)
{
	this->Models_factory = Models_factory;
	BaseFactor = 10000;
}

void Drawing_Manager::Draw_Head(float AngleStart)
{
	float Scale = 5;
	StaticHandle::mv_matrix =
		translate(PlayerPosition[0],PlayerPosition[1] + (PlayerPosition[1] * Scale/10),PlayerPosition[2]) *
		rotate(AngleStart, 0.0f, 1.0f, 0.0f) *
		scale(Scale,Scale,Scale); 

	Models_factory.Draw_Models(Models_factory.ModelType::Head,Load_Image::Type_Image::WoodBox);
}

void Drawing_Manager::DrawPlayer()
{
	Draw_Head(90);
}

void Drawing_Manager::Update(Player player)
{
	PlayerPosition = player.Position;
	PlayerRotation = player.Rotation;
	PlayerLife = player.Life;
	PlayerMaxLife = player.MaxLife;
}

void Drawing_Manager::Draw(float CurrentTime,float GameSpeed)
{
	this->CurrentTime = CurrentTime;
	this->GameSpeed = GameSpeed;

	DrawPlayer();
}

