#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxProfit(vector<int> prices)
{
    // DP
    int size = prices.size();

    if (2 > size) {
        return 0;
    }

    int profit = 0;

    vector<vector<vector<int>>> result(2, vector<vector<int>>(2 + 1, vector<int>(2, 0)));
    result[0][0][0] = 0;
    result[0][0][1] = -prices[0];
    result[0][1][0] = 0;
    result[0][1][1] = INT_MIN;
    result[0][2][0] = 0;
    result[0][2][1] = INT_MIN;

    for (int i = 1; i != size; ++i) {
        int m = i % 2;
        int n = (i + 1) % 2;
        result[m][0][0] = 0;
        result[m][0][1] = max(result[n][0][1], result[n][0][0] - prices[i]);

        result[m][1][0] = max(result[n][1][0], result[n][0][1] + prices[i]);
        result[m][1][1] = max(result[n][1][1], result[n][1][0] - prices[i]);

        result[m][2][0] = max(result[n][2][0], result[n][1][1] + prices[i]);

        cout << "i = " << i << endl;
    }

    int index = (size-1) % 2;
    profit = max(result[index][0][0], max(result[index][1][0], result[index][2][0]));

    return profit;
}

int main(int argc, char const *argv[])
{
    // vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    vector<int> prices = {1, 2, 3, 4, 5};

    cout << maxProfit(prices) << endl;

    return 0;
}
