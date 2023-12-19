#include <queue>
#include <functional>

class MedianFinder {
    std::priority_queue<int> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        // Rebalance the heaps
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2.0;
        } else {
            return max_heap.top();
        }
    }
};
#include <iostream>

int main() {
    MedianFinder mf; // Create an instance of MedianFinder

    // Adding numbers
    mf.addNum(5);
    mf.addNum(2);
    mf.addNum(8);

    // Find and print the median
    std::cout << "Median: " << mf.findMedian() << std::endl;

    return 0;
}