#pragma once


#include "World.h"
#include <GLFW\glfw3.h>

#define screen_width 1280
#define screen_height 720
#define _WIN32_WINNT_NT4                    0x0400 // Windows NT 4.0  
#define _WIN32_WINNT_WIN2K                  0x0500 // Windows 2000  
#define _WIN32_WINNT_WINXP                  0x0501 // Windows XP  
#define _WIN32_WINNT_WS03                   0x0502 // Windows Server 2003  
#define _WIN32_WINNT_WIN6                   0x0600 // Windows Vista  
#define _WIN32_WINNT_VISTA                  0x0600 // Windows Vista  
#define _WIN32_WINNT_WS08                   0x0600 // Windows Server 2008  
#define _WIN32_WINNT_LONGHORN               0x0600 // Windows Vista  
#define _WIN32_WINNT_WIN7                   0x0601 // Windows 7  
#define _WIN32_WINNT_WIN8                   0x0602 // Windows 8  
#define _WIN32_WINNT_WINBLUE                0x0603 // Windows 8.1  
#define _WIN32_WINNT_WINTHRESHOLD           0x0A00 // Windows 10  
#define _WIN32_WINNT_WIN10                  0x0A00 // Windows 10  


static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	Tron *tron = reinterpret_cast<Tron*>(glfwGetWindowUserPointer(window));

	//Default command
	//Tron::GetInstance()->getInput(-1);

	//move up
	if (action == GLFW_PRESS)
		tron->HandleControls(key, scancode, action, mods);
	
}




int main()
{

	std::cout << "###########     Welcome to TRON!!!     #########\n\n";
	std::cout << "#######Rules: \n\nTron is a snake-inspired game where you need to trap the enemy \nto collide with its own light path or the walls.";
	std::cout << "The last one \nstanding is declared the winner \n(in the console window, because printing it on the game screen is too main stream)\n";
	std::cout << "\nThere can also be a DRAW if two players collide with each other\n\n\n\n\n";

	std::cout << "#######Controls: \n\n Blue biker: Arrow Keys (UP, LEFT, DOWN, RIGHT)\n";
	std::cout << "  Red biker (if multiplayer): WASD\n\n";

	std::cout << "RESTART GAME > SPACE\n\n";
	bool AI;

	while (std::cout << "\t\tPlaying with a friend?\n\n\t\tType 1 for NO and 0 for YES.\n\t\t**Press 'Enter'**\n" && !(std::cin >> AI)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "\n\n\t\tI SAID 1 OR 0 GODAMMIT!!!\n\n";
	}
	
	


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);		 // yes, 3 and 2!!!
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // But also 4 if present
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(screen_width, screen_height, "TRON", nullptr, nullptr);

	int major = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MAJOR);
	int minor = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MINOR);
	int revision = glfwGetWindowAttrib(window, GLFW_CONTEXT_REVISION);
	std::cout << "OpenGL Version " << major << "." << minor << "." << revision << std::endl;

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	

	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress)))
	{
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return -1;
	}

	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / float(height);
	auto lastFrame = glfwGetTime();




	Tron *world = new Tron(screen_width, screen_height, AI);
	
	glfwSetWindowUserPointer(window, world);
	glfwSetKeyCallback(window, key_callback);

	GameObject object = {};


	igad::Matrix44 m;
	igad::Matrix44 mat;
	m + mat;


	

	while (!glfwWindowShouldClose(window))
	{
		auto currentFrame = glfwGetTime();
		auto deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glViewport(0, 0, width, height);
		glClearColor(1.0, 1.0, 1.0, 1.0);
		//glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_CULL_FACE);

		
		world->Update(deltaTime);
		world->Render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	world->~Tron();
	//delete world;
	//std::cout << "world memory 1: "<< world << "\n";
	glfwDestroyWindow(window);
	delete world;
	world = nullptr;
	
	glfwTerminate();
	//std::cout << "world memory 2: " << world;

	exit(EXIT_SUCCESS);
}
