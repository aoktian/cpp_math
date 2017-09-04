#pragma once

#include "vector2.h"


class Vector2UnitTest
{
public:
	
	Vector2UnitTest();
	~Vector2UnitTest();

	Vector2UnitTest(const Vector2UnitTest& other) = delete;
	Vector2UnitTest operator=(const Vector2UnitTest& other) = delete;

	void Vector2Test_DefaultConstructor();
	void Vector2Test_CopyConstructor();
	void Vector2Test_SingleValueConstructor();

	void Vector2Test_AssignmentOperator();
	void Vector2Test_TimesEqualsOperator();
	void Vector2Test_DivideEqualsOperator();
	void Vector2Test_PlusEqualsOperator();
	void Vector2Test_MinusEqualsOperator();

	void Vector2Test_SetX();
	void Vector2Test_SetY();
	void Vector2Test_SetXY();
	void Vector2Test_SetSingleValue();
	
	void Vector2Test_LengthSq();
	void Vector2Test_Length();

	void Vector2Test_Normalise();
	void Vector2Test_Normalised();

	void Vector2Test_EqualityOperator();
	void Vector2Test_InequalityOperator();
	void Vector2Test_MultiplyOperator();
	void Vector2Test_DivisionOperator();
	void Vector2Test_AdditionOperator();
	void Vector2Test_SubtractionOperator();

};
