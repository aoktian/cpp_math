#include "vector3UnitTest.h"

#include <assert.h>
#include <math.h>
#include "../matrix/matrix4.h"
#include "../utility/mathUtility.h"
#include "../quaternion/quaternion.h"


const float Vector3UnitTest::TOLERANCE = 0.00001f;

void Vector3UnitTest::vector3Test_DefaultConstructor()
{
	assert(Vector3().x() == 0.0f);
	assert(Vector3().y() == 0.0f);
	assert(Vector3().z() == 0.0f);
	assert(Vector3(10.0f).x() == 10.0f);
	assert(Vector3(20.0f).y() == 0.0f);
	assert(Vector3(10.0f, 20.0f).x() == 10.0f);
	assert(Vector3(10.0f, 20.0f).y() == 20.0f);

	Vector3 v1 = 5.0f;
	assert(v1.x() == 5.0f);
	assert(v1.y() == 0.0f);
	assert(v1.z() == 0.0f);

	Vector3 v2 = { 5.0f, 20.0f };
	assert(v2.x() == 5.0f);
	assert(v2.y() == 20.0f);
	assert(v2.z() == 0.0f);

	Vector3 v3 = { 5.0f, 20.0f, 50.0f };
	assert(v3.x() == 5.0f);
	assert(v3.y() == 20.0f);
	assert(v3.z() == 50.0f);
}

void Vector3UnitTest::vector3Test_CopyConstructor()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	assert(Vector3(v1).x() == 10.0f);
	assert(Vector3(v1).y() == 20.0f);
	assert(Vector3(v1).z() == 50.0f);
}

void Vector3UnitTest::vector3Test_AssignmentOperator()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	Vector3 v2 = v1;
	assert(v2.x() == 10.0f);
	assert(v2.y() == 20.0f);
	assert(v2.z() == 50.0f);
}

void Vector3UnitTest::vector3Test_TimesEqualsOperator()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	v1 *= 2.0f;
	assert(v1.x() == 20.0f);
	assert(v1.y() == 40.0f);
	assert(v1.z() == 100.0f);

	Vector3 v2(1.0f, 2.0f, 3.0f);
	Vector3 v3(4.0f, 5.0f, 6.0f);
	v2 *= v3;
	assert(v2.x() == 4.0f);
	assert(v2.y() == 10.0f);
	assert(v2.z() == 18.0f);
	assert(v3.x() == 4.0f);
	assert(v3.y() == 5.0f);
	assert(v3.z() == 6.0f);

	Matrix4 translation = Matrix4::translation(10.0f, 5.0f, 0.0f);
	Vector3 translated(0.0f, 0.0f, 0.0f);
	translated *= translation;
	assert(translated.x() == 10.0f);
	assert(translated.y() == 5.0f);
	assert(translated.z() == 0.0f);

	Matrix4 scale = Matrix4::scale(1.0f, 1.5f, 2.0f);
	Vector3 scaled(10.0f, 10.0f, 10.0f);
	scaled *= scale;
	assert(scaled.x() == 10.0f);
	assert(scaled.y() == 15.0f);
	assert(scaled.z() == 20.0f);

	Matrix4 rotation = Matrix4::pitch(MathUtil::radians(45.0f));
	Vector3 rotated(10.0f, 10.0f, 0.0f);
	rotated *= rotation;
	assert(fabs(rotated.x() - 10.0f) < TOLERANCE);
	assert(fabs(rotated.y() - 7.07106f) < TOLERANCE);
	assert(fabs(rotated.z() - 7.07106f) < TOLERANCE);

	Quaternion quat(MathUtil::radians(45.0f), Vector3(1.0f, 0.0f, 0.0f));
	Vector3 qRotated(10.0f, 10.0f, 0.0f);
	qRotated *= quat.rotationMatrix();
	assert(fabs(qRotated.x() - 10.0f) < TOLERANCE);
	assert(fabs(qRotated.y() - 7.07106f) < TOLERANCE);
	assert(fabs(qRotated.z() - 7.07106f) < TOLERANCE);
}

void Vector3UnitTest::vector3Test_DivideEqualsOperator()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	v1 /= 2.0f;
	assert(v1.x() == 5.0f);
	assert(v1.y() == 10.0f);
	assert(v1.z() == 25.0f);
}

