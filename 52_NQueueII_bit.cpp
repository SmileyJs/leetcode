#include <iostream>

using namespace std;

void helper(int n, int row, int& result, int vCol, int vP, int vQ)
{
    if (row == n) {
        result++;
        return;
    }

    int valid = (~(vCol | vP | vQ)) & ((1 << n) - 1);

    while (valid > 0) {
        int crt = valid & (-valid);

        helper(n, row + 1, result, vCol | crt, (vP | crt) << 1, (vQ | crt) >> 1);

        valid &= valid - 1;
    }
}

int solution(int n)
{
    if (n <= 0)
        return {};

    int result = 0;
    helper(n, 0, result, 0, 0, 0);

    return result;
}

int main()
{
    auto ret = solution(5);

    cout << "solution number is " << ret << endl;

    return 0;
}