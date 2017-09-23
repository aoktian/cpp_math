#include "matrix4.h"

#include <math.h>
#include "../vector/vector3.h"


Matrix4::Matrix4()
{
	toIdentity();
}

Matrix4::Matrix4(const Matrix4& other)
	: Matrix4()
{
	m_ix = other.m_ix; m_jx = other.m_jx; m_kx = other.m_kx; m_tx = other.m_tx;
	m_iy = other.m_iy; m_jy = other.m_jy; m_ky = other.m_ky; m_ty = other.m_ty;
	m_iz = other.m_iz; m_jz = other.m_jz; m_kz = other.m_kz; m_tz = other.m_tz;
	m_iw = other.m_iw; m_jw = other.m_jw; m_kw = other.m_kw; m_tw = other.m_tw;
}

Matrix4::~Matrix4()
{
}

Matrix4& Matrix4::operator=(const Matrix4& other)
{
	m_ix = other.m_ix; m_jx = other.m_jx; m_kx = other.m_kx; m_tx = other.m_tx;
	m_iy = other.m_iy; m_jy = other.m_jy; m_ky = other.m_ky; m_ty = other.m_ty;
	m_iz = other.m_iz; m_jz = other.m_jz; m_kz = other.m_kz; m_tz = other.m_tz;
	m_iw = other.m_iw; m_jw = other.m_jw; m_kw = other.m_kw; m_tw = other.m_tw;
	return *this;
}

Matrix4& Matrix4::operator+=(const Matrix4& other)
{
	m_ix += other.m_ix; m_iy += other.m_iy; m_iz += other.m_iz;
	m_jx += other.m_jx; m_jy += other.m_jy; m_jz += other.m_jz;
	m_kx += other.m_kx; m_ky += other.m_ky; m_kz += other.m_kz;
	m_tx += other.m_tx; m_ty += other.m_ty; m_tz += other.m_tz;
	return *this;
}

Matrix4& Matrix4::operator-=(const Matrix4& other)
{
	m_ix -= other.m_ix; m_iy -= other.m_iy; m_iz -= other.m_iz;
	m_jx -= other.m_jx; m_jy -= other.m_jy; m_jz -= other.m_jz;
	m_kx -= other.m_kx; m_ky -= other.m_ky; m_kz -= other.m_kz;
	m_tx -= other.m_tx; m_ty -= other.m_ty; m_tz -= other.m_tz;
	return *this;
}

Matrix4& Matrix4::operator*=(const Matrix4& other)
{
	float ix = m_ix * other.m_ix + m_jx * other.m_iy + m_kx * other.m_iz + m_tx * other.m_iw;
	float iy = m_iy * other.m_ix + m_jy * other.m_iy + m_ky * other.m_iz + m_ty * other.m_iw;
	float iz = m_iz * other.m_ix + m_jz * other.m_iy + m_kz * other.m_iz + m_tz * other.m_iw;
	float iw = m_iw * other.m_ix + m_jw * other.m_iy + m_kw * other.m_iz + m_tw * other.m_iw;
	float jx = m_ix * other.m_jx + m_jx * other.m_jy + m_kx * other.m_jz + m_tx * other.m_jw;
	float jy = m_iy * other.m_jx + m_jy * other.m_jy + m_ky * other.m_jz + m_ty * other.m_jw;
	float jz = m_iz * other.m_jx + m_jz * other.m_jy + m_kz * other.m_jz + m_tz * other.m_jw;
	float jw = m_iw * other.m_jx + m_jw * other.m_jy + m_kw * other.m_jz + m_tw * other.m_jw;
	float kx = m_ix * other.m_kx + m_jx * other.m_ky + m_kx * other.m_kz + m_tx * other.m_kw;
	float ky = m_iy * other.m_kx + m_jy * other.m_ky + m_ky * other.m_kz + m_ty * other.m_kw;
	float kz = m_iz * other.m_kx + m_jz * other.m_ky + m_kz * other.m_kz + m_tz * other.m_kw;
	float kw = m_iw * other.m_kx + m_jw * other.m_ky + m_kw * other.m_kz + m_tw * other.m_kw;
	float tx = m_ix * other.m_tx + m_jx * other.m_ty + m_kx * other.m_tz + m_tx * other.m_tw;
	float ty = m_iy * other.m_tx + m_jy * other.m_ty + m_ky * other.m_tz + m_ty * other.m_tw;
	float tz = m_iz * other.m_tx + m_jz * other.m_ty + m_kz * other.m_tz + m_tz * other.m_tw;
	float tw = m_iw * other.m_tx + m_jw * other.m_ty + m_kw * other.m_tz + m_tw * other.m_tw;

	m_ix = ix; m_jx = jx; m_kx = kx; m_tx = tx;
	m_iy = iy; m_jy = jy; m_ky = ky; m_ty = ty;
	m_iz = iz; m_jz = jz; m_kz = kz; m_tz = tz;
	m_iw = iw; m_jw = jw; m_kw = kw; m_tw = tw;
	return *this;
}

