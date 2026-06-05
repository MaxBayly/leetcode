#ifndef LEETCODE_REVERSE_LINKED_LIST_H
#define LEETCODE_REVERSE_LINKED_LIST_H
#include "linked_list.h++"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while (cur != nullptr) {
            ListNode* b = cur->next;
            cur->next = prev;
            prev = cur;
            cur = b;
        }

        return prev;
    }
};

#endif //LEETCODE_REVERSE_LINKED_LIST_H
