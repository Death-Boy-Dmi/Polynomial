#include "ClassPolynom.h"

#include <gtest.h>
TEST(CPolynominal, can_use_constructor)
{
	ASSERT_NO_THROW(CPolynom pol("-3x^2+x^3", "x", 10));
}