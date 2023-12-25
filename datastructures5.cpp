#include <iostream>
#include <vector>
#include <algorithm>

int calculateMaxProfit(std::vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }

    int maxProfitBefore = 0;
    int maxProfitAfter = 0;

    int minPrice = prices[0];
    for (int i = 1; i < n; i++) {
        minPrice = std::min(minPrice, prices[i]);
        maxProfitBefore = std::max(maxProfitBefore, prices[i] - minPrice);
    }

    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxPrice = std::max(maxPrice, prices[i]);
        maxProfitAfter = std::max(maxProfitAfter, maxPrice - prices[i]);
    }

    int maxProfit = std::max(maxProfitBefore, maxProfitAfter);

    return maxProfit;
}

int main() {
    // Input array of stock prices
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};

    int maxProfitValue = calculateMaxProfit(prices);

    std::cout << "Max Profit: " << maxProfitValue << std::endl;

    return 0;
}