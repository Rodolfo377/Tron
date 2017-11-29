#pragma once

#include <Matrix44.h>
#include <Mesh.h>
#include <Shader.h>
#include <Texture.h>
#include <Label.h>
#include <Renderer.h>

class BlasterCamera;

class AsteroidsEntity
{
public:
	virtual ~AsteroidsEntity();
	virtual void Render(BlasterCamera* camera, igad::Renderer* renderer);
	static bool DoCollission(	AsteroidsEntity* entity0,
								AsteroidsEntity* entity1);

	igad::Vector3	Position() const { return _position; }
	float			Radius() const { return _radius; }
	igad::Vector3	Velocity() const { return _velocity; }

protected:
	void WrapSpace();

	igad::Vector3	_position;
	float			_radius;
	igad::Vector3	_velocity;
	float			_density = 1.0f;
	igad::Matrix44	_transform;
	igad::Mesh*		_mesh = nullptr;
	igad::Texture*	_texture = nullptr;
};

class Blaster : public AsteroidsEntity
{
public:
	Blaster(int player);
	void Update(float dt);
	igad::Matrix44& GetTransform() { return _transform; }

private:

	int				_player;
	igad::Vector3	_force;
	float			_mass = 1.0f;
	float			_linearDamping = 1.0f;
	bool			_shot = false;
};

class Asteroid : public AsteroidsEntity
{
public:
	Asteroid();
	Asteroid(igad::Vector3 position, igad::Vector3 velocity, float scale);
	void Update(float dt);


private:
	void Init(igad::Vector3 position, igad::Vector3 velocity, float scale);

	igad::Vector3	_orientation;
	igad::Vector3	_rotation;
	igad::Vector3	_scale;
};

class Bullet : public AsteroidsEntity
{
public:
	Bullet(igad::Vector3 position, igad::Vector3 velocity);
	void Update(float dt);
	float Time() const { return _time; }

private:
	float _time = 0.0f;
};

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

class BlasterCamera : public Camera
{
public:
	BlasterCamera(Blaster*	blaster) : _blaster(blaster) {}
	void Update(float dt);

private:
	Blaster*		_blaster;
};

class Background
{
public:
	Background();
	~Background();
	void Render(Camera* camera, igad::Renderer* renderer);

private:
	igad::Mesh*		_mesh = nullptr;
	igad::Texture*	_texture = nullptr;
};

class ScoreLabel
{
public:
	ScoreLabel();
	~ScoreLabel();
	void Render(Camera* camera);
	void SetScore(int score);
	int GetScore() const { return _score; }
private:
	void Rebuild();

	int _score					= 0;
	igad::Label* _scoreLabel	= nullptr;
	igad::Mesh*	_scoreMesh		= nullptr;
};

class Asteroids
{
public:
	Asteroids(float screenWidth, float screenHeight);
	void SpawnSmallerAsteroids(Asteroid* asteroid);
	void Update(float dt);
	void Render();

	static Asteroids* GetInstance() { return _instance;		}	
	 // igad::Shader* GetSimpleShader() { return _simpleShader; }
	float GetWidth()				{ return _width;		}
	float GetHeight()				{ return _height;		}
	void CreateBullet(	igad::Vector3 position,
						igad::Vector3 velocity);

private:
	//Camera*						_UIcamera;
	//ScoreLabel*					_score;
	igad::Renderer*				_renderer;
	Blaster*					_blaster0;
	Blaster*					_blaster1;
	BlasterCamera*				_camera;
	Background*					_background;
	// igad::Shader*				_simpleShader;
	static Asteroids*			_instance;
	std::vector<Asteroid*>		_asteroids;
	std::vector<Bullet*>		_bullets;
	float						_width;
	float						_height;
};