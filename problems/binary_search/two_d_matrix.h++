

#include <algorithm>
#include <vector>

#include "binary_search.h++"
using namespace std;
class SearchMatrix {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int upper = 0;
        int lower = matrix.size() - 1;
        while (upper <= lower) {
            int y = (upper + lower)/2;
            vector row = matrix[y];
            if (row[row.size() - 1] < target) {
                upper = y + 1;
            } else if (row[0] > target) {
                lower = y - 1;
            } else {
                return search(row, target);
            }
        }

        return false;
    }

    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int idx = (right + left)/2;
            int current = nums[idx];
            if (current == target) {
                return true;
            }
            if (current < target) {
                left = idx + 1;
            } else {
                right = idx - 1;
            }
        }

        return false;
    }
};