Matrix4& Matrix4::toIdentity()
{
	m_ix = 1.0f; m_jx = 0.0f; m_kx = 0.0f; m_tx = 0.0f;
	m_iy = 0.0f; m_jy = 1.0f; m_ky = 0.0f; m_ty = 0.0f;
	m_iz = 0.0f; m_jz = 0.0f; m_kz = 1.0f; m_tz = 0.0f;
	m_iw = 0.0f; m_jw = 0.0f; m_kw = 0.0f; m_tw = 1.0f;
	return *this;
}

Matrix4 Matrix4::identity()
{
	Matrix4 result;
	result.m_ix = 1.0f; result.m_jx = 0.0f; result.m_kx = 0.0f; result.m_tx = 0.0f;
	result.m_iy = 0.0f; result.m_jy = 1.0f; result.m_ky = 0.0f; result.m_ty = 0.0f;
	result.m_iz = 0.0f; result.m_jz = 0.0f; result.m_kz = 1.0f; result.m_tz = 0.0f;
	result.m_iw = 0.0f; result.m_jw = 0.0f; result.m_kw = 0.0f; result.m_tw = 1.0f;
	return result;
}

Matrix4 Matrix4::scale(float s)
{
	Matrix4 result;
	result.m_ix = s;
	result.m_jy = s;
	result.m_kz = s;
	return result;
}

Matrix4 Matrix4::scale(float sx, float sy, float sz)
{
	Matrix4 result;
	result.m_ix = sx;
	result.m_jy = sy;
	result.m_kz = sz;
	return result;
}

Matrix4 Matrix4::scale(const Vector3& s)
{
	return scale(s.x(), s.y(), s.z());
}

Matrix4 Matrix4::yaw(float y)
{
	Matrix4 result;

	float cs = static_cast<float>(cos(y));
	float sn = static_cast<float>(sin(y));
	result.m_ix = cs;
	result.m_iz = -sn;
	result.m_kx = sn;
	result.m_kz = cs;
	return result;
}

Matrix4 Matrix4::pitch(float p)
{
	Matrix4 result;
	float cs = static_cast<float>(cos(p));
	float sn = static_cast<float>(sin(p));
	result.m_jy = cs;
	result.m_jz = sn;
	result.m_ky = -sn;
	result.m_kz = cs;
	return result;
}

Matrix4 Matrix4::roll(float r)
{
	Matrix4 result;
	float cs = static_cast<float>(cos(r));
	float sn = static_cast<float>(sin(r));
	result.m_ix = cs;
	result.m_iy = sn;
	result.m_jx = -sn;
	result.m_jy = cs;
	return result;
}

Matrix4 Matrix4::rotation(float yaw, float pitch, float roll)
{
	Matrix4 result;
	if (yaw)
	{
		result = Matrix4::yaw(yaw);
		if (pitch) { result *= Matrix4::pitch(pitch); }
		if (roll) { result *= Matrix4::roll(roll); }
	}
	else if (pitch)
	{
		result = Matrix4::pitch(pitch);
		if (roll) { result *= Matrix4::roll(roll); }
	}
	else if (roll)
	{
		result = Matrix4::roll(roll);
	}
	return result;
}

Matrix4 Matrix4::rotation(const Vector3& r)
{
	return rotation(r.x(), r.y(), r.z());
}

Matrix4 Matrix4::translation(float x, float y, float z)
{
	Matrix4 result;
	result.m_tx = x;
	result.m_ty = y;
	result.m_tz = z;
	return result;
}

Matrix4 Matrix4::translation(const Vector3& t)
{
	return translation(t.x(), t.y(), t.z());
}