void Vector3UnitTest::vector3Test_PlusEqualsOperator()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	Vector3 v2(5.0f, 10.0f, 25.0f);
	v2 += v1;
	assert(v1.x() == 10.0f);
	assert(v1.y() == 20.0f);
	assert(v1.z() == 50.0f);
	assert(v2.x() == 15.0f);
	assert(v2.y() == 30.0f);
	assert(v2.z() == 75.0f);
}

void Vector3UnitTest::vector3Test_MinusEqualsOperator()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	Vector3 v2(5.0f, 10.0f, 25.0f);
	v2 -= v1;
	assert(v1.x() == 10.0f);
	assert(v1.y() == 20.0f);
	assert(v1.z() == 50.0f);
	assert(v2.x() == -5.0f);
	assert(v2.y() == -10.0f);
	assert(v2.z() == -25.0f);
}

void Vector3UnitTest::vector3Test_SetX()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	v1.setX(30.0f);
	assert(v1.x() == 30.0f);
	assert(v1.y() == 20.0f);
	assert(v1.z() == 50.0f);
}

void Vector3UnitTest::vector3Test_SetY()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	v1.setY(30.0f);
	assert(v1.x() == 10.0f);
	assert(v1.y() == 30.0f);
	assert(v1.z() == 50.0f);
}

void Vector3UnitTest::vector3Test_SetZ()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	v1.setZ(30.0f);
	assert(v1.x() == 10.0f);
	assert(v1.y() == 20.0f);
	assert(v1.z() == 30.0f);
}

void Vector3UnitTest::vector3Test_SetXYZ()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	v1.set(5.0f, 6.0f, 7.0f);
	assert(v1.x() == 5.0f);
	assert(v1.y() == 6.0f);
	assert(v1.z() == 7.0f);
}

void Vector3UnitTest::vector3Test_SetSingleValue()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	v1.set(5.0f);
	assert(v1.x() == 5.0f);
	assert(v1.y() == 5.0f);
	assert(v1.z() == 5.0f);
}

void Vector3UnitTest::vector3Test_LengthSq()
{
	assert(Vector3().lengthSq() == 0.0f);
	assert(Vector3(10.0f, 10.0f, 10.0f).lengthSq() == 300.0f);
	assert(Vector3(0.5f, 0.5f, 0.5f).lengthSq() == 0.75f);
}

void Vector3UnitTest::vector3Test_Length()
{
	assert(Vector3().length() == 0.0f);
	assert(fabs(Vector3(10.0f, 20.0f, 40.0f).length() - sqrt(10.0f * 10.0f + 20.0f * 20.0f + 40.0f * 40.0f)) < TOLERANCE);
	assert(fabs(Vector3(0.5f, 0.75f, 0.25f).length() - sqrt(0.5f * 0.5f + 0.75f * 0.75f + 0.25f * 0.25f)) < TOLERANCE);
}

void Vector3UnitTest::vector3Test_Normalise()
{
	Vector3 v1(10.0f, 20.0f, 40.0f);
	auto len = sqrt(10.0f * 10.0f + 20.0f * 20.0f + 40.0f * 40.0f);
	v1.normalise();
	assert(fabs(v1.x() - (10.0f / len)) < TOLERANCE);
	assert(fabs(v1.y() - (20.0f / len)) < TOLERANCE);
	assert(fabs(v1.z() - (40.0f / len)) < TOLERANCE);
	assert(fabs(v1.length() -1.0f) < TOLERANCE);

	v1.set(0.0f, 1.0f, 0.0f);
	v1.normalise();
	assert(fabs(v1.x()) < TOLERANCE);
	assert(fabs(v1.y() - 1.0f) < TOLERANCE);
	assert(fabs(v1.z()) < TOLERANCE);
	assert(fabs(v1.length() - 1.0f) < TOLERANCE);
}

void Vector3UnitTest::vector3Test_Normalised()
{
	Vector3 v1(10.0f, 20.0f, 40.0f);
	auto len = sqrt(10.0f * 10.0f + 20.0f * 20.0f + 40.0f * 40.0f);
	assert(fabs(v1.normalised().x() - (10.0f / len)) < TOLERANCE);
	assert(fabs(v1.normalised().y() - (20.0f / len)) < TOLERANCE);
	assert(fabs(v1.normalised().z() - (40.0f / len)) < TOLERANCE);
	assert(fabs(v1.normalised().length() - 1.0f) < TOLERANCE);

	v1.set(0.0f, 1.0f, 0.0f);
	assert(fabs(v1.normalised().x()) < TOLERANCE);
	assert(fabs(v1.normalised().y() - 1.0f) < TOLERANCE);
	assert(fabs(v1.normalised().z()) < TOLERANCE);
	assert(fabs(v1.normalised().length() - 1.0f) < TOLERANCE);
}

