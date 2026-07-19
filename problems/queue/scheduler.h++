#ifndef LEETCODE_SCHEDULER_H
#define LEETCODE_SCHEDULER_H
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class Scheduler {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector freqs(static_cast<int>('Z') + 1, 0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> heap;
        queue<pair<int, pair<int, int>>> waiting;

        for (char task : tasks) {
            freqs[task]++;
        }

        for (int i = 0; i <= static_cast<int>('Z'); i++) {
            if (freqs[i] > 0) {
                heap.emplace(freqs[i], i);
            }
        }

        int time = 0;

        while (!heap.empty() || !waiting.empty()) {
            time++;
            if (heap.empty()) {
                time = waiting.front().first;
            } else {
                pair<int, int> task = heap.top();
                heap.pop();
                task.first--;
                if (task.first > 0) {
                    waiting.emplace(time + n, task);
                }
            }

            if (!waiting.empty() && time >= waiting.front().first) {
                pair<int, int> task = waiting.front().second;
                heap.emplace(task);
                waiting.pop();
            }
        }

        return time;
    }
};

#endif //LEETCODE_SCHEDULER_H
