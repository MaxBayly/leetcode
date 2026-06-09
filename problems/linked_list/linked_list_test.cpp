#include "linked_list.h++"
#include "remove_node.hpp"
#include "merge_lists.h++"
#include "reorder.h++"
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

TEST(Reorder, One) {
    ReorderList soln;

    auto list = ListNode(
        0, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    soln.reorderList(&list);
}

TEST(Reorder, Two) {
    ReorderList soln;

    auto list =  ListNode(2, new ListNode(4, new ListNode(6, new ListNode(8))));
    soln.reorderList(&list);
}

TEST(RemoveTest, One) {
   auto list = ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
   RemoveNode soln;
   soln.removeNthFromEnd(&list, 2);
}

TEST(RemoveTest, Two) {
   auto list = ListNode(1, new ListNode(2));
   RemoveNode soln;
   soln.removeNthFromEnd(&list, 2);
}