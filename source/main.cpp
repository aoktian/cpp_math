#include "vector/vector2UnitTest.h"
#include "vector/vector3UnitTest.h"


void runVector2Test();
void runVector3Test();
void runMatrix4Test();
void runQuaternionTest();

int main()
{
	runVector2Test();
	runVector3Test();
	runMatrix4Test();
	runQuaternionTest();
	return 0;
}

void runVector2Test()
{
	Vector2UnitTest::vector2Test_DefaultConstructor();
	Vector2UnitTest::vector2Test_CopyConstructor();
	Vector2UnitTest::vector2Test_TimesEqualsOperator();
	Vector2UnitTest::vector2Test_DivideEqualsOperator();
	Vector2UnitTest::vector2Test_PlusEqualsOperator();
	Vector2UnitTest::vector2Test_MinusEqualsOperator();
	Vector2UnitTest::vector2Test_SetX();
	Vector2UnitTest::vector2Test_SetY();
	Vector2UnitTest::vector2Test_SetXY();
	Vector2UnitTest::vector2Test_SetSingleValue();
	Vector2UnitTest::vector2Test_LengthSq();
	Vector2UnitTest::vector2Test_Length();
	Vector2UnitTest::vector2Test_Normalise();
	Vector2UnitTest::vector2Test_Normalised();
	Vector2UnitTest::vector2Test_Rotate();
	Vector2UnitTest::vector2Test_Rotated();
	Vector2UnitTest::vector2Test_EqualityOperator();
	Vector2UnitTest::vector2Test_InequalityOperator();
	Vector2UnitTest::vector2Test_MultiplyOperator();
	Vector2UnitTest::vector2Test_DivisionOperator();
	Vector2UnitTest::vector2Test_AdditionOperator();
	Vector2UnitTest::vector2Test_SubtractionOperator();
}

void runVector3Test()
{
	Vector3UnitTest::vector3Test_DefaultConstructor();
	Vector3UnitTest::vector3Test_CopyConstructor();
	Vector3UnitTest::vector3Test_AssignmentOperator();
	Vector3UnitTest::vector3Test_TimesEqualsOperator();
	Vector3UnitTest::vector3Test_DivideEqualsOperator();
	Vector3UnitTest::vector3Test_PlusEqualsOperator();
	Vector3UnitTest::vector3Test_MinusEqualsOperator();
	Vector3UnitTest::vector3Test_SetX();
	Vector3UnitTest::vector3Test_SetY();
	Vector3UnitTest::vector3Test_SetZ();
	Vector3UnitTest::vector3Test_SetXYZ();
	Vector3UnitTest::vector3Test_SetSingleValue();
	Vector3UnitTest::vector3Test_LengthSq();
	Vector3UnitTest::vector3Test_Length();
	Vector3UnitTest::vector3Test_Normalise();
	Vector3UnitTest::vector3Test_Normalised();
	Vector3UnitTest::vector3Test_EqualityOperator();
	Vector3UnitTest::vector3Test_InequalityOperator();
	Vector3UnitTest::vector3Test_MultiplyOperator();
	Vector3UnitTest::vector3Test_DivisionOperator();
	Vector3UnitTest::vector3Test_AdditionOperator();
	Vector3UnitTest::vector3Test_SubtractionOperator();
}

void runMatrix4Test()
{
}

void runQuaternionTest()
{
}
