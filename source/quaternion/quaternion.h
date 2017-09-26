#pragma once

class Matrix4;
class Vector3;


class Quaternion
{
public:

	Quaternion(float radians = 0.0f, float x = 0.0f, float y = 0.0f, float z = 0.0f);
	Quaternion(const float radians, const Vector3& axis);
	Quaternion(const Quaternion& other);
	~Quaternion();

	Quaternion& operator=(const Quaternion& other);
	
	inline float w() const { return m_w; }
	inline float x() const { return m_x; }
	inline float y() const { return m_y; }
	inline float z() const { return m_z; }

	Matrix4 rotationMatrix() const;

private:

	friend bool operator==(const Quaternion& v1, const Quaternion& v2);
	friend bool operator!=(const Quaternion& v1, const Quaternion& v2);

	void createUnit(float radians, const Vector3& axis);
	void createUnit(float radians, float x, float y, float z);
	void normalise();

	float m_w;
	float m_x;
	float m_y;
	float m_z;

};


bool operator==(const Quaternion& q1, const Quaternion& q2);
bool operator!=(const Quaternion& q1, const Quaternion& q2);
