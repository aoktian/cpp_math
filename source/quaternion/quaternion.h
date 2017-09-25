#pragma once

class Vector3;


class Quaternion
{
public:

	Quaternion(float w = 1.0f, float x = 0.0f, float y = 0.0f, float z = 0.0f);
	Quaternion(const float angle, const Vector3& axis);
	Quaternion(const Quaternion& other);
	~Quaternion();

	Quaternion& operator=(const Quaternion& other);
	
	inline float w() const { return m_w; }
	inline float x() const { return m_x; }
	inline float y() const { return m_y; }
	inline float z() const { return m_z; }

private:

	friend bool operator==(const Quaternion& v1, const Quaternion& v2);
	friend bool operator!=(const Quaternion& v1, const Quaternion& v2);

	void createUnit(float w, float x, float y, float z);

	float m_w;
	float m_x;
	float m_y;
	float m_z;

};


bool operator==(const Quaternion& q1, const Quaternion& q2);
bool operator!=(const Quaternion& q1, const Quaternion& q2);
