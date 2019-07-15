#include <iostream>
#include <vector>
#include <unordered_map>

static std::vector<int>
twoSum(std::vector<int>& nums, int target) {
    
    int size = nums.size();

    // brute force
    // for (int i = 0; i != size; ++i) {
    //     for (int j = i + 1; j != size; ++j) {
    //         if (target == (nums[i] + nums[j]))
    //             return {i, j};
    //     }
    // }

    // map
    std::unordered_map<int, int> containor;

    for (int i = 0; i != size; ++i) {
        int tmp = target - nums[i];
        if (containor.end() != containor.find(tmp)) {
            return {containor[tmp], i};
        }

        containor.insert(std::make_pair(nums[i], i));
    }

    return {0};
}

int
main(int argc, char const *argv[])
{
    std::vector<int> array = {2, 7, 11, 16};

    std::vector<int> res = twoSum(array, 9);

    for (auto i : res) {
        std::cout << array[i] << std::endl;
    }

    return 0;
}
