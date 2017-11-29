#pragma once

#include "GameObject.h"
#include <time.h>
#include <stdlib.h>
class World;

class PlayerObject : public GameObject
{
public:
	PlayerObject(int player);
	//void update(double xi, double dt, double &last_xi, double &last_dt, double &acceleration);
	void update(float dt);
	//void render(PlayerCamera *camera, igad::Renderer *renderer);
	bool doCollision(int tile_index_x, int tile_index_z, int biker_tile_index_x, int biker_tile_index_z);
	void setVelocity(igad::Vector3 &velocity);
	igad::Vector3 giveBikerPosition();
	void avoidWallCollision(float dt);
	igad::Vector3 getVelocity();

	igad::Matrix44& GetTransform() { return my_model; }
	
	

	

	bool first_tile;
	int old_biker_tile_x;
	int old_biker_tile_z;
	int biker_tile_x;
	int biker_tile_z;
	
private:

	/*double xi;
	double dt;
	double last_xi;
	double last_dt; */
	igad::Vector3 biker_acceleration;
	int player;
	igad::Vector3 biker_velocity;
	float mass;
	igad::Vector3 biker_force;
	igad::Vector3  biker_current_position;
	igad::Vector3  biker_last_position;
	std::vector <float> stored_positions;
	time_t timer1, timer2;
};