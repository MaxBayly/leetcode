#ifndef LEETCODE_KTH_LARGEST_H
#define LEETCODE_KTH_LARGEST_H
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            queue.push(num);
            if (queue.size() > k) {
                queue.pop();
            }
        }
    }

    int add(int val) {
        queue.push(val);
        if (queue.size() > k) {
            queue.pop();
        }

        return queue.top();
    }
private:
    int k;
    std::priority_queue<int, vector<int>, greater<>> queue;
};

#endif //LEETCODE_KTH_LARGEST_H
