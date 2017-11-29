#pragma once

#include <Matrix44.h>
#include <Mesh.h>
#include <Shader.h>
#include <Texture.h>

namespace igad
{

class Renderer
{
public:
	Renderer(Shader* shader);
	
	void Begin(const Matrix44& view, const Matrix44& projection);

	void Render(const Matrix44& model,
				const Texture* texture,
				const Mesh* mesh);
	void End();

protected:
	Shader*	_shader;
	ShaderParameter* _projParam;
	ShaderParameter* _modelParam;
	ShaderParameter* _viewParam;
	ShaderParameter* _textureParam;
	ShaderAttribute* _positionAttrib;
	ShaderAttribute* _normalAttrib;
	ShaderAttribute* _textureAttrib;
};

}