void Vector3UnitTest::vector3Test_DotProduct()
{
	Vector3 v1(10.0f, 0.0f, 0.0f);
	Vector3 v2(0.0f, 10.0f, 0.0f);
	assert(v1.dotProduct(v2) == 0.0f);
	assert(Vector3::dotProduct(v1, v2) == 0.0f);
	assert(v2.dotProduct(v1) == 0.0f);
	assert(Vector3::dotProduct(v2, v1) == 0.0f);
	
	v1.set(100.0f, 50.0f, 25.0f);
	v2.set(25.0f, 50.0f, 100.0f);
	assert(fabs(v1.dotProduct(v2) - 0.57142f) < TOLERANCE);
	assert(fabs(Vector3::dotProduct(v1, v2) - 0.57142f) < TOLERANCE);
	assert(fabs(v2.dotProduct(v1) - 0.57142f) < TOLERANCE);
	assert(fabs(Vector3::dotProduct(v2, v1) - 0.57142f) < TOLERANCE);
}

void Vector3UnitTest::vector3Test_CrossProduct()
{
	Vector3 v1(10.0f, 0.0f, 0.0f);
	Vector3 v2(0.0f, 10.0f, 0.0f);
	assert(v1.crossProduct(v2).x() == 0.0f);
	assert(v1.crossProduct(v2).y() == 0.0f);
	assert(v1.crossProduct(v2).z() == 1.0f);
	assert(v2.crossProduct(v1).x() == 0.0f);
	assert(v2.crossProduct(v1).y() == 0.0f);
	assert(v2.crossProduct(v1).z() == -1.0f);
	assert(Vector3::crossProduct(v1, v2).x() == 0.0f);
	assert(Vector3::crossProduct(v1, v2).y() == 0.0f);
	assert(Vector3::crossProduct(v1, v2).z() == 1.0f);
	assert(Vector3::crossProduct(v2, v1).x() == 0.0f);
	assert(Vector3::crossProduct(v2, v1).y() == 0.0f);
	assert(Vector3::crossProduct(v2, v1).z() == -1.0f);
}

void Vector3UnitTest::vector3Test_Angle()
{
	Vector3 v1(10.0f, 0.0f, 0.0f);
	Vector3 v2(0.0f, 10.0f, 0.0f);
	assert(fabs(MathUtil::degrees(v1.angle(v2)) - 90.0f) < TOLERANCE);
	assert(fabs(MathUtil::degrees(v1.angle(v2)) - 90.0f) < TOLERANCE);
	assert(fabs(MathUtil::degrees(v1.angle(v2)) - 90.0f) < TOLERANCE);
	assert(fabs(MathUtil::degrees(v1.angle(v2)) - 90.0f) < TOLERANCE);
}


void Vector3UnitTest::vector3Test_EqualityOperator()
{
	Vector3 v1(10.0f, 20.0f);
	Vector3 v2(10.0f, 20.0f);
	Vector3 v3(20.0f, 10.0f);
	assert((v1 == v2) == true);
	assert((v2 == v1) == true);
	assert((v1 == v3) == false);
	assert((v3 == v1) == false);
	assert((v2 == v3) == false);
	assert((v3 == v2) == false);
}

void Vector3UnitTest::vector3Test_InequalityOperator()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	Vector3 v2(10.0f, 20.0f, 50.0f);
	Vector3 v3(20.0f, 10.0f, 50.0f);
	Vector3 v4(20.0f, 10.0f, 51.0f);
	assert((v1 != v2) == false);
	assert((v2 != v1) == false);
	assert((v1 != v3) == true);
	assert((v3 != v1) == true);
	assert((v2 != v3) == true);
	assert((v3 != v4) == true);
}

