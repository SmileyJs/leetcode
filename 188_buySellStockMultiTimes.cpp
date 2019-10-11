#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int profit = 0;

    int size = prices.size();

    for (int i = 1; i != size; ++i) {
        if (prices[i] > prices[i-1]) {
            profit += prices[i] - prices[i-1];
        }
    }

    return profit;
}

int maxProfit(int count, vector<int>& prices) {
    // DP
    int size = prices.size();

    if (1 >= size || 0 == count) {
        return 0;
    }

    if (size/2 < count) {
        return maxProfit(prices);
    }

    int profit = 0;

    vector<vector<vector<int>>> result(2, vector<vector<int>>(count + 1, vector<int>(2, 0)));
    result[0][0][0] = 0;
    result[0][0][1] = -prices[0];
    result[0][1][0] = 0;
    result[0][1][1] = INT_MIN;
    result[0][2][0] = 0;
    result[0][2][1] = INT_MIN;

    for (int i = 1; i != size; ++i) {
        int m = i % 2;
        int n = (i + 1) % 2;
        for (int k = 0; k <= count && k <= (i+1)/2; ++k) {
            if (k == 0) {
                result[m][k][0] = 0;
            }
            else {
                result[m][k][0] = std::max(result[n][k-1][1] + prices[i], result[n][k][0]);
            }

            if (k == count) {
                result[m][k][1] = INT_MIN;
            }
            else {
                result[m][k][1] = std::max(result[n][k][0] - prices[i], result[n][k][1]);
            }

            profit = max(profit, result[m][k][0]);

            cout << "i = " << i << " k = " << k << " " << result[m][k][0] << " " << result[m][k][1] << endl;
        }
    }

    return profit;
}

int main(int argc, char const *argv[])
{
    vector<int> prices = {3, 2, 6, 5, 0, 3};

    int ret = maxProfit(2, prices);

    cout << "result = " << ret << endl;

    return 0;
}
