#ifndef LEETCODE_CYCLE_DETECTION_H
#define LEETCODE_CYCLE_DETECTION_H

#include "linked_list.h++"
#include <set>

using namespace std;

class CycleDetection {
public:
    bool hasCycleDumb(ListNode* head) {
        if (head == nullptr) {
            return false;
        }
        // dumb solution - we know there is only ever 1000 or fewer elements
        for (int i = 0;  i < 1000; i++) {
            if (head->next == nullptr) {
                return false;
            }
            head = head->next;
        }

        return true;
    }

    bool hasCycleHash(ListNode* head) {
        set<ListNode*> visited;
        while (head) {
            if (!visited.insert(head).second) {
                return true;
            }
            head = head->next;
        }

        return false;
    }

    bool hasCycleFastSlow(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
#endif //LEETCODE_CYCLE_DETECTION_H
