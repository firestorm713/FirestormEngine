#include"FlatTransformed.h"
FlatTransformed::FlatTransformed(std::shared_ptr<ShaderProgram> shader_program, std::shared_ptr<SDL_Surface> _texture)
	:Material(shader_program)
{
}

FlatTransformed::~FlatTransformed()
{

}