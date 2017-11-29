#include "World.h"


Tron* Tron::_instance = nullptr;
//using namespace igad;
Tron::Tron(float screenWidth, float screenHeight, bool use_AI)
{
	//Tile::numberOfTiles = 0;

	_instance = this;
	//n = 0;
	//xi = 0;
	//dt = 0;
	//last_xi = 0;
	//last_dt = 0;
	//acceleration = 0;

	tron_AI = use_AI;

	float fov = 60.0f;
	float dist = 100.0f;
	float ratio = screenWidth / screenHeight;
	tron_height = tan(igad::DegToRad(fov * 0.5f)) * dist;
	tron_width = tron_height * ratio;
	//std::cout << "tiles_array[0][0] = " << tiles_array[0][0] << "\n";
	setSpeed(40.0f);
	//std::cout << "height: " << tron_height << " width: " << tron_width << "\n";

	red_biker = new PlayerObject(0);
	//sets the AI default direction to the left
	red_biker->setVelocity(igad::Vector3(-tron_speed, 0, 0));
	

	blue_biker = new PlayerObject(1);
	//sets the default player direction to the right
	blue_biker->setVelocity(igad::Vector3(tron_speed, 0, 0));

	tron_camera = new PlayerCamera(blue_biker);
	tron_shader = new igad::Shader("./Assets/Basic3D.vsh", "./Assets/Basic3D.fsh");
	tron_renderer = new igad::Renderer(tron_shader);
	tron_arena = new Stage();


	igad::Matrix44 view = igad::Matrix44::CreateLookAt(igad::Vector3(0, dist, 0), igad::Vector3(), igad::Vector3(0, 0, 1));
	igad::Matrix44 projection = igad::Matrix44::CreatePerspective(igad::DegToRad(fov), ratio, 0.1f, 2000.0f);

	tile_texture = new igad::Texture("./Assets/Textures/tron_tile.png");
	tile_texture2 = new igad::Texture("./Assets/Textures/tron_tile_blue.png");

	tile_mesh = new igad::Mesh("./Assets/Models/my_cube.obj");

	tron_camera->SetView(view);
	tron_camera->SetProjection(projection);

	first_tile = true;
	game_over = false;
	//sets initial state to HUNTER.
	state = 0;
	old_state = state;
	timer1 = time(NULL);
	timer4 = time(NULL);
	survival_count = 0;
}

Tron::~Tron()
{
	/*std::cout << "cleaning up after my program...\n";
	std::cout << "red biker memory 1: " << red_biker << "\n";*/
	/*tron_arena->stored_positions[0]->~Tile();
	tron_arena->~Stage();
	*/
	delete red_biker;
	red_biker = nullptr;
	/*
	std::cout << "red biker memory 2: " << red_biker << "\n";*/

	delete tron_renderer;
	tron_renderer = nullptr;

	delete blue_biker;
	blue_biker = nullptr;

	delete tron_camera;
	tron_camera = nullptr;

	delete tron_arena;
	tron_arena = nullptr;

	delete tron_shader;
	tron_shader = nullptr;
}



void Tron::Update(float dt)
{

	

	//Update camera's position
	tron_camera->Update(dt);

	if (!game_over)
	{
		/*AI*/
	
		if (tron_AI)
		{
			FiniteStateMachine();
			red_biker->avoidWallCollision(dt);
		}

			/*Update red biker's position*/
			red_biker->update(dt);
			/*Update blue biker's position*/
			blue_biker->update(dt);
			
			tileCollision(blue_biker, 2);
			tileCollision(red_biker, 1);

			if (red_biker->biker_tile_x == blue_biker->biker_tile_x && red_biker->biker_tile_z == blue_biker->biker_tile_z)
			{
				game_over = true;
				std::cout << "\n\n***********DRAW************\n\n";
			}

	
		}
	

}//closes update









void Tron::Render()
{
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	//glDepthFunc(GL_LESS);
	//glFrontFace(GL_CW);
	tron_renderer->Begin(tron_camera->View(), tron_camera->Projection());

	tron_arena->Render(tron_camera, tron_renderer);

	for (int i = 0; i < tron_arena->stored_positions.size(); i++)
	{
		tron_arena->stored_positions[i]->Render(tron_camera, tron_renderer);
	}



	blue_biker->Render(tron_camera, tron_renderer);
	red_biker->Render(tron_camera, tron_renderer);
	//_blaster1->Render(_camera, _renderer);


	tron_renderer->End();


	auto m = tron_camera->ViewProjection();
	igad::gDebugDraw3D.Draw(m);
	igad::gDebugDraw3D.Clear();

	//glDisable(GL_DEPTH_TEST);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// _score->Render(_UIcamera);
}

