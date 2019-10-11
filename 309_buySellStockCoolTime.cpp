#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int size = prices.size();

    if (2 > size) {
        return 0;
    }

    int profit = 0;
    bool coolDown = false;

    vector<vector<vector<int>>> result(2, vector<vector<int>>(2, vector<int>(2, INT_MIN)));
    result[0][0][0] = 0;
    result[0][1][0] = -prices[0];

    for (int i = 1; i != size; ++i) {
        int m = i % 2;
        int n = (i+1) % 2;

        result[m][0][0] = max(result[n][0][0], result[n][0][1]);
        result[m][1][0] = max(result[n][0][0] - prices[i], result[n][1][0]);
        result[m][0][1] = result[n][1][0] + prices[i];

        profit = max(profit, max(result[m][0][0], result[m][0][1]));

        cout << "i = " << i << " profit = " << profit << endl;
    }

    return profit;
}

int main(int argc, char const *argv[])
{
    vector<int> prices = {1, 2, 3, 0, 2};

    int ret = maxProfit(prices);

    cout << "result = " << ret << endl;

    return 0;
}
