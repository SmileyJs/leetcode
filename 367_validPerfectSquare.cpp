#include <iostream>
#include <cmath>

bool isPerfectSquare(int num)
{
    double ans = num;
    double delta = 1e-6;

    while ((ans - num/ans) > delta) {
        ans = (ans + num/ans) / 2;
    }

    return delta > std::fabs(ans - (int)(ans + 0.5));
}

int main(int argc, char const *argv[])
{
    std::cout << isPerfectSquare(16) << std::endl;
    return 0;
}
