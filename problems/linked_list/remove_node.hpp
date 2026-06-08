#include "linked_list.h++"

using namespace std;

class RemoveNode
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == nullptr) {
            return nullptr;
        }
        int count = 0;
        int nth = 0;
        ListNode *preskip = head;
        ListNode *cur = head;
        while (cur)
        {
            count++;
            if (nth <= n)
            {
                nth++;
                
            } else {
                preskip = preskip->next;
            }

            cur = cur->next;
        }

        if (count == n) {
            head = head->next;
        } else {
            preskip->next = preskip->next->next;
        }
        
        
        
        return head;
    }
};