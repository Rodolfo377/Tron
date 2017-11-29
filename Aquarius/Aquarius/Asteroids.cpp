#include "./Asteroids.h"
#include <DebugRenderer.h>
#include <Renderer.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <Label.h>
#include <PerlinNoise.h>

using namespace igad;

Asteroids* Asteroids::_instance = nullptr;

//////////////////////////////////////////////////////////////////////////////////////////
//
// AsteroidsEntity
//
//////////////////////////////////////////////////////////////////////////////////////////
AsteroidsEntity::~AsteroidsEntity()
{
// 	if(_mesh)
//		delete _mesh;
//	if(_texture)
//		delete _texture;
}

void AsteroidsEntity::WrapSpace()
{
	float width = Asteroids::GetInstance()->GetWidth() * 1.5f;
	float height = Asteroids::GetInstance()->GetHeight() * 1.5f;

	if (_position.x > width)
		_position.x -= 2 * width;
	else if (_position.x < -width)
		_position.x += 2 * width;

	if (_position.z > height)
		_position.z -= 2 * height;
	else if (_position.z < -height)
		_position.z += 2 * height;

	gDebugDraw3D.AddSphere(_position, _radius);
}

void AsteroidsEntity::Render(BlasterCamera* camera, Renderer* renderer)
{
	renderer->Render(_transform, _texture, _mesh);
}

