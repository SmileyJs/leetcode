#include <iostream>

using namespace std;

int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n != 0) {
        count++;
        n = n & (n - 1);
    }

    return count;
}

int
main()
{
    uint32_t val = 00000000000000000000000000001011;

    cout << "result = " << hammingWeight(val) << endl;

    return 0;
}