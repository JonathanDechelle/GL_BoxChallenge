#include "Model_Factory.h"


Model_Factory::Model_Factory()
{
}


Model_Factory::~Model_Factory()
{
}


void Model_Factory::Load_Models()
{
	vector<vec3> vertices;
	vector<vec2> uvs;
	vector<vec3> normals;

	objloader::LoadObj("Calf.obj", vertices, uvs, normals); 
	Calf_Model = TabVertex(vertices,uvs);
	objloader::LoadObj("Clavicle.obj", vertices, uvs, normals);  
	Clavicle_Model = TabVertex(vertices,uvs);
	objloader::LoadObj("Foot.obj",vertices,uvs,normals); 	
	Foot_Model = TabVertex(vertices,uvs);
	objloader::LoadObj("ForeArm.obj",vertices,uvs,normals); 	
	ForeArm_Model = TabVertex(vertices,uvs);
	objloader::LoadObj("Hand.obj",vertices,uvs,normals); 	
	Hand_Model = TabVertex(vertices,uvs);
	objloader::LoadObj("Head.obj",vertices,uvs,normals); 	
	Head_Model = TabVertex(vertices,uvs);
	objloader::LoadObj("Neck.obj",vertices,uvs,normals); 	
	Neck_Model = TabVertex(vertices,uvs);
	objloader::LoadObj("Pelvis.obj",vertices,uvs,normals); 	
	Pelvis_Model = TabVertex(vertices,uvs);
	objloader::LoadObj("Spine.obj",vertices,uvs,normals); 	
	Spine_Model = TabVertex(vertices,uvs);
	objloader::LoadObj("Thigh.obj",vertices,uvs,normals); 	
	Thigh_Model = TabVertex(vertices,uvs);
	objloader::LoadObj("UpperArm.obj",vertices,uvs,normals); 	
	UpperArm_Model = TabVertex(vertices,uvs);

	Models[Calf] = Calf_Model;
	Models[Clavicle] = Clavicle_Model;
	Models[Foot] = Foot_Model;
	Models[ForeArm] = ForeArm_Model;
 	Models[Hand] = Hand_Model;
	Models[Head] = Head_Model;
	Models[Neck] = Neck_Model;
	Models[Pelvis] = Pelvis_Model;
	Models[Spine] = Spine_Model;
	Models[Thigh] = Thigh_Model;
	Models[UpperArm] = UpperArm_Model;
	NbModels = 11;
}

void Model_Factory::Draw_Models(ModelType Type, int Texture)
{
	glUniformMatrix4fv(StaticHandle::mv_location, 1, GL_FALSE, StaticHandle::mv_matrix);
	glUniform1i(glGetUniformLocation(StaticHandle::rendering_program, "textureSelect"), Texture);
	
	if((int)Type != 0)
		glDrawArrays( GL_TRIANGLES, Models[Type - 1].NbVertex, Models[Type].NbVertex - Models[Type - 1].NbVertex);	
	else
		glDrawArrays( GL_TRIANGLES, 0, Models[0].NbVertex);	
}

void Model_Factory::Draw_Models(ModelType Type, int Texture, float Percent)
{
	glUniformMatrix4fv(StaticHandle::mv_location, 1, GL_FALSE, StaticHandle::mv_matrix);
	glUniform1i(glGetUniformLocation(StaticHandle::rendering_program, "textureSelect"), Texture);

	if((int)Type != 0)
		glDrawArrays( GL_TRIANGLES, Models[Type - 1].NbVertex, (Models[Type].NbVertex - Models[Type - 1].NbVertex) * Percent);	
	else
		glDrawArrays( GL_TRIANGLES, 0, Models[0].NbVertex * Percent);	
}
