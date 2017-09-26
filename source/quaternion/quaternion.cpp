#include "quaternion.h"

#include <math.h>
#include "../matrix/matrix4.h"
#include "../vector/vector3.h"

Quaternion::Quaternion(float radians /* = 0.0f */, float x /* = 0.0f */, float y /* = 0.0f */, float z /* = 0.0f */)
{
	createUnit(radians, x, y, z);
}

Quaternion::Quaternion(const float radians, const Vector3& axis)
	: Quaternion(radians, axis.x(), axis.y(), axis.z())
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

Matrix4 Quaternion::rotationMatrix() const
{
	Matrix4 result;
	float wSq = m_w * m_w;
	float xSq = m_x * m_x;
	float ySq = m_y * m_y;
	float zSq = m_z * m_z;
	
	float twoW = m_w * 2.0f;
	float twoX = m_x * 2.0f;
	float twoY = m_y * 2.0f;
	
	float wx = twoW * m_x;
	float wy = twoW * m_y;
	float wz = twoW * m_z;
	float xy = twoX * m_y;
	float xz = twoX * m_z;
	float yz = twoY * m_z;

	result.m_ix = wSq + xSq - ySq - zSq;
	result.m_jx = xy - wz;
	result.m_kx = xz + wy;
	result.m_iy = xy + wz;
	result.m_jy = wSq - xSq + ySq - zSq;
	result.m_ky = yz - wx;
	result.m_iz = xz - wy;
	result.m_jz = yz + wx;
	result.m_kz = wSq - xSq - ySq + zSq;

	return result;
}

void Quaternion::createUnit(float radians, const Vector3& axis)
{
	const Vector3 n = axis.normalised();
	float angle = radians * 0.5f;
	m_w = static_cast<float>(cos(angle));
	float sn = static_cast<float>(sin(angle));
	m_x = n.x() * sn;
	m_y = n.y() * sn;
	m_z = n.z() * sn;
	normalise();
}

void Quaternion::createUnit(float radians, float x, float y, float z)
{
	createUnit(radians, Vector3(x, y, z));
}

void Quaternion::normalise()
{
	float sq = m_w * m_w +
		m_x * m_x + 
		m_y * m_y + 
		m_z * m_z;

	float inv = 1.0f / sq;
	m_w *= inv;
	m_x *= inv;
	m_y *= inv;
	m_z *= inv;
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
