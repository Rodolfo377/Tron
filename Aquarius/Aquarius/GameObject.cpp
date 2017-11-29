#include "GameObject.h"


/*Time-Corrected Verlet Integrartion method:
Needs the following data:
-Current position
-Current deltaTime
-Previous Position
-Previous Delta-time*/

//void GameObject::Init(igad::Renderer * a_renderer)
//{
//	ASSERT(a_renderer);
//	my_renderer = a_renderer;
//}

void GameObject::Render(PlayerCamera * camera, igad::Renderer * renderer)
{
	
	renderer->Render(my_model, my_texture, my_mesh);
}
