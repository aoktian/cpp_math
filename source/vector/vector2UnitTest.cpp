#include "vector2UnitTest.h"

#include <assert.h>
#include <math.h>


const float Vector2UnitTest::TOLERANCE = 0.000001f;

Vector2UnitTest::Vector2UnitTest()
{
}

Vector2UnitTest::~Vector2UnitTest()
{
}

void Vector2UnitTest::vector2Test_DefaultConstructor()
{
	assert(Vector2().x() == 0.0f);
	assert(Vector2().y() == 0.0f);
	assert(Vector2(10.0f).x() == 10.0f);
	assert(Vector2(20.0f).y() == 0.0f);
	assert(Vector2(10.0f, 20.0f).x() == 10.0f);
	assert(Vector2(10.0f, 20.0f).y() == 20.0f);

	Vector2 v1 = 5.0f;
	assert(v1.x() == 5.0f);
	assert(v1.y() == 0.0f);

	Vector2 v2 = { 5.0f, 20.0f };
	assert(v2.x() == 5.0f);
	assert(v2.y() == 2.0f);
}

void Vector2UnitTest::vector2Test_CopyConstructor()
{
	Vector2 v1(10.0f, 20.0f);
	assert(Vector2(v1).x() == 10.0f);
	assert(Vector2(v1).y() == 20.0f);
}

void Vector2UnitTest::vector2Test_AssignmentOperator()
{
	Vector2 v1(10.0f, 20.0f);
	Vector2 v2 = v1;
	assert(Vector2(v2).x() == 10.0f);
	assert(Vector2(v2).y() == 20.0f);
}

void Vector2UnitTest::vector2Test_TimesEqualsOperator()
{
	Vector2 v1(10.0f, 20.0f);
	v1 *= 2.0f;
	assert(v1.x() == 20.0f);
	assert(v1.y() == 40.0f);
}

void Vector2UnitTest::vector2Test_DivideEqualsOperator()
{
	Vector2 v1(10.0f, 20.0f);
	v1 /= 2.0f;
	assert(v1.x() == 5.0f);
	assert(v1.y() == 10.0f);
}

void Vector2UnitTest::vector2Test_PlusEqualsOperator()
{
	Vector2 v1(10.0f, 20.0f);
	Vector2 v2(5.0f, 10.0f);
	v2 += v1;
	assert(v1.x() == 10.0f);
	assert(v1.y() == 20.0f);
	assert(v2.x() == 15.0f);
	assert(v2.y() == 30.0f);
}

void Vector2UnitTest::vector2Test_MinusEqualsOperator()
{
	Vector2 v1(10.0f, 20.0f);
	Vector2 v2(5.0f, 10.0f);
	v2 -= v1;
	assert(v1.x() == 10.0f);
	assert(v1.y() == 20.0f);
	assert(v2.x() == -5.0f);
	assert(v2.y() == -10.0f);
}

void Vector2UnitTest::vector2Test_SetX()
{
	Vector2 v1(10.0f, 20.0f);
	v1.setX(30.0f);
	assert(v1.x() == 30.0f);
	assert(v1.y() == 20.0f);
}

void Vector2UnitTest::vector2Test_SetY()
{
	Vector2 v1(10.0f, 20.0f);
	v1.setY(30.0f);
	assert(v1.x() == 10.0f);
	assert(v1.y() == 30.0f);
}

void Vector2UnitTest::vector2Test_SetXY()
{
	Vector2 v1(10.0f, 20.0f);
	v1.set(5.0f, 6.0f);
	assert(v1.x() == 5.0f);
	assert(v1.y() == 6.0f);
}

void Vector2UnitTest::vector2Test_SetSingleValue()
{
	Vector2 v1(10.0f, 20.0f);
	v1.set(5.0f);
	assert(v1.x() == 5.0f);
	assert(v1.y() == 5.0f);
}

void Vector2UnitTest::vector2Test_LengthSq()
{
	assert(Vector2().lengthSq() == 0.0f);
	assert(Vector2(10.0f, 10.0f).lengthSq() == 200.0f);
	assert(Vector2(0.5f, 0.5f).lengthSq() == 0.5f);
}

