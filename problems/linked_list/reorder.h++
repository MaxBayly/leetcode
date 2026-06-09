#ifndef LEETCODE_REORDER_H
#define LEETCODE_REORDER_H
#include "linked_list.h++"

class ReorderList {
public:
    void reorderList(ListNode* head) {
        ListNode* oHead = head;
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        head = oHead;
        for (int i = 0; i < (length + 1) / 2; i++) {
            head = head->next;
        }
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        ListNode newHead = ListNode();
        ListNode* newTail = &newHead;

        while (oHead != nullptr && prev != nullptr) {
            newTail->next = oHead;
            oHead = oHead->next;
            newTail->next->next = prev;
            prev = prev->next;

            newTail = newTail->next->next;
        }

        if (oHead != nullptr) {
            newTail->next = oHead;
            newTail->next->next = nullptr;
        }

        head = newHead.next;
    }
};
#endif //LEETCODE_REORDER_H
