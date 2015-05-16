#pragma once
#include "DATA.h"
#include "objloader.h"
#include "..\Include\glew.h"
#include "..\Include\glut.h"
#include "StaticHandle.h"

class Model_Factory
{
public:
	Model_Factory();
	~Model_Factory(void);
	enum ModelType
	{
		Calf,
		Clavicle,
		Foot,
		ForeArm,
		Hand,
		Head,
		LifeBar_Frame,
		LifeBar_Content,
		Neck,
		Pelvis, 
		Spine,
		Thigh,
		UpperArm
	};
	TabVertex Calf_Model;
	TabVertex Clavicle_Model;
	TabVertex Foot_Model;
	TabVertex ForeArm_Model;
	TabVertex Hand_Model;
	TabVertex LifeBar_Content_Model;
	TabVertex LifeBar_Frame_Model;
	TabVertex Head_Model;
	TabVertex Neck_Model;
	TabVertex Pelvis_Model;
	TabVertex Spine_Model;
	TabVertex Thigh_Model;
	TabVertex UpperArm_Model;
	TabVertex Models[13];
	int NbModels;

	void Load_Models();
	void Draw_Models(ModelType Type, int Texture);
	void Draw_Models(ModelType Type, int Texture, float Percent);
};

