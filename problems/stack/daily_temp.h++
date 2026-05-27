

#ifndef LEETCODE_DAILY_TEMP_H
#define LEETCODE_DAILY_TEMP_H
#include <vector>
#include <stack>

using namespace std;

class daily_temp {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> idxs;
        vector<int> res = vector(temperatures.size(), 0);
        for (int idx = 0; idx < temperatures.size(); idx++) {
            while (!idxs.empty() && temperatures[idx] > temperatures[idxs.top()]) {
                res[idxs.top()] = idx - idxs.top();
                idxs.pop();
            }
            idxs.push(idx);
        }

        return res;
    }

    vector<int> dailyTempDynamic(vector<int>& temperatures) {
        vector<int> res = vector(temperatures.size(), 0);
        int count = temperatures.size();
        for (int i = count - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < count && temperatures[j] <= temperatures[i]) {
                if (res[j] == 0) {
                    j = count;
                    break;
                }
                j += res[j];
            }

            if (j < count) {
                res[i] = j - i;
            }
        }
        return res;
    }
};
#endif //LEETCODE_DAILY_TEMP_H