void Tron::setSpeed(float speed)
{
	tron_speed = speed;
}




void Tron::HandleControls(int key, int scancode, int action, int mods)
{

	if (!tron_AI)
	{
		//Controls red_biker
		if (key == GLFW_KEY_W && action == GLFW_PRESS)
		{
			//std::cout << "W\n";
			igad::Vector3 direction(0, 0, tron_speed);
			red_biker->setVelocity(direction);

		}

		if (key == GLFW_KEY_D && action == GLFW_PRESS)
		{
			//std::cout << "D\n";
			igad::Vector3 direction(-tron_speed, 0, 0);
			red_biker->setVelocity(direction);

		}
		if (key == GLFW_KEY_S && action == GLFW_PRESS)
		{
			//std::cout << "S\n"; 
			igad::Vector3 direction(0, 0, -tron_speed);
			red_biker->setVelocity(direction);

		}
		if (key == GLFW_KEY_A && action == GLFW_PRESS)
		{
			//std::cout << "A\n";
			igad::Vector3 direction(tron_speed, 0, 0);
			red_biker->setVelocity(direction);

		}
	}

	//Controls blue_biker
	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
	{
		//std::cout << "W\n";
		igad::Vector3 direction(0, 0, tron_speed);
		blue_biker->setVelocity(direction);

	}

	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
	{
		//std::cout << "D\n";
		igad::Vector3 direction(-tron_speed, 0, 0);
		blue_biker->setVelocity(direction);

	}
	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
	{
		//std::cout << "S\n"; 
		igad::Vector3 direction(0, 0, -tron_speed);
		blue_biker->setVelocity(direction);

	}
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
	{
		//std::cout << "A\n";
		igad::Vector3 direction(tron_speed, 0, 0);
		blue_biker->setVelocity(direction);

	}
	
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		//RESET THE GAME
		//std::cout << "A\n";
		game_over = false;


		for (int i = 0; i < 170; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				tiles_array[i][j] = 0;
			}
		}


		delete red_biker;
		red_biker = nullptr;
		red_biker = new PlayerObject(0);

		delete blue_biker;
		blue_biker = nullptr;
		blue_biker = new PlayerObject(1);

		//std::cout << "stored positions size: before clear: " << tron_arena->stored_positions.size() << "\n";
		tron_arena->stored_positions.clear();
		//std::cout << "stored positions size: after clear: " << tron_arena->stored_positions.size() << "\n";
		tron_arena->stored_positions.swap(std::vector <Tile*>(tron_arena->stored_positions));
		//std::cout << "stored positions size: after swap: " << tron_arena->stored_positions.size() << "\n";

		blue_biker->setVelocity(igad::Vector3(tron_speed, 0, 0));
		red_biker->setVelocity(igad::Vector3(-tron_speed, 0, 0));

		//std::cout << "blue biker pos: " << blue_biker->giveBikerPosition().x << "\n\n";
		
		//n = 0;
	}

}

