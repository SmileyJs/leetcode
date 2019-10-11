#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxProduct(vector<int>& nums) {
    int size = nums.size();

    if (0 == size) {
        return 0;
    }

    int crtMax = nums[0];

    // for (int i = 0; i != size; ++i) {
    //     int max = 1;
    //     for (int j = i; j != size; ++j) {
    //         max *= nums[j];

    //         if (max > crtMax) {
    //             crtMax = max;
    //         }
    //     }
    // }

    int max = nums[0];
    int min = nums[0];

    for (int i = 1; i != size; ++i) {
        int x = max;
        int y = min;

        max = std::max(nums[i], std::max(x * nums[i], y * nums[i]));
        min = std::min(nums[i], std::min(y * nums[i], x * nums[i]));

        if (crtMax < max) {
            crtMax = max;
        }

        cout << max <<  " " << min << endl;
    }

    return crtMax;
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {2, 3, -2, 4};

    auto ret = maxProduct(vec);

    cout << "result = " << ret << endl;

    return 0;
}
