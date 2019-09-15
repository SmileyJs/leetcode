#include <iostream>
#include <cmath>

using namespace std;

int mySqrt(int x)
{
    if (0 == x || 1 == x) {
        return x;
    }

    // int left = 1, right = x, ret;
    // while (left < right) {
    //     int m = left + (right - left) / 2;
    //     // 使用 m 和 x/m 比较是为了防止 m*m 越界
    //     if (m == x / m) {
    //         return m;
    //     }
    //     else if (m > x / m) {
    //         right = m;
    //     }
    //     else {
    //         left = m;
    //         // 因为返回int, 结果肯定是比真实值小的那个, 而不是比较接近的那个, 所以只能返回相对小的那个值, 在 m < x / m 时保存
    //         ret = m;
    //     }
    // }

    // newton iterate
    double ret = x;
    double delta = 0.00001;
    while (std::fabs(ret - x/ret) > delta) {
        ret = (ret + x / ret) / 2;
    }
    
    return ret;
}

int main(int argc, char const *argv[])
{
    cout << mySqrt(11) << endl;

    return 0;
}
