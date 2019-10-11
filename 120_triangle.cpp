#include <iostream>
#include <vector>

using namespace std;

// traverse
int helper(vector<vector<int>>& triangle, int i, int j)
{
    if (triangle.size() == i) {
        return 0;
    }

    int l = helper(triangle, i + 1, j);
    int r = helper(triangle, i + 1, j + 1);

    return l < r ? l + triangle[i][j] : r + + triangle[i][j];
}

int minimumTotal(vector<vector<int>>& triangle) {
    // return helper(triangle, 0, 0);
    int n = triangle.size();

    vector<int> min = triangle[n - 1];

    for (int i = n - 2; i >=0; --i) {
        for (int j = 0; j <= i; ++j) {
            int tmp = min[j] < min[j+1] ? min[j] : min[j+1];
            min[j] = triangle[i][j] + tmp; // 状态压缩
        }
    }

    return min[0];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> vec = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << "result: " << minimumTotal(vec) << endl;

    return 0;
}