void Tron::tileCollision(PlayerObject * biker, int choice)
{
	//std::cout << "difftime = " << difftime(timer_2, timer_1) <<"\n";
	float tile_size = 12.1885f / 5.f;



	float biker_tile_size = 8.88f / 5.f;
	biker->biker_tile_x = (int)biker->giveBikerPosition().x / biker_tile_size;
	biker->biker_tile_z = (int)biker->giveBikerPosition().z / biker_tile_size;

	//std::cout << "red biker_tile_z: " << red_biker->biker_tile_z << "\n";


	if (biker->first_tile)
	{
		biker->old_biker_tile_x = biker->biker_tile_x;
		biker->old_biker_tile_z = biker->biker_tile_z;
		biker->first_tile = false;
	}

	//bike left previous tile
	if (biker->biker_tile_x != biker->old_biker_tile_x || biker->biker_tile_z != biker->old_biker_tile_z)
	{

		//checking tile collision
		int n_pos_x = biker->biker_tile_x + 80;
		int n_pos_z = biker->biker_tile_z + 45;

		if (tiles_array[n_pos_x][n_pos_z] == true
			|| abs(biker->biker_tile_x) > 78
			||abs(biker->biker_tile_z) > 43)
		{
			if (choice == 1)
			{
				std::cout << "\n*********Blue biker won.*********\n";
			}
			if (choice == 2)
			{
				std::cout << "\n*********Red biker won.***********\n";
			}
			game_over = true;
			std::cout << "game over.\n";
		}

		//std::cout << "bike left previous tile\n\n";
		/*int i_x = (int)biker_tile_x*tile_size + tile_shift_x;
		int i_z = (int)biker_tile_z*tile_size + tile_shift_z;*/
		//bike on empty tile

		/*if (tron_arena->stored_positions.size() >= 1)
		{
			n++;
		}*/
		
		//std::cout << "first tile is created!\n\n";
		Tile* tile = new Tile();

		tron_arena->stored_positions.push_back(tile);

		int n = tron_arena->stored_positions.size() - 1;

		tron_arena->stored_positions[n]->selectTexture(choice);
		
		igad::Vector3 position = igad::Vector3(biker->old_biker_tile_x*tile_size, -49, biker->old_biker_tile_z*tile_size);

		igad::Matrix44 scale = igad::Matrix44::CreateScale(igad::Vector3(2.f, 5.f, 2.f));
		tron_arena->stored_positions[n]->my_model = scale;

		igad::Matrix44 translation = igad::Matrix44();
		translation.SetTranslation(position);

		tron_arena->stored_positions[n]->my_model.SetTranslation(position);

		tiles_array[biker->old_biker_tile_x + 80][biker->old_biker_tile_z + 45] = true;

		//resets the previous tiles to the new one
		biker->old_biker_tile_x = biker->biker_tile_x;
		biker->old_biker_tile_z = biker->biker_tile_z;
	}

}


igad::Vector3 Tron::calculate_manhattan_distance(igad::Vector3 v1, igad::Vector3 v2)
{
	igad::Vector3 manhattan_d;

	manhattan_d.x = abs(v1.x - v2.x);
	manhattan_d.y = abs(v1.y - v2.y);
	manhattan_d.z = abs(v1.z - v2.z);

	return manhattan_d;
}

void Tron::FiniteStateMachine()
{
	timer2 = time(NULL);
	//local variable that assures the state hunter only gets set once.
	bool first_Hunter = false;
	//switch to hunter mode after 5 seconds have passed since the game started
	if (difftime(timer2, timer1) == 5 && !first_Hunter)
	{
		state = 0;
		old_state = 0;
		first_Hunter = true;
	}
	//std::cout << "delta time: " << difftime(timer2, timer4) << "\n";
	
	///std::cout << "start of FSM\n\n";

	//State Machine
	switch (state)
	{
		
	case 0://hunter
		//std::cout << "HUNTER\n";
		hunter_ai(tron_speed, red_biker, blue_biker);
		break;

	case 1:	//runner
		//std::cout << "RUNNER\n";
		runner_ai(tron_speed, red_biker, blue_biker);
		break;
		
	case 2: // survival
		//std::cout << "SURVIVAL\n";
		survival_ai(tron_speed, red_biker);
		break;
		
	case 3: //random
		//std::cout << "RANDOM\n";
		random_ai(tron_speed, red_biker);
		old_state = 3;
		break;
	}

	//checks for collisions anyway. If the state is not survival.
	if (state != 2)
		survival_ai(tron_speed, red_biker);

	//std::cout << "state "<<state << "\n";
}

