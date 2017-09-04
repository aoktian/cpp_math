#include "vector2.h"

#include <math.h>
#include <exception>


Vector2::Vector2(float x /* = 0.0f */, float y /* = 0.0f */)
	: m_x(x), m_y(y),
	m_unitX(0.0f), m_unitY(0.0f),
	m_lengthSq(0.0f), m_length(0.0f),
	m_dirty(true)
{
	updateCache();
}

Vector2::Vector2(const Vector2& other)
	: Vector2(other.m_x, other.m_y)
{
}

Vector2::~Vector2()
{
}

Vector2& Vector2::operator=(const Vector2& other)
{
	m_x *= other.m_x;
	m_y *= other.m_y;
	return *this;
}

Vector2& Vector2::operator*=(const float scalar)
{
	m_x *= scalar;
	m_y *= scalar;
	return *this;
}

Vector2& Vector2::operator/=(const float divisor)
{
	if (0.0f == divisor) { throw std::exception("Vector2 --> Divide by zero"); }
	m_x /= divisor;
	m_y /= divisor;
	return *this;
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
	return *this;
}

void Vector2::setX(float val)
{
	m_x = val;
	markDirty();
}

void Vector2::setY(float val)
{
	m_y = val;
	markDirty();
}

void Vector2::set(float x, float y)
{
	m_x = x;
	m_y = y;
	markDirty();
}

void Vector2::set(float val)
{
	m_x = val;
	m_y = val;
	markDirty();
}

float Vector2::lengthSq()
{
	updateCache();
	return m_lengthSq;
}

float Vector2::length()
{
	updateCache();
	return m_length;
}

void Vector2::normalise()
{
	updateCache();
	m_x = m_unitX;
	m_y = m_unitY;
}

Vector2 Vector2::normalised()
{
	updateCache();
	return Vector2(m_unitX, m_unitY);
}

void Vector2::updateCache()
{
	if (dirty())
	{
		m_lengthSq = m_x * m_x + m_y * m_y;
		m_length = static_cast<float>(sqrt(m_lengthSq));

		m_unitX = m_length != 0.0f ? m_x / m_length : 0.0f;
		m_unitY = m_length != 0.0f ? m_y / m_length : 0.0f;
			
		markClean();
	}
}


bool operator==(const Vector2& v1, const Vector2& v2)
{
	return v1.x() == v2.x() &&
		v1.y() == v2.y();
}

bool operator!=(const Vector2& v1, const Vector2& v2)
{
	return !(v1 == v2);
}

Vector2 operator*(const Vector2& v, const float scalar)
{
	return Vector2(v.x() * scalar, v.y() * scalar);
}

Vector2 operator*(const float scalar, const Vector2& v)
{
	return v * scalar;
}

Vector2 operator/(const Vector2& v, const float divisor)
{
	if (0.0f == divisor) { throw std::exception("Vector2 --> Divide by zero"); }
	return Vector2(v.x() / divisor, v.y() / divisor);
}

Vector2 operator/(const float divisor, const Vector2& v)
{
	return v / divisor;
}

Vector2 operator+(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x() + v2.x(), v1.y() + v2.y());
}

Vector2 operator-(const Vector2& v1, const Vector2& v2)
{
	return Vector2(v1.x() - v2.x(), v1.y() - v2.y());
}
