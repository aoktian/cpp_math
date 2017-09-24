#include "quaternion.h"

#include "../vector/vector3.h"

Quaternion::Quaternion()
{
	set(1.0f, 0.0f, 0.0f, 0.0f);
}

Quaternion::Quaternion(const Vector3& axis, const float angle)
{
	// Ste - TODO
}

Quaternion::Quaternion(const Quaternion& other)
{
	// Ste - TODO
}

Quaternion::~Quaternion()
{
}

Quaternion& Quaternion::operator=(const Quaternion& other)
{
	// Ste - TODO
}

void Quaternion::set(float w, float x, float y, float z)
{
	// Ste - TODO - calculate values here!
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