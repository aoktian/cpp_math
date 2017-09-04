#include "vector/vector2UnitTest.h"


void runVector2Test();
void runVector3Test();
void runMatrix2Test();
void runMatrix3Test();


int main()
{
	runVector2Test();
	runVector3Test();
	runMatrix2Test();
	runMatrix3Test();

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
	Vector2UnitTest::vector2Test_EqualityOperator();
	Vector2UnitTest::vector2Test_InequalityOperator();
	Vector2UnitTest::vector2Test_MultiplyOperator();
	Vector2UnitTest::vector2Test_DivisionOperator();
	Vector2UnitTest::vector2Test_AdditionOperator();
	Vector2UnitTest::vector2Test_SubtractionOperator();
}

void runVector3Test()
{
}

void runMatrix2Test()
{
}

void runMatrix3Test()
{
}
