#pragma once
#include <Mesh.h>
#include <Renderer.h>
#include <Shader.h>
#include <Texture.h>
#include <Matrix44.h>
#include <Vector3.h>
#include <GLFW/glfw3.h>
#include "PlayerObject.h"
#include <DebugRenderer.h>
#include "GameObject.h"
#include "Camera.h"
#include "Input.h"
#include <time.h>
#include <stdlib.h>

class Stage;
class Tile;
//using namespace igad;
class Tron :public GameObject
{
public:
	Tron(float screenWidth, float screenHeight, bool);
	~Tron();
	//double xi; 
	//double dt; 
	//double last_xi; 
	//double last_dt; 
	//double acceleration;
	static Tron* GetInstance() { return _instance; }

	void Update(float dt);

	void HandleControls(int key, int scancode, int action, int mods);
	//the tileCollision function checks if a biker object is collisind with a tile that contains a light trail
	//If it is not colliding, draw a new tile in its previous position.
	//The argument choice indicates what color should the light trail be, according to the player.
	//1 is red, 2 is blue.
	void tileCollision(PlayerObject* biker, int choice);
	
	igad::Vector3 calculate_manhattan_distance(igad::Vector3 v1, igad::Vector3 v2);
	void FiniteStateMachine();
	void avoidLightTrail(PlayerObject*);
	void Render();
	
	void random_ai(float tron_speed, PlayerObject*);
	void hunter_ai(float tron_speed, PlayerObject*, PlayerObject*);
	void runner_ai(float tron_speed, PlayerObject*, PlayerObject*);
	void survival_ai(float tron_speed, PlayerObject*);
	
	void setSpeed(float);
	// igad::Shader* GetSimpleShader() { return _simpleShader; }
	float GetWidth() { return tron_width; }
	float GetHeight() { return tron_height; }

	igad::Texture*				 tile_texture;
	igad::Texture*				 tile_texture2;
	igad::Mesh*						tile_mesh;
private:
	//Camera*						_UIcamera;
	//ScoreLabel*					_score;
	igad::Renderer*				tron_renderer;
	PlayerObject*				blue_biker;
	PlayerObject*				red_biker;
	PlayerCamera*				tron_camera;
	Stage*						tron_arena;
	//Tile*						tron_tile;

	igad::Shader*				tron_shader;
	// igad::Shader*				_simpleShader;
	static Tron*				_instance;
	float						tron_width;
	float						tron_height;
	float tron_speed;
	bool first_tile;
	bool game_over;
	//int n;
	time_t timer1;
	time_t timer2;
	time_t timer3;
	time_t timer4;
	time_t timer5;
	//boolean array to determine if the tiles have been occupied by light trails or not. 1 or 'true' means it has been occupied.
	bool tiles_array[170][100];
	//this variable will keep track of the current state of the AI as follows:
	//old state is the state that was active before the function survival wa called. Since it is called everytime, it is convenient to 
	//test if a collision is about to happen then switich back to the previous state if there isn't.
	int old_state;
	int state;
	//keeps track of how many times the AI has been trapped and will be used to double the amount of time to hold on survival
	//mode until it is not trapped anymore and it is reset.
	int survival_count;

	bool tron_AI;
};


class Stage :public GameObject
{
public:
	Stage();
	~Stage();

	std::vector <Tile*> stored_positions;
	//Tile* stored_position;

protected:



	float fov;
	float dist;
	float a;
	float b;
	float ratio;
	float h;
	float w;
	float dist2;
};

class Tile :public GameObject
{
public:
	Tile();
	~Tile();
	//void createVertices(float vx, float vy, float vz, float side);
	//void Render(Camera* camera, igad::Renderer* renderer);

	//returns the x and z coordinates of the tiles
	float getTileX();
	float getTileZ();
	//Checks if there is a tile at the given indexes.
	//If there is already a tile, returns true.
	//If there is not a tile, marks the given tile as created -  Although it doesn't create it - and returns false.
	void selectTexture(int choice);


private:
	//igad::Mesh* tile_mesh = nullptr;

	//std::vector<igad::VertexFormat> tile_positions;
	float tile_x_coordinate;
	float tile_z_coordinate;
	//This array represents the tiles that were already occupied by the light trail.


};




//class Input
//{
//	public:
//		Input();
//		~Input();
//
//
//};