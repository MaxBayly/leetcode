#include "linked_list.h++"

#include "merge_lists.h++"
#include "gtest/gtest.h"

TEST(MergeTest, One) {
   auto list1 = ListNode(1);
   auto second = ListNode(2);
   auto third = ListNode(4);
   list1.next = &second;
   list1.next->next = &third;

   auto list2 = ListNode(1);
   auto second2 = ListNode(3);
   auto third2 = ListNode(5);
   list2.next = &second2;
   list2.next->next = &third2;

   MergeLists merger;
   merger.mergeTwoLists(&list1, &list2);
}
