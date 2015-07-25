#include<GL/glew.h>
#include<SDL.h>
#include<memory>
#include"Engine.h"

int main(int argc, char* argv[])
{
	Engine* _engine = new Engine();
	delete _engine;
//	system("pause");
	return 0;
}