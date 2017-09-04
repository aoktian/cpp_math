#include "vector/vector2UnitTest.h"

int main()
{
	Vector2UnitTest v2Test;
	v2Test.Vector2Test_DefaultConstructor();
	v2Test.Vector2Test_CopyConstructor();
	v2Test.Vector2Test_SingleValueConstructor();
	v2Test.Vector2Test_TimesEqualsOperator();
	v2Test.Vector2Test_DivideEqualsOperator();
	v2Test.Vector2Test_PlusEqualsOperator();
	v2Test.Vector2Test_MinusEqualsOperator();
	v2Test.Vector2Test_SetX();
	v2Test.Vector2Test_SetY();
	v2Test.Vector2Test_SetXY();
	v2Test.Vector2Test_SetSingleValue();
	v2Test.Vector2Test_LengthSq();
	v2Test.Vector2Test_Length();
	v2Test.Vector2Test_Normalise();
	v2Test.Vector2Test_Normalised();
	v2Test.Vector2Test_EqualityOperator();
	v2Test.Vector2Test_InequalityOperator();
	v2Test.Vector2Test_MultiplyOperator();
	v2Test.Vector2Test_DivisionOperator();
	v2Test.Vector2Test_AdditionOperator();
	v2Test.Vector2Test_SubtractionOperator();

	return 0;
}