#pragma once

class Vector3;


// Ste - TODO [http://wiki.roblox.com/index.php?title=Quaternions_for_rotation]
class Quaternion
{
public:

	Quaternion();
	Quaternion(const Vector3& axis, const float angle);
	Quaternion(const Quaternion& other);
	~Quaternion();

	Quaternion& operator=(const Quaternion& other);
	
private:

	friend bool operator==(const Quaternion& v1, const Quaternion& v2);
	friend bool operator!=(const Quaternion& v1, const Quaternion& v2);

	void set(float w, float x, float y, float z);

	float m_w;
	float m_x;
	float m_y;
	float m_z;

	// Ste - TODO - mutable lazy evaluation values

};


bool operator==(const Quaternion& q1, const Quaternion& q2);
bool operator!=(const Quaternion& q1, const Quaternion& q2);
