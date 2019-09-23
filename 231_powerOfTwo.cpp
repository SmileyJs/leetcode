#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && ((n & (n - 1)) == 0);
}

int main(int argc, char const *argv[])
{
    cout << "reuslt = " << isPowerOfTwo(64) << endl;

    return 0;
}
