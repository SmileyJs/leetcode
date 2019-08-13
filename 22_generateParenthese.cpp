#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(string str, int left, int right, int num, vector<string> &result) 
{
    if (num == left && left == right) {
        result.push_back(str);
        return;
    }
    
    if (left < num) {
        helper(str + "(", left + 1, right, num, result);
    }
    if (right < num && right < left) {
        helper(str + ")", left, right + 1, num, result);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ret;

    string s = "";

    helper(s, 0, 0, n, ret);

    return ret;
}


int main(int argc, char const *argv[])
{
    vector<string> ret = generateParenthesis(3);

    for (auto i = ret.begin(); i != ret.end(); ++i) {
        cout << *i << endl;
    }

    return 0;
}
