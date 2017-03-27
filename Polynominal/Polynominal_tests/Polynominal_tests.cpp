#include "ClassPolynom.h"

#include <gtest.h>

TEST(CPolynom, can_use_default_constructor)
{
	ASSERT_NO_THROW(CPolynom pol());
}
TEST(CPolynom, can_use_main_constructor)
{
	string strP = "-3x^2y + 4x^3y^4z^1";
	string strV = "x y z";
	static unsigned int power = 10;

	ASSERT_NO_THROW(CPolynom pol(strP, strV, power));
}
TEST(CPolynom, can_use_Calculate)
{
	string strP = "-3x^2y + 4x^3y^4z^1";
	string strV = "x y z";
	static unsigned int power = 10;
	CPolynom pol(strP, strV, power);

	ASSERT_NO_THROW(pol.Calculate());
}

TEST(CPolynom, can_use_ToString)
{
	string strP = "-3x^2y + 4x^3y^4z^1";
	string strV = "x y z";
	static unsigned int power = 10;
	CPolynom pol(strP, strV, power);

	ASSERT_NO_THROW(pol.ToString());
}