Matrix4 operator+(const Matrix4& m1, const Matrix4& m2)
{
	Matrix4 result;
	result.m_ix = m1.m_ix + m2.m_ix;
	result.m_jx = m1.m_jx + m2.m_jx;
	result.m_kx = m1.m_kx + m2.m_kx;
	result.m_tx = m1.m_tx + m2.m_tx;
	result.m_iy = m1.m_iy + m2.m_iy;
	result.m_jy = m1.m_jy + m2.m_jy;
	result.m_ky = m1.m_ky + m2.m_ky;
	result.m_ty = m1.m_ty + m2.m_ty;
	result.m_iz = m1.m_iz + m2.m_iz;
	result.m_jz = m1.m_jz + m2.m_jz;
	result.m_kz = m1.m_kz + m2.m_kz;
	result.m_tz = m1.m_tz + m2.m_tz;
	return result;
}

Matrix4 operator-(const Matrix4& m1, const Matrix4& m2)
{
	Matrix4 result;
	result.m_ix = m1.m_ix - m2.m_ix;
	result.m_jx = m1.m_jx - m2.m_jx;
	result.m_kx = m1.m_kx - m2.m_kx;
	result.m_tx = m1.m_tx - m2.m_tx;
	result.m_iy = m1.m_iy - m2.m_iy;
	result.m_jy = m1.m_jy - m2.m_jy;
	result.m_ky = m1.m_ky - m2.m_ky;
	result.m_ty = m1.m_ty - m2.m_ty;
	result.m_iz = m1.m_iz - m2.m_iz;
	result.m_jz = m1.m_jz - m2.m_jz;
	result.m_kz = m1.m_kz - m2.m_kz;
	result.m_tz = m1.m_tz - m2.m_tz;
	return result;
}

Matrix4 operator*(const Matrix4& m1, const Matrix4& m2)
{
	Matrix4 result;
	result.m_ix = m1.m_ix * m2.m_ix + m1.m_jx * m2.m_iy + m1.m_kx * m2.m_iz + m1.m_tx * m2.m_iw;
	result.m_iy = m1.m_iy * m2.m_ix + m1.m_jy * m2.m_iy + m1.m_ky * m2.m_iz + m1.m_ty * m2.m_iw;
	result.m_iz = m1.m_iz * m2.m_ix + m1.m_jz * m2.m_iy + m1.m_kz * m2.m_iz + m1.m_tz * m2.m_iw;
	result.m_iw = m1.m_iw * m2.m_ix + m1.m_jw * m2.m_iy + m1.m_kw * m2.m_iz + m1.m_tw * m2.m_iw;
	result.m_jx = m1.m_ix * m2.m_jx + m1.m_jx * m2.m_jy + m1.m_kx * m2.m_jz + m1.m_tx * m2.m_jw;
	result.m_jy = m1.m_iy * m2.m_jx + m1.m_jy * m2.m_jy + m1.m_ky * m2.m_jz + m1.m_ty * m2.m_jw;
	result.m_jz = m1.m_iz * m2.m_jx + m1.m_jz * m2.m_jy + m1.m_kz * m2.m_jz + m1.m_tz * m2.m_jw;
	result.m_jw = m1.m_iw * m2.m_jx + m1.m_jw * m2.m_jy + m1.m_kw * m2.m_jz + m1.m_tw * m2.m_jw;
	result.m_kx = m1.m_ix * m2.m_kx + m1.m_jx * m2.m_ky + m1.m_kx * m2.m_kz + m1.m_tx * m2.m_kw;
	result.m_ky = m1.m_iy * m2.m_kx + m1.m_jy * m2.m_ky + m1.m_ky * m2.m_kz + m1.m_ty * m2.m_kw;
	result.m_kz = m1.m_iz * m2.m_kx + m1.m_jz * m2.m_ky + m1.m_kz * m2.m_kz + m1.m_tz * m2.m_kw;
	result.m_kw = m1.m_iw * m2.m_kx + m1.m_jw * m2.m_ky + m1.m_kw * m2.m_kz + m1.m_tw * m2.m_kw;
	result.m_tx = m1.m_ix * m2.m_tx + m1.m_jx * m2.m_ty + m1.m_kx * m2.m_tz + m1.m_tx * m2.m_tw;
	result.m_ty = m1.m_iy * m2.m_tx + m1.m_jy * m2.m_ty + m1.m_ky * m2.m_tz + m1.m_ty * m2.m_tw;
	result.m_tz = m1.m_iz * m2.m_tx + m1.m_jz * m2.m_ty + m1.m_kz * m2.m_tz + m1.m_tz * m2.m_tw;
	result.m_tw = m1.m_iw * m2.m_tx + m1.m_jw * m2.m_ty + m1.m_kw * m2.m_tz + m1.m_tw * m2.m_tw;
	return result;
}
