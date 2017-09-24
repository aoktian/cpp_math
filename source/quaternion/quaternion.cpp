#include "quaternion.h"

#include "../vector/vector3.h"

Quaternion::Quaternion(float w /* = 1.0f */, float x /* = 0.0f */, float y /* = 0.0f */, float z /* = 0.0f */)
{
	create(w, x, y, z);
}

Quaternion::Quaternion(const Vector3& axis, const float angle)
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

void Quaternion::create(float w, float x, float y, float z)
{
	// Ste - TODO - calculate values here!
	// [http://wiki.roblox.com/index.php?title=Quaternions_for_rotation]
	float qw = 0.0f;
	float qx = 0.0f;
	float qy = 0.0f;
	float qz = 0.0f;
	// ----------

	m_w = qw;
	m_x = qx;
	m_y = qy;
	m_z = qz;
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
