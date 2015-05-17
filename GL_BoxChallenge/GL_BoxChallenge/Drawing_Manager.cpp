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
	PlayerScale = 5.0f;
}

void Drawing_Manager::Draw_Head(float AngleStart)
{
	StaticHandle::mv_matrix =
		translate(PlayerPosition[0],PlayerPosition[1] + (PlayerPosition[1] * PlayerScale/10),PlayerPosition[2]) *
		rotate(AngleStart, 0.0f, 1.0f, 0.0f) *
		scale(PlayerScale,PlayerScale,PlayerScale); 

	Models_factory.Draw_Models(Models_factory.ModelType::Head,Load_Image::Type_Image::WoodBox);
}

void Drawing_Manager::Draw_Neck(float AngleStart)
{
	StaticHandle::mv_matrix =
		translate(PlayerPosition[0],PlayerPosition[1] + (PlayerPosition[1] * PlayerScale/10),PlayerPosition[2]) *
		rotate(AngleStart, 0.0f, 1.0f, 0.0f) *
		scale(PlayerScale,PlayerScale,PlayerScale); 

	Models_factory.Draw_Models(Models_factory.ModelType::Neck,Load_Image::Type_Image::WoodBox);
}

void Drawing_Manager::Draw_Pelvis(float AngleStart)
{
	StaticHandle::mv_matrix =
		translate(PlayerPosition[0],PlayerPosition[1] + (PlayerPosition[1] * PlayerScale/10),PlayerPosition[2]) *
		rotate(AngleStart, 0.0f, 1.0f, 0.0f) *
		scale(PlayerScale,PlayerScale,PlayerScale); 

	Models_factory.Draw_Models(Models_factory.ModelType::Pelvis,Load_Image::Type_Image::WoodBox);
}

void Drawing_Manager::Draw_UpperArm(float AngleStart)
{
	float Gap = PlayerScale/4;
	StaticHandle::mv_matrix =
		translate(PlayerPosition[0] - Gap ,PlayerPosition[1] + (PlayerPosition[1] * PlayerScale/10),PlayerPosition[2]) *
		rotate(AngleStart, 0.0f, 1.0f, 0.0f) *
		scale(PlayerScale,PlayerScale,PlayerScale); 

	Models_factory.Draw_Models(Models_factory.ModelType::UpperArm,Load_Image::Type_Image::WoodBox);
}

void Drawing_Manager::Draw_Clavicle(float AngleStart)
{
	StaticHandle::mv_matrix =
		translate(PlayerPosition[0],PlayerPosition[1] + (PlayerPosition[1] * PlayerScale/10),PlayerPosition[2]) *
		rotate(AngleStart, 0.0f, 1.0f, 0.0f) *
		scale(PlayerScale,PlayerScale,PlayerScale); 

	Models_factory.Draw_Models(Models_factory.ModelType::Clavicle,Load_Image::Type_Image::WoodBox);
}

void Drawing_Manager::DrawPlayer()
{
	Draw_Head(90);
	Draw_Neck(90);
	Draw_Pelvis(90);
	Draw_UpperArm(90);
	Draw_Clavicle(0);
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

