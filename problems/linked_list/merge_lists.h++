#ifndef LEETCODE_MERGE_LISTS_H
#define LEETCODE_MERGE_LISTS_H
#include "linked_list.h++"
struct ListNode;

class MergeLists {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode newHead = ListNode();
        ListNode* newTail = &newHead;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                newTail->next = list1;
                list1 = list1->next;
            } else {
                newTail->next = list2;
                list2 = list2->next;
            }

            newTail = newTail->next;

        }

        if (list1 != nullptr) {
            newTail->next = list1;
        } else {
            newTail->next = list2;
        }

        return newHead.next;
    }
};
#endif //LEETCODE_MERGE_LISTS_H
