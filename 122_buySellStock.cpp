#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> prices)
{
    // int profit = 0;
    // int size = prices.size();

    // for (int i = 0; i != size - 1; ++i) {
    //     if (prices[i+1] > prices[i]) {
    //         profit += prices[i+1] - prices[i];
    //     }
    // }

    // return profit;

    // DP
    int size = prices.size();

    if (0 == size) {
        return 0;
    }

    int profit = 0;

    vector<vector<int>> result(size, vector<int>(2, 0));
    result[0][0] = 0;
    result[0][1] = -prices[0];

    for (int i = 1; i != size; ++i) {
        result[i][0] = std::max(result[i-1][0], result[i-1][1] + prices[i]);
        result[i][1] = std::max(result[i-1][1], result[i-1][0] - prices[i]);
    }

    return result[size-1][0];
}

int main(int argc, char const *argv[])
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(prices) << endl;

    return 0;
}
