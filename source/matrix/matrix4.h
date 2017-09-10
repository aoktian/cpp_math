#pragma once


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

	static Matrix4 identityMatrix();
	static Matrix4 scaleMatrix(float scale);
	static Matrix4 scaleMatrix(float sx, float sy, float sz);
	static Matrix4 yawMatrix(float yaw);
	static Matrix4 pitchMatrix(float pitch);
	static Matrix4 rollMatrix(float roll);
	static Matrix4 rotationMatrix(float yaw, float pitch, float roll);
	static Matrix4 translationMatrix(float x, float y, float z);

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
