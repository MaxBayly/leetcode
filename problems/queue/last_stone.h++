#ifndef LEETCODE_LAST_STONE_H
#define LEETCODE_LAST_STONE_H
#include <queue>
#include <vector>

using namespace std;

class LastStone {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<>> stone_queue;

        for (int stone : stones) {
            stone_queue.push(stone);
        }

        while (stone_queue.size() > 1) {
            int largest = stone_queue.top();
            stone_queue.pop();
            int second = stone_queue.top();
            stone_queue.pop();

            if (largest == second) {
                continue;
            }
            stone_queue.push(largest - second);
        }

        return stone_queue.empty() ? 0 : stone_queue.top();
    }
};


#endif //LEETCODE_LAST_STONE_H
