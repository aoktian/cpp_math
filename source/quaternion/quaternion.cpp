#include "quaternion.h"

#include <math.h>
#include "../vector/vector3.h"

Quaternion::Quaternion(float w /* = 1.0f */, float x /* = 0.0f */, float y /* = 0.0f */, float z /* = 0.0f */)
{
	createUnit(w, x, y, z);
}

Quaternion::Quaternion(const float angle, const Vector3& axis)
	: Quaternion(angle, axis.x(), axis.y(), axis.z())
{
}

Quaternion::Quaternion(const Quaternion& other)
	: Quaternion()
{
	m_w = other.m_w;
	m_x = other.m_x;
	m_y = other.m_y;
	m_z = other.m_z;
}

Quaternion::~Quaternion()
{
}

Quaternion& Quaternion::operator=(const Quaternion& other)
{
	m_w = other.m_w;
	m_x = other.m_x;
	m_y = other.m_y;
	m_z = other.m_z;
	return *this;
}

void Quaternion::createUnit(float w, float x, float y, float z)
{
	m_w = static_cast<float>(cos(w * 0.5f));
	float sn = static_cast<float>(sin(w * 0.5f));
	m_x = sn * x;
	m_y = sn * y;
	m_z = sn * z;
}


bool operator==(const Quaternion& q1, const Quaternion& q2) 
{
	return q1.m_w == q2.m_w && 
		q1.m_x == q2.m_x &&
		q1.m_y == q2.m_y &&
		q1.m_z == q2.m_z;
}

bool operator!=(const Quaternion& q1, const Quaternion& q2)
{
	return !(q1 == q2);
}
