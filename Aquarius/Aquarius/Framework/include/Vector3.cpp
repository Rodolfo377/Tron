#include "Vector3.h"

using namespace igad;

/// The default constructor creates a zero vector.
Vector3::Vector3()
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
}



/// Creates a vector with the given components
Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

/// Returns the value of the given vector added to this
Vector3 Vector3::operator+(const Vector3 & v) const
{
	Vector3 v3;
	v3.x =  this->x + v.x;
	v3.y = this->y + v.y;
	v3.z = this->z + v.z;

	return v3;
}

/// Returns the value of the given vector subtracted from this
Vector3 Vector3::operator-(const Vector3& v) const 
{
	Vector3 v3;
	v3.x = this->x - v.x;
	v3.y = this->y - v.y;
	v3.z = this->z - v.z;

	return v3;
}

/// Returns a copy of this vector scaled the given value
Vector3 Vector3::operator*(const float value) const 
{
	Vector3 v3;
	v3.x = this->x * value;
	v3.y = this->y * value;
	v3.z = this->z * value;

	return v3;
}

/// Returns a copy of this vector scaled the inverse of the value
Vector3 Vector3::operator/(const float value) const 
{
	Vector3 v3;
	v3.x = this->x / value;
	v3.y = this->y / value;
	v3.z = this->z / value;

	return v3;
}

/// Returns the negative this vector
 Vector3 Vector3::operator-() const 
 {
	 Vector3 v3;
	 v3.x = -this->x;
	 v3.y = -this->y;
	 v3.z = -this->z;

	 return v3;
 }

/// Calculates and returns the dot product of this
/// with the given vector
float Vector3::operator *(const Vector3& vector) const 
{
	float dotProduct = this->x*vector.x + this->y*vector.y + this->z*vector.z;

	return dotProduct;
}

/// Adds the given vector to this
void Vector3::operator+=(const Vector3& v) 
{
	this->x = this->x + v.x;
	this->y = this->y + v.y;
	this->z = this->z + v.z;
}

/// Subtracts the given vector from this
void Vector3::operator-=(const Vector3& v) 
{
	this->x = this->x - v.x;
	this->y = this->y - v.y;
	this->z = this->z - v.z;
}

/// Multiplies this vector by the given scalar
void Vector3::operator*=(const float value) 
{
	this->x = this->x *value;
	this->y = this->y *value;
	this->z = this->z *value;
}

/// Calculates and returns the cross product of this vector
/// with the given vector
Vector3 Vector3::Cross(const Vector3& vector) const 
{
	Vector3 v3;
	v3.x = this->y*vector.z - this->z*vector.y;
	v3.y = this->z*vector.x - this->x*vector.z;
	v3.z = this->x*vector.y - this->y*vector.x;

	return v3;
}

/// Calculates and returns the dot product of this vector
/// with the given vector
float Vector3::Dot(const Vector3& vector) const 
{
	float dotProduct = this->x*vector.x + this->y*vector.y + this->z*vector.z;

	return dotProduct;
}

///  Gets the magnitude of this vector
float Vector3::Magnitude() const 
{
	float mag = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
	//std::cout << "mag: " << mag << "\n";
	return mag;
}

///  Gets the squared magnitude of this vector
float Vector3::SquareMagnitude() const 
{
	float squared_mag = pow(Magnitude(), 2);

	return squared_mag;
}

/// Turns a non-zero vector into a vector of unit length
void Vector3::Normalize() 
{
	float mag = Magnitude();
	if (mag > 0)
	{
		this->x = this->x / mag;
		this->y = this->y / mag;
		this->z = this->z / mag;
	}
	else
	{
		std::cout << "Wrong magnitude on Normalize() from Vector3.cpp\n";
	}
}


/// Checks if the two vectors have identical components
bool Vector3::operator==(const Vector3& other) const 
{
	bool identical = false;

	if (this->x == other.x)
	{
		if (this->y == other.y)
		{
			if (this->z == other.z)
			{
				identical = true;
			}
		}
	}
	return identical;
}

/// Checks if the two vectors have non-identical components
bool Vector3::operator!=(const Vector3& other) const 
{
	bool different = true;

	if (this->x == other.x)
	{
		if (this->y == other.y)
		{
			if (this->z == other.z)
			{
				different = false;
			}
		}
	}
	return different;
}

/// Zero all the components of the vector
void Vector3::Clear() 
{
	this->x = 0;
	this->y = 0;
	this->z = 0;	
}

//Vector3 Vector3::Slerp(float fact, const Vector3 & r) const
//{
//	return Vector3();
//}
//
//
//
///// Multiplication with Rhs Vector
inline Vector3 operator*(float val, const Vector3& rhs)
{
	return rhs * val;
}

igad::Vector2::Vector2()
{
	this->x = 0.0f;
	this->y = 0.0f;
}

igad::Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2 Vector2::operator*(const float value) const
{
	Vector2 v2;
	v2.x = this->x * value;
	v2.y = this->y * value;
	

	return v2;
}

Vector2 igad::Vector2::operator+(const Vector2 & v) const
{
	Vector2 v2;
	v2.x = this->x + v.x;
	v2.y = this->y + v.y;


	return v2;
}

bool igad::Vector2::operator==(const Vector2 & other) const
{
	bool identical = false;

	if (this->x == other.x)
	{
		if (this->y == other.y)
		{			
				identical = true;
		}
	}
	return identical;
}