void Vector3UnitTest::vector3Test_MultiplyOperator()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	assert((v1 * 2).x() == 20.0f);
	assert((v1 * 2).y() == 40.0f);
	assert((v1 * 2).z() == 100.0f);
	assert((v1 * 0.25).x() == 2.5f);
	assert((v1 * 0.25).y() == 5.0f);
	assert((v1 * 0.25).z() == 12.5f);

	Vector3 v2(1.0f, 2.0f, 3.0f);
	Vector3 v3(4.0f, 5.0f, 6.0f);
	assert((v2 * v3).x() == 4.0f);
	assert((v2 * v3).y() == 10.0f);
	assert((v2 * v3).z() == 18.0f);
	
	Matrix4 translation = Matrix4::translation(10.0f, 5.0f, 0.0f);
	Vector3 translated(0.0f, 0.0f, 0.0f);
	Vector3 tRes1 = translated * translation;
	Vector3 tRes2 = translation * translated;
	assert(tRes1.x() == 10.0f);
	assert(tRes1.y() == 5.0f);
	assert(tRes1.z() == 0.0f);
	assert(tRes2.x() == 10.0f);
	assert(tRes2.y() == 5.0f);
	assert(tRes2.z() == 0.0f);

	Matrix4 scale = Matrix4::scale(1.0f, 1.5f, 2.0f);
	Vector3 scaled(10.0f, 10.0f, 10.0f);
	Vector3 sRes1 = scaled * scale;
	Vector3 sRes2 = scaled * scale;
	assert(sRes1.x() == 10.0f);
	assert(sRes1.y() == 15.0f);
	assert(sRes1.z() == 20.0f);
	assert(sRes2.x() == 10.0f);
	assert(sRes2.y() == 15.0f);
	assert(sRes2.z() == 20.0f);

	Matrix4 yaw = Matrix4::yaw(MathUtil::radians(25.0f));
	Matrix4 pitch = Matrix4::pitch(MathUtil::radians(80.0f));
	Matrix4 roll = Matrix4::roll(MathUtil::radians(10.0f));
	Vector3 rotate(10.0f, 10.0f, 10.0f);
	Vector3 yRes = rotate * yaw;
	assert(fabs(yRes.x() - 13.28926f) < TOLERANCE);
	assert(fabs(yRes.y() - 10.0f) < TOLERANCE);
	assert(fabs(yRes.z() - 4.83689f) < TOLERANCE);
	Vector3 pRes = rotate * pitch;
	assert(fabs(pRes.x() - 10.0f) < TOLERANCE);
	assert(fabs(pRes.y() - -8.11159f) < TOLERANCE);
	assert(fabs(pRes.z() - 11.58456f) < TOLERANCE);
	Vector3 rRes = roll * rotate;
	assert(fabs(rRes.x() - 8.11159f) < TOLERANCE);
	assert(fabs(rRes.y() - 11.58455f) < TOLERANCE);
	assert(fabs(rRes.z() - 10.0f) < TOLERANCE);
	
	Quaternion quat(MathUtil::radians(25.0f), 0.0f, 1.0f, 0.0f);
	Vector3 qRotate(10.0f, 10.0f, 10.0f);
	Vector3 qRes = qRotate * quat.rotationMatrix();
	assert(fabs(qRes.x() - 13.28926f) < TOLERANCE);
	assert(fabs(qRes.y() - 10.0f) < TOLERANCE);
	assert(fabs(qRes.z() - 4.836895f) < TOLERANCE);
}

void Vector3UnitTest::vector3Test_DivisionOperator()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	assert((v1 / 2).x() == 5.0f);
	assert((v1 / 2).y() == 10.0f);
	assert((v1 / 2).z() == 25.0f);
	assert((v1 / 0.25).x() == 40.0f);
	assert((v1 / 0.25).y() == 80.0f);
	assert((v1 / 0.25).z() == 200.0f);
}

void Vector3UnitTest::vector3Test_AdditionOperator()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	Vector3 v2(5.0f, 7.5f, 10.0f);

	assert((v1 + v2).x() == 15.0f);
	assert((v1 + v2).y() == 27.5f);
	assert((v1 + v2).z() == 60.0f);
	assert((v2 + v1).x() == (v1 + v2).x());
	assert((v2 + v1).y() == (v1 + v2).y());
	assert((v2 + v1).z() == (v1 + v2).z());
}

void Vector3UnitTest::vector3Test_SubtractionOperator()
{
	Vector3 v1(10.0f, 20.0f, 50.0f);
	Vector3 v2(5.0f, 7.5f, 10.0f);

	assert((v1 - v2).x() == 5.0f);
	assert((v1 - v2).y() == 12.5f);
	assert((v1 - v2).z() == 40.0f);
	assert((v2 - v1).x() == -5.0f);
	assert((v2 - v1).y() == -12.5f);
	assert((v2 - v1).z() == -40.0f);
}
