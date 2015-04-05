#include<GL/glew.h>
#include<SDL.h>
#include<memory>
#include"Engine.h"
//#include<SDL_opengl.h>

int main(int argc, char* argv[])
{
	std::shared_ptr<Engine> Engine(new Engine());
//	system("pause");
	return 0;
}