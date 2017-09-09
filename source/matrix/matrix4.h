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
	
	Matrix4& identity();

	/*inline float ix() const { return m_ix; }
	inline float jx() const { return m_jx; }
	inline float kx() const { return m_kx; }
	inline float tx() const { return m_tx; }
	inline float iy() const { return m_iy; }
	inline float jy() const { return m_jy; }
	inline float ky() const { return m_ky; }
	inline float ty() const { return m_ty; }
	inline float iz() const { return m_iz; }
	inline float jz() const { return m_jz; }
	inline float kz() const { return m_kz; }
	inline float tz() const { return m_tz; }
	inline float iw() const { return m_iw; }
	inline float jw() const { return m_jw; }
	inline float kw() const { return m_kw; }
	inline float tw() const { return m_tw; }*/

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
