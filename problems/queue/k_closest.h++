#ifndef LEETCODE_K_CLOSEST_H
#define LEETCODE_K_CLOSEST_H
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

class KClosest {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float, vector<int>>, vector<pair<float, vector<int>>>, less<>> distances;

        for (auto point : points) {
            float distance = sqrt(pow(point[0], 2) + pow(point[1], 2));
            distances.push({distance, point});
            if (distances.size() > k) {
                distances.pop();
            }
        }

        vector<vector<int>> closest;

        while (!distances.empty()) {
            closest.push_back(distances.top().second);
            distances.pop();
        }

        return closest;
    }

};

#endif //LEETCODE_K_CLOSEST_H