bool AsteroidsEntity::DoCollission(AsteroidsEntity* entity0, AsteroidsEntity* entity1)
{
	float r0 = entity0->_radius;
	float r1 = entity1->_radius;

	if (r0 == 0.0f || r1 == 0.0f)
		return false;

	bool resolve = true;
	Vector3 normal = entity0->_position - entity1->_position;
	float dist = normal.Magnitude();
	float radiussum = r0 + r1;

	if (dist < radiussum)
	{
		normal.Normalize();
		float diff = radiussum - dist;

		// Very, very, very crude collision resolving
		if (resolve)
		{
			Vector3 move = normal * diff;
			Vector3 moveFst = move * (-r0 / radiussum);
			Vector3 moveSec = move * (r1 / radiussum);

			entity0->_position -= moveFst;
			entity1->_position -= moveSec;


			// Get the velocity in the direction of the contact
			Vector3 relativeVelocity = entity0->_velocity - entity1->_velocity;
			float separatingSpeed = relativeVelocity.Dot(normal);

			// float mass0 = 4 / 3 * Pi * (r0 * r0 * r0);
			// float mass1 = 4 / 3 * Pi * (r1 * r1 * r1);
			float mass0 = 1.0f;
			float mass1 = 1.0f;
			float restitution = 0.85f;

			// Check if there is anything to resolve
			if (separatingSpeed < 0)
			{
				// Calculate new separating velocity
				float newSepVelocity = separatingSpeed * restitution;
				float delataVelocity = newSepVelocity - separatingSpeed;
				float totalMass = mass0 + mass1;
				float impulse = delataVelocity * totalMass;
				Vector3 impulsePerMass = normal * impulse;
				entity0->_velocity += impulsePerMass / mass0;
				entity1->_velocity -= impulsePerMass / mass1;
			}
		}

		return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Blaster
//
//////////////////////////////////////////////////////////////////////////////////////////
Blaster::Blaster(int player) : _player(player)
{
	_mesh = new Mesh("./Assets/Models/uh60.obj");
	_texture = new Texture("./Assets/Textures/fuselage.jpg");
	_radius = 4.0f;
}

void Blaster::Update(float dt)
{
	int joy = _player;
	int count;
	int p = glfwJoystickPresent(joy);

	if (!p)
		return;
	const float* axes = glfwGetJoystickAxes(joy, &count);

	if (joy == 1)
	{
		cout << "JOY\n\n";
		for (int i = 0; i < count; i++)
			cout << "Axes " << i << "=" << axes[i] << endl;
		cout << endl;
	}

	Vector3 dir(-axes[1], 0.0f, axes[0]);

	Matrix44 rotation;

	if (dir.Magnitude() > 0.1f)
	{
		dir.Normalize();
		Vector3 up(0.0f, 1.0f, 0.0f);
		Vector3 side = dir.Cross(up);
		rotation.SetOrientation(dir, up, side);
	}

	_transform = rotation * Matrix44::CreateRotateZ(DegToRad(90));


	Vector3 fwd = _transform.GetZAxis();
	float thrust = axes[2];
	if (thrust < -0.01f)
	{
		_force += fwd * thrust * -100.0f;
	}

	Vector3 acceleration = _force / _mass;
	_velocity += acceleration * dt;
	_velocity -= _velocity * (dt * _linearDamping);
	_position += _velocity * dt;
	_transform.SetTranslation(_position);
	_force.Clear();

	gDebugDraw3D.AddAxis(_transform, 6.0f);
	const unsigned char* buttons = glfwGetJoystickButtons(joy, &count);

	/*
	for (int i = 0; i < count; i++)
		cout << "Button " << i << "=" << (bool)buttons[i] << endl;
	cout << endl;
	*/

	if (buttons[0] > 0 && !_shot)
	{
		_shot = true;
		Asteroids::GetInstance()->CreateBullet(_position, fwd * 200.0f);
	}
	else if (buttons[0] == 0)
	{
		_shot = false;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// BlasterCamera
//
//////////////////////////////////////////////////////////////////////////////////////////
void BlasterCamera::Update(float dt)
{	
	float dist = 140;

	//	Matrix44 view = Matrix44::CreateLookAt(Vector3(0, dist, 0), Vector3(), Vector3(0, 0, 1));
	//	Vector3 blasterPos = _blaster->GetTransform().GetTranslation();

	Vector3 blasterPos = _blaster->GetTransform().GetTranslation() / 2.0f;
	Vector3 camerPos = blasterPos;
	camerPos.y = dist;

	_view = Matrix44::CreateLookAt(camerPos, Vector3(), Vector3(0, 0, 1));
} 


//////////////////////////////////////////////////////////////////////////////////////////
//
// Background
//
//////////////////////////////////////////////////////////////////////////////////////////
Background::Background()
{
	_mesh = new Mesh();
	_texture = new Texture("./Assets/white.png");

	float fov = 60.0f;
	float dist = 150.0f;
	float ratio = Asteroids::GetInstance()->GetWidth() / Asteroids::GetInstance()->GetHeight();
	float w = tan(DegToRad(fov * 0.5f)) * dist * ratio;
	float h = w;

	// auto w = Asteroids::GetInstance()->GetWidth();
	// auto h = Asteroids::GetInstance()->GetWidth();
	dist = -50;

	vector<VertexFormat> vertices =
	{
		{ Vector3(-w, dist, -h),  Vector3(0, 1, 0), { 0, 0 } },
		{ Vector3(w, dist, -h),  Vector3(0, 1, 0), { 0, 1 } },
		{ Vector3(w, dist, h),  Vector3(0, 1, 0), { 1, 1 } },
		{ Vector3(-w, dist, h),  Vector3(0, 1, 0), { 1, 0 } }
	};
	_mesh->SetVertices(move(vertices));
	vector<GLushort> indices = { 0, 2, 1, 0, 3, 2 };
	_mesh->SetIndices(move(indices));
	_mesh->Apply();
}

Background::~Background()
{
	delete _mesh;
	delete _texture;
}

void Background::Render(Camera* camera, igad::Renderer* renderer)
{
	renderer->Render(Matrix44::CreateIdentity(), _texture, _mesh);
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Asteroid
//
//////////////////////////////////////////////////////////////////////////////////////////
Asteroid::Asteroid()
{
	auto w = Asteroids::GetInstance()->GetWidth();
	auto h = Asteroids::GetInstance()->GetHeight();

	float v = 0.0f;
	auto velocity = Vector3(
		RandInRange(-v, v),
		0.0f,
		RandInRange(-v, v));

	auto position = Vector3(
		RandInRange(-w, w),
		0.0f, //RandInRange(0, 0),
		RandInRange(-h, h));

	float scale = RandInRange(3.2f, 15.0f);

	Init(position, velocity, scale);
}

Asteroid::Asteroid(Vector3 position, Vector3 velocity, float scale)
{
	Init(position, velocity, scale);
}

Vector3 Noise(Vector3 p, float offset)
{
	float x = ImprovedNoise::Noise(p.x, p.y, p.z) * offset;
	float y = ImprovedNoise::Noise(p.y, p.z, p.x) * offset;
	float z = ImprovedNoise::Noise(p.z, p.x, p.y) * offset;
	return Vector3(x, y, z);
}

void Asteroid::Init(Vector3 position, Vector3 velocity, float scale)
{
	static auto baseMesh = new Mesh();
	baseMesh->Load("./Assets/GeoSphere.obj");

	vector<VertexFormat> vertices = baseMesh->GetVertices();
	vector<GLushort> indices = baseMesh->GetIndices();
	
	Vector3 randomSampleOffset(RandInRange(-Pi, Pi), RandInRange(-Pi, Pi), RandInRange(-Pi, Pi));
	float offset = 0.6f;

	for (size_t baseIdx = 0; baseIdx < indices.size() / 3; baseIdx++)
	{
		Vector3& v0 = vertices[baseIdx * 3 + 0].Position;
		Vector3& v1 = vertices[baseIdx * 3 + 1].Position;
		Vector3& v2 = vertices[baseIdx * 3 + 2].Position;

		v0 += Noise(v0 + randomSampleOffset, offset);
		v1 += Noise(v1 + randomSampleOffset, offset);
		v2 += Noise(v2 + randomSampleOffset, offset);

		Vector3 v10 = v1 - v0;
		Vector3 v20 = v2 - v0;
		Vector3 normal = v10.Cross(v20);
		normal.Normalize();
		
		for (auto i = 0; i < 3; i++)
			vertices[baseIdx * 3 + i].Normal = normal;
	}

	auto mesh = new Mesh();
	mesh->SetVertices(move(vertices));
	mesh->SetIndices(move(indices));
	mesh->Apply();

	static auto texture = new Texture("./Assets/white.png");
	_mesh = mesh;
	_texture = texture;
	_velocity = velocity;
	_position = position;

	_scale = Vector3(scale, scale, scale);
	_radius = scale;

	float o = 0.3f;
	_rotation = Vector3(
		RandInRange(-o, o),
		RandInRange(-o, o),
		RandInRange(-o, o));
}

void Asteroid::Update(float dt)
{
	_position += _velocity * dt;
	_orientation += _rotation * dt;

	Matrix44 orientation;
	orientation.SetEulerAxis(_orientation.x, _orientation.y, _orientation.z);

	_transform = Matrix44::CreateIdentity();	
	_transform = orientation * Matrix44::CreateScale(_scale);
	_transform.SetTranslation(_position);
	WrapSpace();

	gDebugDraw3D.AddSphere(_position, _radius);
}

//////////////////////////////////////////////////////////////////////////////////////////
//
// Bullet
//
//////////////////////////////////////////////////////////////////////////////////////////
Bullet::Bullet(Vector3 position, Vector3 velocity)
{
	_radius = 0.3f;
	_position = position;
	_velocity = velocity;

	static auto mesh = new Mesh("./Assets/Sphere.obj");
	static auto texture = new Texture("./Assets/white.png");
	_mesh = mesh;
	_texture = texture;

	_transform = Matrix44::CreateIdentity();
	//_transform = Matrix44::CreateScale(Vector3(_radius, _radius, _radius));
}

void Bullet::Update(float dt)
{
	_time += dt;
	_position += _velocity * dt;
	_transform.SetTranslation(_position);
}


//////////////////////////////////////////////////////////////////////////////////////////
//
// ScoreLabel
//
//////////////////////////////////////////////////////////////////////////////////////////
ScoreLabel::ScoreLabel()
{
	Rebuild();
}

ScoreLabel::~ScoreLabel()
{
	delete _scoreLabel;
	delete _scoreMesh;
}

void ScoreLabel::Rebuild()
{
	if (_scoreLabel) delete _scoreLabel;
	if (_scoreMesh) delete _scoreMesh;

	string scoreString =  "SCORE:" + to_string(_score);

	_scoreLabel = new Label(scoreString, "./Assets/OpenSans-Regular.ttf", 32, 650);
	_scoreMesh = new Mesh();
	Vector2 size = _scoreLabel->GetSize();
	Vector2 uv = _scoreLabel->GetUVTo();
	/*
	vector<VertexFormat> vertices =
	{
		{ Vector3(0.0f,		0, 0),		Vector3(0, 1, 0),{ 0, 0 }		},
		{ Vector3(size.x,	0, 0),		Vector3(0, 1, 0),{ 0, uv.y }	},
		{ Vector3(size.x,	0, size.y), Vector3(0, 1, 0),{ uv.x, uv.y } },
		{ Vector3(0.0f,		0, size.y), Vector3(0, 1, 0),{ uv.x, 0 }	}
	};
	*/
	vector<VertexFormat> vertices =
	{
		{ Vector3(0.0f,		0, 0),		Vector3(0, 1, 0), { 0, 0	} },
		{ Vector3(size.x,	0, 0),		Vector3(0, 1, 0), { uv.x, 0 } },
		{ Vector3(size.x,	0, size.y), Vector3(0, 1, 0), { uv.x, uv.y } },
		{ Vector3(0.0f,		0, size.y), Vector3(0, 1, 0), { 0, uv.y } }
	};
	_scoreMesh->SetVertices(move(vertices));
	vector<GLushort> indices = { 0, 2, 1, 0, 3, 2 };
	_scoreMesh->SetIndices(move(indices));
	_scoreMesh->Apply();
}

void ScoreLabel::Render(Camera* camera)
{
	
	/*igad::Render(	Asteroids::GetInstance()->GetSimpleShader(),
					Matrix44::CreateIdentity(),
					camera->View(),
					camera->Projection(),
					_scoreLabel,
					_scoreMesh);
					*/
}

void ScoreLabel::SetScore(int score)
{
	_score = score;
	Rebuild();
}


//////////////////////////////////////////////////////////////////////////////////////////
//
// Asteroids
//
//////////////////////////////////////////////////////////////////////////////////////////
Asteroids::Asteroids(float screenWidth, float screenHeight)
{
	_instance = this;

	float fov = 60.0f;
	float dist = 100.0f;
	float ratio = screenWidth / screenHeight;
	_height = tan(DegToRad(fov * 0.5f)) * dist;
	_width = _height * ratio;

	auto shader = new Shader("./Assets/Basic3D.vsh", "./Assets/Basic3D.fsh");
	_renderer = new Renderer(shader);

	for (size_t i = 0; i < 15; i++)
	{
		auto a = new Asteroid();
		_asteroids.push_back(a);
	}

	//Why two blasters??

	_blaster0 = new Blaster(0);
	//_blaster1 = new Blaster(1);
	_camera = new BlasterCamera(_blaster0);
	_background = new Background();

	Matrix44 view = Matrix44::CreateLookAt(Vector3(0, dist, 0), Vector3(), Vector3(0, 0, 1));
	Matrix44 projection = Matrix44::CreatePerspective(DegToRad(fov), ratio, 0.1f, 2000.0f);

	_camera->SetView(view);
	_camera->SetProjection(projection);

	gDebugDraw3D.Initialize();
}

void Asteroids::CreateBullet(igad::Vector3 position, igad::Vector3 velocity)
{
	auto b = new Bullet(position, velocity);
	_bullets.push_back(b);
}

void Asteroids::Update(float dt)
{
	//auto view = _camera->View();
	//_camera->SetView(view);
	_camera->Update(dt);

	_blaster0->Update(dt);
	//_blaster1->Update(dt);

	for (auto a : _asteroids)
	{
		a->Update(dt);
	}

	for (size_t i = 0; i < _bullets.size(); i++)
	{
		auto b = _bullets[i];
		b->Update(dt);
		if (b->Time() > 1.2f)
		{
			_bullets.erase(_bullets.begin() + i);
			delete b;
			i--;
		}
	}

	for (auto a : _asteroids)
	{
		AsteroidsEntity::DoCollission(a, _blaster0);
		//AsteroidsEntity::DoCollission(a, _blaster1);
	}

	for(size_t i = 0; i < _asteroids.size(); i++)
	{
		for (size_t j = i + 1; j < _asteroids.size(); j++)
		{
			AsteroidsEntity::DoCollission(_asteroids[i], _asteroids[j]);
		}
	}

	vector<Asteroid*> asteroidsToRemove;
	for (size_t i = 0; i < _asteroids.size(); i++)
	{
		auto a = _asteroids[i];
		for (size_t j = 0; j < _bullets.size(); j++)
		{
			auto b = _bullets[j];
			if (AsteroidsEntity::DoCollission(a, b))
			{
				_asteroids.erase(_asteroids.begin() + i);
				_bullets.erase(_bullets.begin() + j);
				asteroidsToRemove.push_back(a);
				delete b;
				i--;
				j--;
			}
		}
	}

	for (auto a : asteroidsToRemove)
	{
		// _score->SetScore(_score->GetScore() + 100);

		if (a->Radius() > 2.0f)
			SpawnSmallerAsteroids(a);
		
		delete a;
	}
}

void Asteroids::SpawnSmallerAsteroids(Asteroid* asteroid)
{	
	float r = asteroid->Radius() / 2.0f;
	for (size_t i = 0; i < 2; i++)
	{
		auto velocity = Vector3(
			RandInRange(-1.0f, 1.0f),
			0.0f,
			RandInRange(-1.0f, 1.0f));
		velocity.Normalize();

		Vector3 pos = asteroid->Position();

		velocity *= asteroid->Velocity().Magnitude();
		auto a = new Asteroid(pos, velocity, r);
		a->Update(0.0f);		
		_asteroids.push_back(a);
	}
}

void Asteroids::Render()
{
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);

	_renderer->Begin(_camera->View(), _camera->Projection());

	//glDepthFunc(GL_LESS);
	//glFrontFace(GL_CW);

	_background->Render(_camera, _renderer);
	_blaster0->Render(_camera, _renderer);
	//_blaster1->Render(_camera, _renderer);

	for (auto a : _asteroids)
		a->Render(_camera, _renderer);

	for (auto b : _bullets)
		b->Render(_camera, _renderer);

	_renderer->End();


	auto m = _camera->ViewProjection();
	gDebugDraw3D.Draw(m);
	gDebugDraw3D.Clear();

	//glDisable(GL_DEPTH_TEST);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// _score->Render(_UIcamera);
}