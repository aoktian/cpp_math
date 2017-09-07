#pragma once


class Vector2
{
public:
	
	Vector2(float x = 0.0f, float y = 0.0f);
	Vector2(const Vector2& other);

	~Vector2();

	Vector2& operator=(const Vector2& other);
	Vector2& operator*=(const float scalar);
	Vector2& operator/=(const float divisor);
	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	
	inline float x() const { return m_x; }
	inline float y() const { return m_y; }

	void setX(float val);
	void setY(float val);
	void set(float x, float y);
	void set(float val);

	float lengthSq();
	float length();

	void normalise();
	Vector2 normalised();
	
	void rotate(float degrees);
	Vector2 rotated(float degrees);

private:

	float m_x;
	float m_y;

	// Cached length, length squared
	float m_lengthSq;
	float m_length;

	// Cached unit vector values
	float m_unitX;
	float m_unitY;

	// Dirty flag for cached unit vector, lengthSq, length
	bool m_dirty;
	
	void updateCache();

};


bool operator==(const Vector2& v1, const Vector2& v2);
bool operator!=(const Vector2& v1, const Vector2& v2);
Vector2 operator*(const Vector2& v, const float scalar);
Vector2 operator*(const float scalar, const Vector2& v);
Vector2 operator/(const Vector2& v, const float divisor);
Vector2 operator/(const float divisor, const Vector2& v);
Vector2 operator+(const Vector2& v1, const Vector2& v2);
Vector2 operator-(const Vector2& v1, const Vector2& v2);
