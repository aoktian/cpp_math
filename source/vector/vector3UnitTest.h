#pragma once

#include "vector3.h"


class Vector3UnitTest
{
public:
	
	static void vector3Test_DefaultConstructor();
	static void vector3Test_CopyConstructor();

	static void vector3Test_AssignmentOperator();
	static void vector3Test_TimesEqualsOperator();
	static void vector3Test_DivideEqualsOperator();
	static void vector3Test_PlusEqualsOperator();
	static void vector3Test_MinusEqualsOperator();

	static void vector3Test_SetX();
	static void vector3Test_SetY();
	static void vector3Test_SetZ();
	static void vector3Test_SetXYZ();
	static void vector3Test_SetSingleValue();

	static void vector3Test_LengthSq();
	static void vector3Test_Length();

	static void vector3Test_Normalise();
	static void vector3Test_Normalised();

	static void vector3Test_EqualityOperator();
	static void vector3Test_InequalityOperator();
	static void vector3Test_MultiplyOperator();
	static void vector3Test_DivisionOperator();
	static void vector3Test_AdditionOperator();
	static void vector3Test_SubtractionOperator();

private:

	static const float TOLERANCE;

};
