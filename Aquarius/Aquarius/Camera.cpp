#include "Camera.h"



void PlayerCamera::Update(float dt)
{
	float dist = 140;

	//	Matrix44 view = Matrix44::CreateLookAt(Vector3(0, dist, 0), Vector3(), Vector3(0, 0, 1));
	//	Vector3 blasterPos = _blaster->GetTransform().GetTranslation();
	
	igad::Vector3 blasterPos = _biker->GetTransform().GetTranslation() / 2.0f;
	igad::Vector3 camerPos = igad::Vector3();
	camerPos.y = dist;

	_view = igad::Matrix44::CreateLookAt(camerPos, igad::Vector3(), igad::Vector3(0, 0, 1));
}
