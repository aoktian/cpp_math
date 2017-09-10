#pragma once

class Vector3;


class Matrix4
{
public:

	Matrix4();
	Matrix4(const Matrix4& other);
	~Matrix4();

	Matrix4& operator=(const Matrix4& other);
	Matrix4& operator+=(const Matrix4& other);
	Matrix4& operator-=(const Matrix4& other);
	Matrix4& operator*=(const Matrix4& other);
	
	Matrix4& toIdentity();

	static Matrix4 identity();
	static Matrix4 scale(float s);
	static Matrix4 scale(float sx, float sy, float sz);
	static Matrix4 scale(const Vector3& s);
	static Matrix4 yaw(float y);
	static Matrix4 pitch(float p);
	static Matrix4 roll(float r);
	static Matrix4 rotation(float y, float p, float r);
	static Matrix4 rotation(const Vector3& r);
	static Matrix4 translation(float x, float y, float z);
	static Matrix4 translation(const Vector3& t);

private:

	friend Matrix4 operator+(const Matrix4& m1, const Matrix4& m2);
	friend Matrix4 operator-(const Matrix4& m1, const Matrix4& m2);
	friend Matrix4 operator*(const Matrix4& m1, const Matrix4& m2);

	float m_ix, m_jx, m_kx, m_tx;
	float m_iy, m_jy, m_ky, m_ty;
	float m_iz, m_jz, m_kz, m_tz;
	float m_iw, m_jw, m_kw, m_tw;

};


Matrix4 operator+(const Matrix4& m1, const Matrix4& m2);
Matrix4 operator-(const Matrix4& m1, const Matrix4& m2);
Matrix4 operator*(const Matrix4& m1, const Matrix4& m2);
