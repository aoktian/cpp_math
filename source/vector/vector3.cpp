#include "vector3.h"

#include <math.h>
#include "../utility/mathUtility.h"


Vector3::Vector3(float x /* = 0.0f */, float y /* = 0.0f */, float z /* = 0.0f */)
	: m_x(x), m_y(y), m_z(z),
	m_lengthSq(0.0f), m_length(0.0f),
	m_unitX(0.0f), m_unitY(0.0f), m_unitZ(0.0f),
	m_dirty(true)
{
	updateCache();
}

Vector3::Vector3(const Vector3& other)
	: Vector3(other.m_x, other.m_y, other.m_z)
{
}

Vector3::~Vector3()
{
}

Vector3& Vector3::operator=(const Vector3& other)
{
	m_x = other.m_x;
	m_y = other.m_y;
	m_z = other.m_z;
	m_dirty = true;
	return *this;
}

Vector3& Vector3::operator*=(const float scalar)
{
	m_x *= scalar;
	m_y *= scalar;
	m_z *= scalar;
	m_dirty = true;
	return *this;
}

Vector3& Vector3::operator/=(const float divisor)
{
	if (0.0f == divisor)
	{
		return *this;
	}
	m_x /= divisor;
	m_y /= divisor;
	m_z /= divisor;
	m_dirty = true;
	return *this;
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	m_z += other.m_z;
	m_dirty = true;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& other)
{
	m_x -= other.m_x;
	m_y -= other.m_y;
	m_z -= other.m_z;
	m_dirty = true;
	return *this;
}

void Vector3::setX(float val)
{
	m_x = val;
	m_dirty = true;
}

void Vector3::setY(float val)
{
	m_y = val;
	m_dirty = true;
}

void Vector3::setZ(float val)
{
	m_z = val;
	m_dirty = true;
}

void Vector3::set(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_dirty = true;
}

void Vector3::set(float val)
{
	m_x = val;
	m_y = val;
	m_z = val;
	m_dirty = true;
}

void Vector3::set(const Vector3& other)
{
	m_x = other.m_x;
	m_y = other.m_y;
	m_z = other.m_z;
	m_dirty = true;
}

float Vector3::lengthSq() const
{
	updateCache();
	return m_lengthSq;
}

float Vector3::length() const 
{
	updateCache();
	return m_length;
}

void Vector3::normalise()
{
	updateCache();
	m_x = m_unitX;
	m_y = m_unitY;
	m_z = m_unitZ;
	m_dirty = true;
}

Vector3 Vector3::normalised() const
{
	updateCache();
	return Vector3(m_unitX, m_unitY, m_unitZ);
}

void Vector3::updateCache() const
{
	if (m_dirty)
	{
		m_lengthSq = m_x * m_x + m_y * m_y + m_z * m_z;
		m_length = static_cast<float>(sqrt(m_lengthSq));

		m_unitX = m_length != 0.0f ? m_x / m_length : 0.0f;
		m_unitY = m_length != 0.0f ? m_y / m_length : 0.0f;
		m_unitZ = m_length != 0.0f ? m_z / m_length : 0.0f;

		m_dirty = false;
	}
}

float Vector3::dotProduct(const Vector3& other) const
{
	auto unitV1 = normalised();
	auto unitV2 = other.normalised();
	return unitV1.m_x * unitV2.m_x + 
		unitV1.m_y * unitV2.m_y + 
		unitV1.m_z * unitV2.m_z;
}

float Vector3::dotProduct(const Vector3& v1, const Vector3& v2)
{
	return v1.dotProduct(v2);
}

Vector3 Vector3::crossProduct(const Vector3& other) const
{
	return Vector3(m_y * other.m_z - m_z * other.m_y,
		m_z * other.m_x - m_x * other.m_z,
		m_x * other.m_y - m_y * other.m_x
		).normalised();
}

Vector3 Vector3::crossProduct(const Vector3& v1, const Vector3& v2)
{
	return v1.crossProduct(v2);
}

float Vector3::angle(const Vector3& other) const
{
	auto lenV1 = length();
	auto lenV2 = other.length();
	return static_cast<float>(acos(dotProduct(other) / (lenV1 * lenV2)));
}

float Vector3::angle(const Vector3& v1, const Vector3& v2)
{
	return v1.angle(v2);
}


bool operator==(const Vector3& v1, const Vector3& v2)
{
	return v1.x() == v2.x() && 
			v1.y() == v2.y() &&
			v1.z() == v2.z();
}

bool operator!=(const Vector3& v1, const Vector3& v2)
{
	return !(v1 == v2);
}

Vector3 operator*(const Vector3& v, const float scalar)
{
	return Vector3(v.x() * scalar, v.y() * scalar, v.z() * scalar);
}

Vector3 operator*(const float scalar, const Vector3& v)
{
	return v * scalar;
}

Vector3 operator/(const Vector3& v, const float divisor)
{
	if (0.0f == divisor)
	{
		return Vector3();
	}

	return Vector3(v.x() / divisor, v.y() / divisor, v.z() / divisor);
}

Vector3 operator/(const float divisor, const Vector3& v)
{
	return v / divisor;
}

Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}

Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}
