#pragma once


class MathUtil
{
public:

	static constexpr float PI = 3.14159265f;
	static constexpr float DEG_TO_RAD = PI / 180.0f;
	static constexpr float RAD_TO_DEG = 180.0f / PI;

	static constexpr float radians(float degs)
	{
		return DEG_TO_RAD * degs;
	}

	static constexpr float degrees(float rads)
	{
		return RAD_TO_DEG * rads;
	}

};
