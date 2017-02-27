#include "TList.h"
#include <gtest.h>

TEST(TList, can_create_List)
{
	ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_use_IsEmpty)
{
	TList<int> list;

	ASSERT_NO_THROW(list.IsEmpty());
}

TEST(TList, can_use_IsFull)
{
	TList<int> list;

	ASSERT_NO_THROW(list.IsFull());
}

TEST(TList, can_use_InsFirst)
{
	TList<int> list;

	ASSERT_NO_THROW(list.InsFirst(5));
}

TEST(TList, can_use_InsLast)
{
	TList<int> list;
	list.InsFirst(5);
	ASSERT_NO_THROW(list.InsLast(5));
}

TEST(TList, can_use_Insert)
{
	TList<int> list;
	list.InsFirst(5);
	list.InsLast(5);
	ASSERT_NO_THROW(list.Insert(5, 1));
}

TEST(TList, can_use_DelFirst)
{
	TList<int> list;
	list.InsFirst(5);

	ASSERT_NO_THROW(list.DelFirst());
}

TEST(TList, can_use_DelLast)
{
	TList<int> list;
	list.InsFirst(5);

	ASSERT_NO_THROW(list.DelLast());
}

TEST(TList, can_use_Delete)
{
	TList<int> list;
	list.InsFirst(5);
	list.InsLast(5);

	ASSERT_NO_THROW(list.Delete(1));
}

TEST(TList, can_use_GetCount)
{
	TList<int> list;

	ASSERT_NO_THROW(list.GetCount());
}

TEST(TList, can_use_ReVal)
{
	TList<int> list;
	list.InsFirst(5);

	ASSERT_NO_THROW(list.ReVal(3, 0));
}

TEST(TList, can_use_GetVal)
{
	TList<int> list;
	list.InsFirst(5);

	ASSERT_NO_THROW(list.GetVal(0));
}

TEST(TList, throw_when_use_InsFirst_when_list_is_full)
{
	TList<int> list;
	for (size_t i = 0; i < MaxL; i++)
		list.InsFirst(0);

	ASSERT_ANY_THROW(list.InsFirst(5));
}

TEST(TList, throw_when_use_InsLast_when_list_is_full)
{
	TList<int> list;
	for (size_t i = 0; i < MaxL; i++)
		list.InsFirst(0);

	ASSERT_ANY_THROW(list.InsLast(5));
}

TEST(TList, throw_when_use_Insert_when_list_is_full)
{
	TList<int> list;
	for (size_t i = 0; i < MaxL; i++)
		list.InsFirst(0);

	ASSERT_ANY_THROW(list.Insert(5, 5));
}

TEST(TList, throw_when_use_Insert_when_pos_bigger_count)
{
	TList<int> list;

	ASSERT_ANY_THROW(list.Insert(0, 5));
}

TEST(TList, throw_when_use_Delete_when_pos_bigger_count)
{
	TList<int> list;

	ASSERT_ANY_THROW(list.Delete(5));
}

TEST(TList, throw_when_use_Delete_when_list_is_empty)
{
	TList<int> list;

	ASSERT_ANY_THROW(list.Delete(5));
}

TEST(TList, throw_when_use_DelFirst_when_list_is_empty)
{
	TList<int> list;

	ASSERT_ANY_THROW(list.DelFirst());
}

TEST(CList, throw_when_use_DelLast_when_list_is_empty)
{
	TList<int> list;

	ASSERT_ANY_THROW(list.DelLast());
}

TEST(TList, throw_when_use_GetVal_when_pos_bigger_count)
{
	TList<int> list;

	ASSERT_ANY_THROW(list.GetVal(5));
}

TEST(TList, throw_when_use_ReVal_when_pos_bigger_count)
{
	TList<int> list;

	ASSERT_ANY_THROW(list.ReVal(5, 5));
}

TEST(TList, can_right_use_IsEmpty)
{
	TList<int> list;

	ASSERT_TRUE(list.IsEmpty());
}

TEST(TList, can_right_use_IsFull)
{
	TList<int> list;
	for (size_t i = 0; i < MaxL; i++)
		list.InsFirst(0);
	ASSERT_TRUE(list.IsFull());
}

TEST(TList, can_right_use_InsFirst_and_GetVal)
{
	TList<int> list;
	list.InsFirst(5);

	ASSERT_TRUE(list.GetVal(0) == 5);
}

TEST(TList, can_right_use_InsLast)
{
	TList<int> list;
	list.InsLast(5);
	list.InsLast(3);
	ASSERT_TRUE(list.GetVal(0) == 5);
	ASSERT_TRUE(list.GetVal(1) == 3);
}

TEST(TList, can_right_use_Insert)
{
	TList<int> list;
	list.InsLast(5);
	list.InsLast(3);
	list.Insert(13, 1);
	ASSERT_TRUE(list.GetVal(1) == 13);
}

TEST(TList, can_right_use_DelFirst)
{
	TList<int> list;
	list.InsFirst(5);
	list.InsFirst(3);
	list.InsFirst(13);

	list.DelFirst();
	ASSERT_TRUE(list.GetVal(0) == 3);
}

TEST(TList, can_right_use_DelLast)
{
	TList<int> list;
	list.InsFirst(5);
	list.InsFirst(3);
	list.InsFirst(13);

	list.DelLast();
	ASSERT_TRUE(list.GetVal(1) == 3);
}

TEST(TList, can_right_use_Delete)
{
	TList<int> list;
	list.InsFirst(5);
	list.InsLast(3);
	list.InsLast(13);

	list.Delete(1);
	ASSERT_TRUE(list.GetVal(1) == 13);
}
TEST(TList, can_right_use_GetCount)
{
	TList<int> list;
	list.InsFirst(5);
	list.InsLast(3);
	list.InsLast(13);

	ASSERT_TRUE(list.GetCount() == 3);
}

TEST(TList, can_right_use_ReVal)
{
	TList<int> list;
	list.InsFirst(5);
	list.ReVal(3, 0);

	ASSERT_TRUE(list.GetVal(0) == 3);
}