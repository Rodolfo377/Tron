#include "World.h"
#include "PlayerObject.h"
#include <iostream>
#include <DebugRenderer.h>

#define M_PI 3.14159265358979323846

//using namespace igad;
using namespace std;

PlayerObject::PlayerObject(int player)
{
	
	my_mesh = new igad::Mesh("./Assets/Models/red_light_cycle.obj");
	first_tile = true;
	//Loads different textures according to the object: e.g. Player 0 will be blue and Player 1 will be red
	if (player == 0)
	{
		
		my_texture = new igad::Texture("./Assets/Textures/white.png");
		biker_current_position = igad::Vector3(139, 0, 0);
	}
	else
	{
		
		//my_mesh = new igad::Mesh("./Assets/Models/blue_light_cycle.obj");
		my_texture = new igad::Texture("./Assets/Textures/white.png");
		biker_current_position = igad::Vector3(-139, 0, 0);
	}

	my_radius = 4.0f;
	
}



void PlayerObject::update(float dt)
{
	
	//biker_last_position = biker_current_position;
	//biker_velocity +=  (biker_force / mass)*dt;

	//biker_current_position = biker_last_position + (biker_velocity*dt);
	//std::cout << "biker velocity "<<biker_velocity.x << "\n";
	//doCollision();
	biker_current_position += biker_velocity * dt;
	my_model.SetTranslation(biker_current_position);

}



//void PlayerObject::doCollision()
//{
//	/*****Screen Collision********/
//	//Collision with  margin of the screen
//	if (my_model.GetTranslation().x < -140)
//	{
//		setVelocity(igad::Vector3(0, 0, biker_velocity.z));
//		
//	}
//	//Collision with bottom margin of the screen
//	if (my_model.GetTranslation().z < -78.75)
//	{
//		setVelocity(igad::Vector3(biker_velocity.x, 0, 0));
//	}
//	//Collision with left margin of the screen
//	if (my_model.GetTranslation().x > 140)
//	{
//		setVelocity(igad::Vector3(0, 0, biker_velocity.z));  
//	}
//	//Collision with top margin of the screen
//	if (my_model.GetTranslation().z > 78.75)
//	{
//		
//		setVelocity(igad::Vector3(biker_velocity.x, 0, 0));
//	}
//}

bool PlayerObject::doCollision(int tile_index_x, int tile_index_z, int biker_tile_index_x, int biker_tile_index_z)
{
	bool collision = false;



	if (biker_tile_index_x == tile_index_x && biker_tile_index_z == tile_index_z)
	{
		//std::cout << "red biker on a red tile!!!\n\n";
		collision = true;
	}
	return collision;
}

void PlayerObject::setVelocity(igad::Vector3 &speed)
{
	biker_velocity = speed;
	//
	if (speed.x > 0)
	{   
		my_model = igad::Matrix44::CreateRotateY(igad::DegToRad(90));
	}

	else if (speed.x < 0)
	{
		my_model = igad::Matrix44::CreateRotateY(igad::DegToRad(270));
	}

	else if (speed.z > 0)
	{
		my_model = igad::Matrix44::CreateRotateY(igad::DegToRad(0));
	}

	else if (speed.z < 0)
	{
		my_model = igad::Matrix44::CreateRotateY(igad::DegToRad(180));
	}
}

igad::Vector3 PlayerObject::giveBikerPosition()
{
	return biker_current_position;
}

void PlayerObject::avoidWallCollision(float dt)
{
	//Avoid collision with the sides of the screen and tells the model to go up or down depending on where there is more space.
	if (biker_current_position.x + biker_velocity.x*dt > 140  || biker_current_position.x + biker_velocity.x*dt < -140 )
	{
		//std::cout << "avoid collision with the left or right screen sides.\n";
		//abs((float)biker_velocity.x)) will get whatever the current speed is and make the change in direction work regardless of 
		//the speed value. This makes it easier to maintain.

		//If there is more space to go up than to go down, go up
		if (biker_current_position.z <= 0)
		{
			setVelocity(igad::Vector3(0, 0, abs((float)biker_velocity.x)));
		}

		//If there is more space to go down than to go up, go down
		if (biker_current_position.z > 0)
		{
			setVelocity(igad::Vector3(0, 0, -abs((float)biker_velocity.x)));
		}
	}

	//Avoid collision with the top and bototm of the screen and tells the model to go left or right depending on where there is more space.
	else if (biker_current_position.z + biker_velocity.z*dt > 78.75 || biker_current_position.z + biker_velocity.z*dt < -78.75)
	{
		//std::cout << "AI x position: "<< biker_current_position.x <<" AI z position: " << biker_current_position.z << "\n";
		//std::cout << "AI x velocity: " << biker_velocity.x << " bike z velocity: " << biker_velocity.z << "\n";
		//setVelocity(igad::Vector3(-50, 0, 0));

		//If there is more space to go right than to go left, go right
		if (biker_current_position.x <= 0)
		{
			setVelocity(igad::Vector3(abs((float)biker_velocity.z), 0, 0));
		}

		//If there is more space to go left than to go right, go left
		if (biker_current_position.x > 0)
		{
			setVelocity(igad::Vector3(-abs((float)biker_velocity.z), 0, 0));
		}
	}
}

igad::Vector3 PlayerObject::getVelocity()
{
	return biker_velocity;
}











