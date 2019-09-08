#include <iostream>
#include <vector>

using namespace std;

void helper(int n, int row, vector<string>& crtResult, int& result, vector<int>& flag_col, vector<int>& flag_p, vector<int>& flag_q)
{
    if (row == n) {
        result++;
        return;
    }

    auto checkResult = [](vector<int>& con, int val) {
        return 1 == con[val];
    };

    for (int i = 0; i != n; ++i) {
        // flag_q + n to avoid negative number
        if (checkResult(flag_col, i) || checkResult(flag_p, row + i) || checkResult(flag_q, row - i + n)) {
            continue;
        }

        flag_col[i] = 1;
        flag_p[row + i] = 1;
        flag_q[row - i + n] = 1;

        crtResult[row][i] = 'Q';
        helper(n, row + 1, crtResult, result, flag_col, flag_p, flag_q);
        crtResult[row][i] = '.';

        flag_col[i] = 0;
        flag_p[row + i] = 0;
        flag_q[row - i + n] = 0;
    }
}

int solution(int n)
{
    if (n <= 0)
        return {};

    vector<int> flag_col(n, 0);
    vector<int> flag_p(2*n, 0);
    vector<int> flag_q(2*n, 0);

    int result;
    vector<string> itemResult(n, string(n, '.'));
    helper(n, 0, itemResult, result, flag_col, flag_p, flag_q);

    return result;
}

int main()
{
    auto ret = solution(5);

    cout << "solution number is " << ret << endl;

    return 0;
}