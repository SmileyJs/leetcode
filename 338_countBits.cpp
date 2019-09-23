#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int num)
{
    vector<int> ret(num + 1, 0);

    for (int i = 1; i <= num; ++i) {
        ret[i] = ret[i & (i - 1)] + 1;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    vector<int> ret = countBits(5);

    for (int i : ret) {
        cout << i << endl;
    }

    return 0;
}
