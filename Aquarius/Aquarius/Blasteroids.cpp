//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include "Asteroids.h"
//#include <iostream>
//
//static void error_callback(int error, const char* description)
//{
//	fputs(description, stderr);
//}
//
//static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}
//
//int main(void)
//{
//	igad::Matrix44 m;
//	igad::Matrix44 mat;
//	m + mat;
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);		 // yes, 3 and 2!!!
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // But also 4 if present
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	GLFWwindow* window;
//	glfwSetErrorCallback(error_callback);
//	if (!glfwInit())
//		exit(EXIT_FAILURE);
//	window = glfwCreateWindow(1280, 720, "Blasteroids", nullptr, nullptr);
//
//	int major = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MAJOR);
//	int minor = glfwGetWindowAttrib(window, GLFW_CONTEXT_VERSION_MINOR);
//	int revision = glfwGetWindowAttrib(window, GLFW_CONTEXT_REVISION);
//	std::cout << "OpenGL Version " << major << "." << minor << "." << revision << std::endl;
//
//	if (!window)
//	{
//		glfwTerminate();
//		exit(EXIT_FAILURE);
//	}
//	glfwMakeContextCurrent(window);
//	glfwSwapInterval(1);
//	glfwSetKeyCallback(window, key_callback);
//
//	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress)))
//	{
//		std::cout << "Failed to initialize OpenGL context" << std::endl;
//		return -1;
//	}
//
//	float ratio;
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	ratio = width / float(height);
//	auto lastFrame = glfwGetTime();
//
//	Asteroids* world = new Asteroids(width, height);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		auto currentFrame = glfwGetTime();
//		auto deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		glViewport(0, 0, width, height);
//		//glClearColor(1.0, 1.0, 1.0, 1.0);
//		glClearColor(0.0, 0.0, 0.0, 1.0);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glEnable(GL_CULL_FACE);
//
//
//		world->Update(deltaTime);
//		world->Render();
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//	glfwDestroyWindow(window);
//	glfwTerminate();
//	exit(EXIT_SUCCESS);
//}
//
