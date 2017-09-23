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
	void set(const Vector2& other);

	float lengthSq() const;
	float length() const;

	void normalise();
	Vector2 normalised() const;
	
	void rotate(float degrees);
	Vector2 rotated(float degrees) const;

private:

	float m_x;
	float m_y;

	// Cached length, length squared
	mutable float m_lengthSq;
	mutable float m_length;

	// Cached unit vector values
	mutable float m_unitX;
	mutable float m_unitY;

	// Dirty flag for cached unit vector, lengthSq, length
	mutable bool m_dirty;
	
	void updateCache() const;

};


bool operator==(const Vector2& v1, const Vector2& v2);
bool operator!=(const Vector2& v1, const Vector2& v2);
Vector2 operator*(const Vector2& v, const float scalar);
Vector2 operator*(const float scalar, const Vector2& v);
Vector2 operator/(const Vector2& v, const float divisor);
Vector2 operator/(const float divisor, const Vector2& v);
Vector2 operator+(const Vector2& v1, const Vector2& v2);
Vector2 operator-(const Vector2& v1, const Vector2& v2);
