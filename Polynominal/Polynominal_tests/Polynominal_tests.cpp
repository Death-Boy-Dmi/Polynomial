#include "ClassPolynom.h"

#include <gtest.h>

TEST(CPolynom, can_use_construct)
{
	ASSERT_NO_THROW(CPolynom pol());
}