#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Mesh.h>
#include <Renderer.h>
#include <Shader.h>
#include <Texture.h>
#include <Matrix44.h>
#include <Vector3.h>
#include <GLFW/glfw3.h>
#include <math.h>


class PlayerCamera;

class GameObject
{
public:
	igad::Mesh *my_mesh = nullptr;
	/*igad::Renderer *my_renderer = nullptr;*/
	igad::Shader *my_shader;
	igad::Texture *my_texture;
	
	float			my_radius;
	igad::Matrix44 my_model;

	//void Init(igad::Renderer* a_renderer);
	virtual void Render(PlayerCamera* camera, igad::Renderer* renderer);
	//virtual void update(float dt);
	//virtual void render(PlayerCamera *camera, igad::Renderer *renderer);

};

#endif	//gameobject_h