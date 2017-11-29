#include <Renderer.h>

using namespace igad;

igad::Renderer::Renderer(Shader* shader) : _shader(shader)
{
	_projParam = shader->GetParameter("u_projection");
	_modelParam = shader->GetParameter("u_model");
	_viewParam = shader->GetParameter("u_view");
	_textureParam = shader->GetParameter("u_texture");
	
	_positionAttrib = shader->GetAttribute("a_position");
	_normalAttrib = shader->GetAttribute("a_normal");
	_textureAttrib = shader->GetAttribute("a_texture");
}

void Renderer::Begin(const Matrix44& view, const Matrix44& projection)
{
	_shader->Activate();

	_projParam->SetValue(projection);
	_viewParam->SetValue(view);
}

void Renderer::Render(	const Matrix44& model,
						const Texture* texture,
						const Mesh* mesh)
{
	const GLuint* vbo = mesh->GetVertexBuffers();

#ifdef DEBUG
	if (glIsBuffer(vbo[0]) != GL_TRUE)
	{
		LOG("The vertex buffer is not a valid buffer (VBO).");
	}
	if (glIsBuffer(vbo[1]) != GL_TRUE)
	{
		LOG("The index buffer is not a valid buffer (VBO)");
	}	
#endif

	// Bind the buffers to the global state
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	GL_GET_ERROR();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);
	GL_GET_ERROR();

	// Default to VBO values, the pointer addresses are interpreted as byte-offsets.
	const void* firstPosition = reinterpret_cast<const void*>(offsetof(VertexFormat, Position));
	const void* firstNormal = reinterpret_cast<const void*>(offsetof(VertexFormat, Normal));
	const void* firstTexture = reinterpret_cast<const void*>(offsetof(VertexFormat, Texture));

	GLsizei size = sizeof(VertexFormat);
	_positionAttrib->SetAttributePointer(3, GL_FLOAT, GL_FALSE, size, firstPosition);
	_normalAttrib->SetAttributePointer(3, GL_FLOAT, GL_FALSE, size, firstNormal);
	_textureAttrib->SetAttributePointer(2, GL_FLOAT, GL_FALSE, size, firstTexture);

	_modelParam->SetValue(model);
	_textureParam->SetValue(*texture);

	const void* firstIndex = reinterpret_cast<const void*>(0);
	glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_SHORT, firstIndex);
	GL_GET_ERROR();

	// Unbind buffers from global state.
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	GL_GET_ERROR();

	_positionAttrib->DisableAttributePointer();
	_normalAttrib->DisableAttributePointer();
	_textureAttrib->DisableAttributePointer();
}

void Renderer::End()
{
	_shader->Deactivate();
}