void Vector2UnitTest::vector2Test_Length()
{
	assert(Vector2().length() == 0.0f);
	assert(fabs(Vector2(10.0f, 20.0f).length() - sqrt(10.0f * 10.0f + 20.0f * 20.0f)) < TOLERANCE);
	assert(fabs(Vector2(0.5f, 0.75f).length() - sqrt(0.5f * 0.5f + 0.75f * 0.75f)) < TOLERANCE);
}

void Vector2UnitTest::vector2Test_Normalise()
{
	Vector2 v1(10.0f, 20.0f);
	v1.normalise();
	assert(fabs(v1.x() - (10.0f / sqrt(500.0f))) < TOLERANCE);
	assert(fabs(v1.y() - (20.0f / sqrt(500.0f))) < TOLERANCE);
	assert(fabs(v1.length() -1.0f) < TOLERANCE);

	v1.set(0.0f, 1.0f);
	v1.normalise();
	assert(fabs(v1.x()) < TOLERANCE);
	assert(fabs(v1.y() - 1.0f) < TOLERANCE);
	assert(fabs(v1.length() - 1.0f) < TOLERANCE);
}

void Vector2UnitTest::vector2Test_Normalised()
{
	Vector2 v1(10.0f, 20.0f);
	assert(fabs(v1.normalised().x() - (10.0f / sqrt(500.0f))) < TOLERANCE);
	assert(fabs(v1.normalised().y() - (20.0f / sqrt(500.0f))) < TOLERANCE);
	assert(fabs(v1.normalised().length() - 1.0f) < TOLERANCE);

	v1.set(0.0f, 1.0f);
	assert(fabs(v1.normalised().x()) < TOLERANCE);
	assert(fabs(v1.normalised().y() - 1.0f) < TOLERANCE);
	assert(fabs(v1.normalised().length() - 1.0f) < TOLERANCE);
}

void Vector2UnitTest::vector2Test_EqualityOperator()
{
	Vector2 v1(10.0f, 20.0f);
	Vector2 v2(10.0f, 20.0f);
	Vector2 v3(20.0f, 10.0f);
	assert((v1 == v2) == true);
	assert((v2 == v1) == true);
	assert((v1 == v3) == false);
	assert((v3 == v1) == false);
	assert((v2 == v3) == false);
	assert((v3 == v2) == false);
}

void Vector2UnitTest::vector2Test_InequalityOperator()
{
	Vector2 v1(10.0f, 20.0f);
	Vector2 v2(10.0f, 20.0f);
	Vector2 v3(20.0f, 10.0f);
	assert((v1 != v2) == false);
	assert((v2 != v1) == false);
	assert((v1 != v3) == true);
	assert((v3 != v1) == true);
	assert((v2 != v3) == true);
	assert((v3 != v2) == true);
}

void Vector2UnitTest::vector2Test_MultiplyOperator()
{
	Vector2 v1(10.0f, 20.0f);
	assert((v1 * 2).x() == 20.0f);
	assert((v1 * 2).y() == 40.0f);
	assert((v1 * 0.25).x() == 2.5f);
	assert((v1 * 0.25).y() == 5.0f);
}

void Vector2UnitTest::vector2Test_DivisionOperator()
{
	Vector2 v1(10.0f, 20.0f);
	assert((v1 / 2).x() == 5.0f);
	assert((v1 / 2).y() == 10.0f);
	assert((v1 / 0.25).x() == 40.0f);
	assert((v1 / 0.25).y() == 80.0f);
}

void Vector2UnitTest::vector2Test_AdditionOperator()
{
	Vector2 v1(10.0f, 20.0f);
	Vector2 v2(5.0f, 7.5f);

	assert((v1 + v2).x() == 15.0f);
	assert((v1 + v2).y() == 27.5f);
	assert((v2 + v1).x() == (v1 + v2).x());
	assert((v2 + v1).y() == (v1 + v2).y());
}

void Vector2UnitTest::vector2Test_SubtractionOperator()
{
	Vector2 v1(10.0f, 20.0f);
	Vector2 v2(5.0f, 7.5f);

	assert((v1 - v2).x() == 5.0f);
	assert((v1 - v2).y() == 12.5f);
	assert((v2 - v1).x() == -5.0f);
	assert((v2 - v1).y() == -12.5f);
}