void Tron::avoidLightTrail(PlayerObject* biker)
{
	//If moving to the left or right
	//std::cout << "Avoid light trail\n\n";
	if (biker->getVelocity().x != 0)
	{
			//std::cout << "****imminent horizontal collision!\n";
			//check which direction allows more free space
			float temp_up = 0;
			float temp_down = 0;

			for (int i = 0; i < 10; i++)
			{
				if (temp_up >= 0)
				{	//in case it is free, increase points for that direction
					if (tiles_array[biker->biker_tile_x + 80][biker->biker_tile_z + i + 45] == 0)
						temp_up++;
					//in case it goes out of the screen bounds, make that direction invalid
					if (biker->biker_tile_z + i >= 43)
						temp_up = -5;
					//in case it leads to a light trail, make that direction invalid
					if (tiles_array[biker->biker_tile_x + 80][biker->biker_tile_z + i + 45] == 1)
						temp_up = -5.f/i;
				}
				if (temp_down >= 0)
				{
					if (tiles_array[biker->biker_tile_x + 80][biker->biker_tile_z - i + 45] == 0)
						temp_down++;
					if (biker->biker_tile_z - i + 45 == 0 || biker->biker_tile_z - i <= -43)
						temp_down = -5;
					if (tiles_array[biker->biker_tile_x + 80][biker->biker_tile_z - i + 45] == 1)
						temp_down = -5.f/i;
				}
			}

			//std::cout << "up: " << temp_up << " down: " << temp_down << "\n";
			//if there is more room to the top instead of to the bottom:
			if (temp_up > temp_down)
			{//go up
				//std::cout << "going up!\n\n";
				biker->setVelocity(igad::Vector3(0, 0, tron_speed));
			}
			else
			{//go down
				//std::cout << "going down!\n\n";
				biker->setVelocity(igad::Vector3(0, 0, -tron_speed));
			}

	}//going to the left or right

	 //If moving up or down
		else if(biker->getVelocity().z != 0)
		{
			//std::cout << "****imminent vertical collision!\n";
			//check which direction allows more free space
			int temp_left = 0;
			int temp_right = 0;

			for (int i = 0; i < 10; i++)
			{
				if (temp_left >= 0)
				{
					//in case it is free, increase points for that direction
					if (tiles_array[biker->biker_tile_x + i + 80][biker->biker_tile_z + 45] == 0)
						temp_left++;
					//in case it goes out of the screen bounds, make that direction invalid
					if (biker->biker_tile_x + i >= 78)
						temp_left = -5;
					//in case it leads to a light trail, make that direction invalid
					if (tiles_array[biker->biker_tile_x + i + 80][biker->biker_tile_z + 45] == 1)
						temp_left = -5.f/i;
				}
				if (temp_right >= 0)
				{
					if (tiles_array[biker->biker_tile_x - i + 80][biker->biker_tile_z + 45] == 0)
						temp_right++;
					if (biker->biker_tile_x - i + 80 == 0 || biker->biker_tile_x - i <= -78)
						temp_right = -5;
					if (tiles_array[biker->biker_tile_x - i + 80][biker->biker_tile_z + 45] == 1)
						temp_right = -5.f/i;
				}
			}

			//std::cout << "left: " << temp_left << " right: " << temp_right << "\n";
			//if there is more room to the top instead of to the bottom:
			if (temp_right > temp_left)
			{//go right
				//std::cout << "going right!\n\n";
				biker->setVelocity(igad::Vector3(-tron_speed, 0, 0));
			}
			else
			{//go left
				//std::cout << "going left!\n\n";
				//
				biker->setVelocity(igad::Vector3(tron_speed, 0, 0));
			}
			timer3 = time(NULL);

			if (state == 1)
			{
				//std::cout << "****trapped!!!\n\n";
				state = 2;
				old_state = 2;
				timer5 = time(NULL);
				survival_count++;
				//std::cout << "wait time: " << 2*survival_count << "\n\n";
			}
			else
			{
				//std::cout << "changing to RUNNER...\n";
				state = 1;
				old_state = 1;
			}
			
	}//going to the left or right

	
	//switches state to Runner

}


void Tron::random_ai(float tron_speed, PlayerObject* player)
{

	timer2 = time(NULL);

	if (difftime(timer2, timer1) > 1)
	{
		timer1 = timer2;

		igad::Vector3 new_velocity = player->getVelocity();
		srand(timer1);

		//if it is running on the left wall, go to the right.
		if (player->biker_tile_x == 78 && player->getVelocity().x == 0)
		{

			new_velocity = igad::Vector3(-tron_speed, 0, 0);
		}
		//if it is running on the right wall, go to the left.
		else if (player->biker_tile_x == -78 && player->getVelocity().x == 0)
		{
			new_velocity = igad::Vector3(tron_speed, 0, 0);
		}
		//if it is running on the top wall, go to the bottom.
		else if (player->biker_tile_z == 43 && player->getVelocity().z == 0)
		{
			new_velocity = igad::Vector3(0, 0, -tron_speed);
		}
		//if it is running on the bottom wall, go to the top.
		else if (player->biker_tile_z == -43 && player->getVelocity().z == 0)
		{
			new_velocity = igad::Vector3(0, 0, tron_speed);
		}

		//else, choose a random move.
		else
		{
			//get a new random direction as long as it is not the opposite of the last one.
			do
			{
				int direction = rand() % 4 + 1;

				//std::cout << "while...direction: " << direction << "\n";
				switch (direction)
				{
					//go up
				case 1:
					new_velocity = igad::Vector3(0, 0, tron_speed);
					break;
					//go right
				case 2:
					new_velocity = igad::Vector3(-tron_speed, 0, 0);
					break;
					//go down
				case 3:
					new_velocity = igad::Vector3(0, 0, -tron_speed);
					break;
					//go left
				case 4:
					new_velocity = igad::Vector3(tron_speed, 0, 0);
					break;
				}//switch
			} while (player->getVelocity().x == -new_velocity.x || player->getVelocity().z == -new_velocity.z);
		}//else

		 //std::cout << biker->getVelocity().x << " " << new_velocity.x << " " << biker->getVelocity().z << " " << new_velocity.z << "\n";
		player->setVelocity(new_velocity);

		

	}
	
}

