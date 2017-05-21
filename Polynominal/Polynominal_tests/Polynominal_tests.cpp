#include "ClassPolynom.h"

#include <gtest.h>

unsigned int CPolynom::Power = 10;
double* CPolynom::arrArg;

TEST(CPolynom, can_use_construct)
{
	ASSERT_NO_THROW(CPolynom pol());
}

TEST(CPolynom, can_use_main_construct)
{
	ASSERT_NO_THROW(CPolynom pol("-3x^2y^3+3x^3y^2"));
}

TEST(CPolynom, can_use_Calculate)
{
	CPolynom pol("-3x^2y^3+3x^3y^2");
	double arr[2] = { 3,10 };
	pol.SetVar(arr);

	ASSERT_NO_THROW(pol.Calculate());
}

TEST(CPolynom, can_correct_use_Calculate)
{
	CPolynom pol("-3x^2y^3+3x^3y^2");
	double arr[2] = { 3,10 };
	pol.SetVar(arr);
	double res = pol.Calculate();

	EXPECT_EQ(res, -18900);
}

TEST(CPolynom, can_use_ToString)
{
	CPolynom pol("-3x^2y^3+3x^3y^2");

	ASSERT_NO_THROW(pol.ToString());
}

TEST(CPolynom, can_correct_use_ToString)
{
	CPolynom pol("-3x^2y^3+3x^3y^2");
	string str = pol.ToString();

	EXPECT_EQ(str, "-3.000000*x^2y^3+3.000000*x^3y^2");
}

TEST(CPolynom, can_use_Plus)
{
	CPolynom pol1("-3x^2y^3+3x^3y^2");
	CPolynom pol2("-3x^2y^3+3x^3y^2");

	ASSERT_NO_THROW(pol1 + pol2);
}

TEST(CPolynom, can_correct_use_Plus)
{
	CPolynom pol1("-3x^2y^3+3x^3y^2");
	CPolynom pol2("-3x^2y^3+3x^3y^2");
	CPolynom pol = pol1 + pol2;

	EXPECT_EQ(pol.ToString(), "-6.000000*x^2y^3+6.000000*x^3y^2");
}

TEST(CPolynom, can_use_Mult)
{
	CPolynom pol1("-3x^2y^3+3x^3y^2");

	ASSERT_NO_THROW(pol1*3);
}

TEST(CPolynom, can_correct_use_Mult)
{
	CPolynom pol1("-3x^2y^3+3x^3y^2");
	CPolynom pol = pol1*2;

	EXPECT_EQ(pol.ToString(), "-6.000000*x^2y^3+6.000000*x^3y^2");
}