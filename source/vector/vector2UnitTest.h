#pragma once

#include "vector2.h"


class Vector2UnitTest
{
public:
	
	Vector2UnitTest();
	~Vector2UnitTest();

	Vector2UnitTest(const Vector2UnitTest& other) = delete;
	Vector2UnitTest operator=(const Vector2UnitTest& other) = delete;

	static void vector2Test_DefaultConstructor();
	static void vector2Test_CopyConstructor();

	static void vector2Test_AssignmentOperator();
	static void vector2Test_TimesEqualsOperator();
	static void vector2Test_DivideEqualsOperator();
	static void vector2Test_PlusEqualsOperator();
	static void vector2Test_MinusEqualsOperator();

	static void vector2Test_SetX();
	static void vector2Test_SetY();
	static void vector2Test_SetXY();
	static void vector2Test_SetSingleValue();

	static void vector2Test_LengthSq();
	static void vector2Test_Length();

	static void vector2Test_Normalise();
	static void vector2Test_Normalised();

	static void vector2Test_EqualityOperator();
	static void vector2Test_InequalityOperator();
	static void vector2Test_MultiplyOperator();
	static void vector2Test_DivisionOperator();
	static void vector2Test_AdditionOperator();
	static void vector2Test_SubtractionOperator();

private:

	static const float TOLERANCE;

};
