#ifndef LEETCODE_MEDIAN_H
#define LEETCODE_MEDIAN_H
#include <queue>


using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        this->count = 0;
    }

    void addNum(int num) {
        if (count == 0) {
            right.push(num);
        } else if (right.size() > left.size()) {
            if (num < right.top()) {
                left.push(num);
            } else {
                int moved = right.top();
                right.pop();
                left.push(moved);
                right.push(num);
            }
        } else {
            if (num < left.top()) {
                int moved = left.top();
                left.pop();
                right.push(moved);
                left.push(num);
            } else {
                right.push(num);
            }
        }
        count++;
    }

    double findMedian() {
        if (count % 2 || count == 1) {
            return right.top();
        }
        return (static_cast<double>(left.top()) + right.top())/2;
    }
private:
    priority_queue<int, vector<int>, less<>> left;
    priority_queue<int, vector<int>, greater<>> right;
    int count;
};
#endif //LEETCODE_MEDIAN_H
