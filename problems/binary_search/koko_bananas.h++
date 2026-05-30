#ifndef LEETCODE_KOKO_BANANAS_H
#define LEETCODE_KOKO_BANANAS_H
#include <algorithm>
#include <vector>
using namespace std;
class KokoBananas {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ranges::sort(piles);
        int maximum = piles.back();
        int l = 1;
        int r = maximum;
        int res = maximum;
        while (l <= r) {
            int mid = (r + l) / 2;
            int taken = hoursTaken(piles, mid);
            if (taken > h) {
                l = mid + 1;
            } else if (mid > res) {
                return res;
            } else {
                res = mid;
                r = mid - 1;
            }
        }

        return res;
    }

    int hoursTaken(vector<int> piles, int rate) {
        int res = 0;
        for (int pile : piles) {
            res += (pile + rate - 1) / rate;
        }
        return res;
    }
};

#endif //LEETCODE_KOKO_BANANAS_H
