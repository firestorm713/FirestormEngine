#include"MeshRenderer.h"

MeshRenderer::MeshRenderer(Engine* _Engine, std::shared_ptr<Entity> _parent, std::shared_ptr<FlatTransformed> _material)
	:Component(_Engine, _parent)
{
}

MeshRenderer::~MeshRenderer()
{
}
void MeshRenderer::Update()
{
}

void MeshRenderer::LateUpdate()
{
}