void Tron::hunter_ai(float tron_speed, PlayerObject* player1, PlayerObject* player2)
{
	igad::Vector3 direction;
	
	
	//If horizontal manhattan distance is greater than vertical, move on the horizontal
	 if (calculate_manhattan_distance(player1->giveBikerPosition(), player2->giveBikerPosition()).x >=
		calculate_manhattan_distance(player1->giveBikerPosition(), player2->giveBikerPosition()).z)
	{
		// std::cout << "chasing player2 on the horizontal: ";
		//chase player2
		 if (player1->giveBikerPosition().x > player2->giveBikerPosition().x)
		 {
			 //std::cout << "chasing player 2 on the right\n";
			 direction = igad::Vector3(-tron_speed, 0, 0);
		 }
		 else
		 {
			// std::cout << "chasing player 2 on the left\n";
			 direction = igad::Vector3(tron_speed, 0, 0);
		 }
		 player1->setVelocity(direction);
	}
	//If horizontal manhattan distance is less than vertical, move on the vertical
	else if (calculate_manhattan_distance(player1->giveBikerPosition(), player2->giveBikerPosition()).x <
		calculate_manhattan_distance(player1->giveBikerPosition(), player2->giveBikerPosition()).z)
	{
		//chase player2
		//std::cout << "chasing player 2 on the vertical: ";
		if (player1->giveBikerPosition().z > player2->giveBikerPosition().z)
		{
			//std::cout << "chasing down\n";
			direction = igad::Vector3(0, 0, -tron_speed);
		}
		else
		{
			//std::cout << "chasing up\n";
			direction = igad::Vector3(0, 0, tron_speed);
		}
		player1->setVelocity(direction);
	}
	

	
}

//player 1 is the one whose behaviour is determined by AI
void Tron::runner_ai(float tron_speed, PlayerObject* player1, PlayerObject* player2)
{
	igad::Vector3 direction;

	
	//After AI player has distanced itself 30 tiles away from the other player, go back to hunter state.
	if (difftime(time(NULL), timer3) == 2)
	{
		timer3 = time(NULL);
		//std::cout << "****changed to hunter!\n";
		state = 0;
		old_state = 0;
	}
	//If horizontal manhattan distance is greater than vertical, move on the vertical
	else if (calculate_manhattan_distance(player1->giveBikerPosition(), player2->giveBikerPosition()).x >=  
		calculate_manhattan_distance(player1->giveBikerPosition(), player2->giveBikerPosition()).z )
	{
		//std::cout << "fleeing from player on vertical\n\n";
		//flee form player2
		if (player1->giveBikerPosition().z > player2->giveBikerPosition().z)
			direction = igad::Vector3(0, 0, tron_speed);
		else
		{
			direction = igad::Vector3(0, 0, -tron_speed);
		}
		player1->setVelocity(direction);
	}
	//If horizontal manhattan distance is less than vertical, move on the horizontal
	else if (calculate_manhattan_distance(player1->giveBikerPosition(), player2->giveBikerPosition()).x <
		calculate_manhattan_distance(player1->giveBikerPosition(), player2->giveBikerPosition()).z)
	{
		//std::cout << "fleeing from player on horizontal\n\n";
		//flee from player2
		if (player1->giveBikerPosition().x > player2->giveBikerPosition().x)
			direction = igad::Vector3(tron_speed, 0, 0);
		else
		{
			direction = igad::Vector3(-tron_speed, 0, 0);
		}
		player1->setVelocity(direction);
	}

	
}

