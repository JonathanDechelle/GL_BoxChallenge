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

void Drawing_Manager::DrawLifeBar(vec3 PlayerPosition, float PlayerLife, float PlayerMaxLife)
{
	StaticHandle::mv_matrix = translate(vec3(PlayerPosition[0],PlayerPosition[1],-19.0f) + vec3(0.0f,14.0f,5.0f)) * 
		//rotate(90.0f, 1.0f, 0.0f, 0.0f) * content
		rotate(0.0f,1.0f,0.0f,0.0f) * 
		scale(14.0f,7.0f,10.0f);

	float LifeRatio = PlayerLife / PlayerMaxLife;

	//Models_factory.Draw_Models(Models_factory.ModelType::LifeBar_Frame,Load_Image::WoodBox);
	//Models_factory.Draw_Models(Models_factory.ModelType::LifeBar_Content,Load_Image::LifeBarContent,LifeRatio);
}

void Drawing_Manager::RenderCollision(vec3 Position)
{
	//StaticHandle::mv_matrix = translate(Position) * scale(2.0f);
	//Models_factory.Draw_Models(Models_factory.ModelType::Cube,Load_Image::Type_Image::Leaf); 
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
	//DrawLifeBar(PlayerPosition,PlayerLife,PlayerMaxLife);
}

