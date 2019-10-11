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

int maxProfit(vector<int>& prices, int fee)
{
    int size = prices.size();

    int profit = 0;

    // vector<vector<int>> result(2, vector<int>(2, INT_MIN));
    // result[0][0] = 0;
    // result[0][1] = -prices[0];
    
    // for (int i = 1; i < size; ++i) {
    //     int m = i % 2;
    //     int n = (i+1) % 2;

    //     result[m][0] = max(result[n][0], result[n][1] + prices[i] - fee);
    //     result[m][1] = max(result[n][1], result[n][0] - prices[i]);
    //     profit = max(profit, result[m][0]);

    //     cout << "i = " << i << " profit = " << profit << endl;
    // }

    int hold = -prices[0];

    for (int i = 1; i < size; ++i) {
        /*
         * We can transform profit first without using temporary variables because 
         * selling and buying on the same day can't be better than just continuing to hold the stock.
         */
        // int tmp = profit;
        profit = max(profit, hold + prices[i] - fee);
        hold = max(hold, profit - prices[i]);
    }

    return profit;
}

int main(int argc, char const *argv[])
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};

    int ret = maxProfit(prices, 2);

    cout << "result = " << ret << endl;

    return 0;
}
