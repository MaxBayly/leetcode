#ifndef LEETCODE_CAR_FLEET_H
#define LEETCODE_CAR_FLEET_H
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class car_fleet {
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed) {
        vector<pair<int, int> > cars(position.size());
        for (int i = 0; i < position.size(); i++) {
            cars[i] = {position[i], speed[i]};
        }

        ranges::sort(cars);
        stack<float> rem;
        for (int i = cars.size() - 1; i >= 0; i--) {
            float remains = ((float) target - (float) cars[i].first) / (float) cars[i].second;
            if (rem.empty()) {
                rem.push(remains);
            } else if (remains > rem.top()) {
                rem.push(remains);
            }
        }

        return rem.size();
    }
};
#endif //LEETCODE_CAR_FLEET_H
