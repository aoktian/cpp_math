#include "matrix4.h"


Matrix4::Matrix4()
{
	identity();
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
	// Ste - TODO
	return *this;
}

Matrix4& Matrix4::identity()
{
	m_ix = 1.0f; m_jx = 0.0f; m_kx = 0.0f; m_tx = 0.0f;
	m_iy = 0.0f; m_jy = 1.0f; m_ky = 0.0f; m_ty = 0.0f;
	m_iz = 0.0f; m_jz = 0.0f; m_kz = 1.0f; m_tz = 0.0f;
	m_iw = 0.0f; m_jw = 0.0f; m_kw = 0.0f; m_tw = 1.0f;
	return *this;
}


Matrix4 operator+(const Matrix4& m1, const Matrix4& m2)
{
	// Ste - TODO
	Matrix4 result;
	return result;
}

Matrix4 operator-(const Matrix4& m1, const Matrix4& m2)
{
	// Ste - TODO
	Matrix4 result;
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
