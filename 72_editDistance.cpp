#include <iostream>
#include <vector>

using namespace std;

int minDistance(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();

    vector<int> cur(n+1, 0);
    vector<int> pre(n+1, 0);

    for (int i = 0; i <= n; ++i) {
        pre[i] = i;
    }

    for (int i = 1; i <= m; ++i) {
        cur[0] = i;
        for (int j = 1; j <= n; ++j) {
            if (word1[i-1] == word2[j-1]) {
                cur[j] = pre[j - 1];
            }
            else {
                cur[j] = 1 + std::min(pre[j-1], std::min(cur[j-1], pre[j]));
            }
        }
        fill(pre.begin(), pre.end(), 0);
        swap(pre, cur);
    }

    return pre[n];
}

int main(int argc, char const *argv[])
{
    std::string word1 = "horse";
    std::string word2 = "ros";

    auto ret = minDistance(word1, word2);

    cout << "result is " << ret << endl;

    return 0;
}
