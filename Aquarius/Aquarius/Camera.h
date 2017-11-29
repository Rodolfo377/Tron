#pragma once
#include "GameObject.h"
#include "PlayerObject.h"


class Camera
{
public:
	Camera() {}
	const igad::Matrix44& View() const { return _view; }
	const igad::Matrix44& Projection() const { return _projection; }
	igad::Matrix44 ViewProjection() const { return _projection * _view; }
	void SetProjection(const igad::Matrix44& p) { _projection = p; }
	void SetView(const igad::Matrix44& v) { _view = v; }
	
protected:
	igad::Matrix44	_view;
	igad::Matrix44	_projection;
};

class PlayerCamera : public Camera
{
public:
	PlayerCamera(PlayerObject*	blue_biker) : _biker(blue_biker) {}
	void Update(float dt);

private:
	PlayerObject*		_biker;
};