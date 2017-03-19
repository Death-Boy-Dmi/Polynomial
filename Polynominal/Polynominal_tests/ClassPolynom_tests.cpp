#include "ClassPolynom.h"
#include <gtest.h>

TEST(CPolynom, can_create_polynom)
{
	ASSERT_NO_THROW(CPolynom polynom());
}