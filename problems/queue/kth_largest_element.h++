#ifndef LEETCODE_KTH_LARGEST_ELEMENT_H
#define LEETCODE_KTH_LARGEST_ELEMENT_H
#include <queue>
#include <vector>

using namespace std;

class KthLargestElement {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> queue;
        for (int num : nums) {
            queue.push(num);
            if (queue.size() > k) {
                queue.pop();
                notreal = 5;
            }
        }

        return queue.top();
    }
};

#endif //LEETCODE_KTH_LARGEST_ELEMENT_H
