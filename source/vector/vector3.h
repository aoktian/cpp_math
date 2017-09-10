#pragma once


class Vector3
{
public:

	Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	Vector3(const Vector3& other);

	~Vector3();

	Vector3& operator=(const Vector3& other);
	Vector3& operator*=(const float scalar);
	Vector3& operator/=(const float divisor);
	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);

	// Ste - TODO - Matrix multiplication overload

	inline float x() const { return m_x; }
	inline float y() const { return m_y; }
	inline float z() const { return m_z; }

	void setX(float val);
	void setY(float val);
	void setZ(float val);
	void set(float x, float y, float z);
	void set(float val);
	void set(const Vector3& other);

	float lengthSq() const;
	float length() const;

	void normalise();
	Vector3 normalised() const;

	float dotProduct(const Vector3& other) const;
	static float dotProduct(const Vector3& v1, const Vector3& v2);
	
	Vector3 crossProduct(const Vector3& other) const;
	static Vector3 crossProduct(const Vector3& v1, const Vector3& v2);

	float angle(const Vector3& other) const;
	static float angle(const Vector3& v1, const Vector3& v2);
	
private:

	float m_x;
	float m_y;
	float m_z;

	// Cached length, length squared
	mutable float m_lengthSq;
	mutable float m_length;

	// Cached unit vector values
	mutable float m_unitX;
	mutable float m_unitY;
	mutable float m_unitZ;

	// Dirty flag for cached values
	mutable bool m_dirty;

	void updateCache() const;

};


bool operator==(const Vector3& v1, const Vector3& v2);
bool operator!=(const Vector3& v1, const Vector3& v2);
Vector3 operator*(const Vector3& v, const float scalar);
Vector3 operator*(const float scalar, const Vector3& v);
Vector3 operator/(const Vector3& v, const float divisor);
Vector3 operator/(const float divisor, const Vector3& v);
Vector3 operator+(const Vector3& v1, const Vector3& v2);
Vector3 operator-(const Vector3& v1, const Vector3& v2);

// Ste - TODO - Matrix multiplication overloads
