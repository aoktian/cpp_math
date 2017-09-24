#pragma once

class Vector3;


class Quaternion
{
public:

	Quaternion(float w = 1.0f, float x = 0.0f, float y = 0.0f, float z = 0.0f);
	Quaternion(const Vector3& axis, const float angle);
	Quaternion(const Quaternion& other);
	~Quaternion();

	Quaternion& operator=(const Quaternion& other);
	
private:

	friend bool operator==(const Quaternion& v1, const Quaternion& v2);
	friend bool operator!=(const Quaternion& v1, const Quaternion& v2);

	void create(float w, float x, float y, float z);

	float m_w;
	float m_x;
	float m_y;
	float m_z;

};


bool operator==(const Quaternion& q1, const Quaternion& q2);
bool operator!=(const Quaternion& q1, const Quaternion& q2);
