#include <iostream>

double myPow(double x, int n) {
    // brute force
    // double ret = 1;
    // if (n >= 0) {
    //     while (n--) {
    //         ret *= x;
    //     }
    // }
    // else {
    //     ret = 1/x;
    //     while (++n) {
    //         ret /= x;
    //     }
    // }
    // return ret;

    // divide & recursion
    // if (n == 0) {
    //     return 1;
    // }

    // if (n < 0) {
    //     if (n == -2147483648)
    //         return 1/x * myPow(x, n + 1);
    //     return 1/(myPow(x, -n));
    // }

    // if (n % 2) {
    //     return x * myPow(x, n - 1);
    // }

    // double y = myPow(x, n/2);

    // return y*y;

    // divide & iterator
    double ret = 1.0;
    
    if (n < 0) {
        if (n == -2147483648) {
            n++;
            ret *= 1/x;
        }
            
        n = -n;
        x = 1.0/x;
    }

    std::cout << x << " " << n <<std::endl;

    while (n) {
        if (n & 1) {
            ret *= x;
        }
        x *= x;
        n >>= 1;
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    std::cout << myPow(2.0000, -100) << std::endl;
    return 0;
}
