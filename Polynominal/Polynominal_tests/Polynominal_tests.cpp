#include "ClassPolynom.h"

#include <gtest.h>

unsigned int CPolynom::Power = 10;

TEST(CPolynom, can_use_construct)
{
	ASSERT_NO_THROW(CPolynom pol());
}

TEST(CPolynom, can_use_main_construct)
{
	ASSERT_NO_THROW(CPolynom pol("-3x^2y^3+3x^3y^2", "x y"));
}