#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int size = prices.size();

    if (0 == size) {
        return 0;
    }

    int profit = 0;

    vector<vector<int>> result(size, vector<int>(3, 0));
    result[0][0] = 0;
    result[0][1] = -prices[0];
    result[0][2] = 0;

    for (int i = 1; i != size; ++i) {
        result[i][0] = result[i-1][0];
        result[i][1] = std::max(result[i-1][1], result[i-1][0] - prices[i]);    // the min buy value of crt time
        result[i][2] = result[i-1][1] + prices[i];

        profit = max(profit, result[i][2]);
    }

    return profit;
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {7, 1, 5, 3, 6, 4};

    int profit = maxProfit(vec);

    cout << "result is " << profit << endl;

    return 0;
}
