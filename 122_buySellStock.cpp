#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> prices)
{
    int profit = 0;
    int size = prices.size();

    for (int i = 0; i != size - 1; ++i) {
        if (prices[i+1] > prices[i]) {
            profit += prices[i+1] - prices[i];
        }
    }

    return profit;
}

int main(int argc, char const *argv[])
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(prices) << endl;

    return 0;
}