void Tron::survival_ai(float tron_speed, PlayerObject *player)
{
	//the state is initially set to 1, but if the player is about to collide in any direction with a light trail it then turns to 2.
	//std::cout << "survival!\n";
	state = old_state;

	//local variables that inform the direction in which the bike is moving
	igad::Vector2 red_direction;
	igad::Vector2 blue_direction;
	igad::Vector2 red_position;
	igad::Vector2 blue_position;
	for (int j = 1; j <= 3; j++)
	{
		//If it is about to collide with a light trail, switch to survival state
		if (player->getVelocity().x < 0)
		{
			if (tiles_array[player->biker_tile_x - j + 80][player->biker_tile_z + 45] == 1)
			{
				avoidLightTrail(player);
				state = 2;
			}

		}
		else if (player->getVelocity().x > 0)
		{
			if (tiles_array[player->biker_tile_x + j + 80][player->biker_tile_z + 45] == 1)
			{
				avoidLightTrail(player);
				state = 2;
			}

		}
		else if (player->getVelocity().z > 0)
		{
			if (tiles_array[player->biker_tile_x + 80][player->biker_tile_z + j + 45] == 1)
			{
				avoidLightTrail(player);
				state = 2;
			}
		}
		else if (player->getVelocity().z < 0)
		{
			if (tiles_array[player->biker_tile_x + 80][player->biker_tile_z - j + 45] == 1)
			{
				avoidLightTrail(player);
				state = 2;
			}
		}
	}
	//Timeout of "trapped" condition: wait time increases exponentially, and if the waiting time is reached, reset the state to hunter. 
	//Also reset survival_count.
	if (difftime(time(NULL), timer5) == 2 * survival_count)
	{
		//std::cout << "wait time reached!\n\n";
		state = 0;
		old_state = 0;
		survival_count = 0;
	}


	//If the manhattan distance is shorter than or equal to 10 in every direction, hold on survival state for 6 seconds.
	if (calculate_manhattan_distance(red_biker->giveBikerPosition(), blue_biker->giveBikerPosition()).Magnitude() <= 10)
	{
		//std::cout << "target locked...survival mode!";
		state = 2;
		old_state = 2;
		timer5 = time(NULL);
		survival_count = 3;

		if (red_biker->getVelocity().x < 0)
			red_direction = igad::Vector2(-1, 0);
		else if (red_biker->getVelocity().x > 0)
			red_direction = igad::Vector2(1, 0);
		else if (red_biker->getVelocity().z > 0)
			red_direction = igad::Vector2(0, 1);
		else if (red_biker->getVelocity().z < 0)
			red_direction = igad::Vector2(0, -1);

		blue_position = igad::Vector2(blue_biker->biker_tile_x, blue_biker->biker_tile_z);
		red_position = igad::Vector2(red_biker->biker_tile_x, red_biker->biker_tile_z);

		for (int i = 1; i <= 5; i++)
		{
			if (red_position + red_direction * i == blue_position + blue_direction * i)
			{
				//biker-biker collision detected!
				//std::cout << "BIKER-BIKER COLLISION PREVENTION DETECTED!\n\n";
				//move in orthogonal direction related to the collision route
				float switch_x = red_biker->getVelocity().x;
				float switch_z = red_biker->getVelocity().z;
				red_biker->setVelocity(igad::Vector3(switch_z, 0,switch_x));
			}
		}

	}

}


Stage::Stage()
{
	//stored_positions.push_back(new Tile());
	my_mesh = new igad::Mesh("./Assets/Models/my_cube.obj");
	my_texture = new igad::Texture("./Assets/Textures/tron_map.png");

	my_model = igad::Matrix44::CreateScale(igad::Vector3(280, 1, 157.5));
	my_model.SetTranslation(igad::Vector3(0, -50, 0));

}

Stage::~Stage()
{

	//delete stored_positions;
	delete my_mesh;
	delete my_texture;

}

//void Stage::Render(Camera * camera, igad::Renderer * renderer)
//{
//	renderer->Render(igad::Matrix44::CreateIdentity(), _texture, _mesh);
//}

Tile::Tile()
{
	//std::cout << "tile constructor\n";
	my_mesh = Tron::GetInstance()->tile_mesh;
	//my_texture = Tron::GetInstance()->tile_texture;

}

Tile::~Tile()
{
	delete my_mesh;
	my_mesh = nullptr;
	//delete tile_texture;
}



float Tile::getTileX()
{
	return tile_x_coordinate;
}



float Tile::getTileZ()
{
	return tile_z_coordinate;
}

void Tile::selectTexture(int choice)
{
	if(choice ==1)
		my_texture = Tron::GetInstance()->tile_texture;
	if(choice == 2)
		my_texture = Tron::GetInstance()->tile_texture2;
}






