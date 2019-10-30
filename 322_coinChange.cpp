#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

int recursiveHelper(vector<int>& coins, int index, int overage, int length, map<int, int>& memory)
{
    if (overage == 0) {
        return length;
    }

    int ret = __INT_MAX__;

    if (index < coins.size() && 0 < overage) {
        int maxValue = overage / coins[index];
        for (int i = maxValue; i >= 0; --i) {
            int tmp = recursiveHelper(coins, index + 1, overage - i * coins[index], length + i, memory);
            if (-1 != tmp && tmp < ret) {
                ret = tmp;
            }

            cout <<  "i = " << i << " tmp = " << tmp << " index = " << index << endl;
        }
    }

    return ret == __INT_MAX__ ? -1 : ret;
}

int coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    // DP
    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j != coins.size(); ++j) {
            if (i >= coins[j]) {
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main(int argc, char const *argv[])
{
    vector<int> coins = {1, 2, 5};

    int ret = coinChange(coins, 11);

    cout << "result is " << ret << endl;

    return 0;
}
