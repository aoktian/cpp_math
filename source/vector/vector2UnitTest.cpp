#include "vector2UnitTest.h"

#include <assert.h>


Vector2UnitTest::Vector2UnitTest()
{
}

Vector2UnitTest::~Vector2UnitTest()
{
}

void Vector2UnitTest::Vector2Test_DefaultConstructor()
{
	assert(Vector2().x() == 0.0f);
	assert(Vector2().y() == 0.0f);
	assert(Vector2(10.0f).x() == 10.0f);
	assert(Vector2(10.0f).y() == 0.0f);
	assert(Vector2(10.0f, 10.0f).x() == 10.0f);
	assert(Vector2(10.0f, 10.0f).y() == 10.0f);
}

void Vector2UnitTest::Vector2Test_CopyConstructor()
{

}

void Vector2UnitTest::Vector2Test_SingleValueConstructor()
{

}

void Vector2UnitTest::Vector2Test_AssignmentOperator()
{

}

void Vector2UnitTest::Vector2Test_TimesEqualsOperator()
{

}

void Vector2UnitTest::Vector2Test_DivideEqualsOperator()
{

}

void Vector2UnitTest::Vector2Test_PlusEqualsOperator()
{

}

void Vector2UnitTest::Vector2Test_MinusEqualsOperator()
{

}

void Vector2UnitTest::Vector2Test_SetX()
{

}

void Vector2UnitTest::Vector2Test_SetY()
{

}

void Vector2UnitTest::Vector2Test_SetXY()
{

}

void Vector2UnitTest::Vector2Test_SetSingleValue()
{

}

void Vector2UnitTest::Vector2Test_LengthSq()
{

}

void Vector2UnitTest::Vector2Test_Length()
{

}

void Vector2UnitTest::Vector2Test_Normalise()
{

}

void Vector2UnitTest::Vector2Test_Normalised()
{

}

void Vector2UnitTest::Vector2Test_EqualityOperator()
{

}

void Vector2UnitTest::Vector2Test_InequalityOperator()
{

}

void Vector2UnitTest::Vector2Test_MultiplyOperator()
{

}

void Vector2UnitTest::Vector2Test_DivisionOperator()
{

}

void Vector2UnitTest::Vector2Test_AdditionOperator()
{

}

void Vector2UnitTest::Vector2Test_SubtractionOperator()
{

}
