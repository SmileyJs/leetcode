#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int bruteForce(int index, vector<int>& nums, int pre)
{
    if (index == nums.size()) {
        return 0;
    }

    int taken = 0;
    int noTaken = 0;

    if (nums[index] > pre) {
        taken = 1 + bruteForce(index + 1, nums, nums[index]);
    }

    noTaken = bruteForce(index + 1, nums, pre);

    return taken > noTaken ? taken : noTaken;
}

int bruteForceWithMemory(int index, vector<int>& nums, int preIndex, vector<vector<int>> memory)
{
    if (index == nums.size()) {
        return 0;
    }

    if (memory[index][preIndex + 1] > INT_MIN) {
        return memory[index][preIndex + 1];
    }

    int taken = 0;
    int noTaken = 0;

    if (preIndex < 0 || nums[index] > nums[preIndex]) {
        taken = 1 + bruteForceWithMemory(index + 1, nums, index, memory);
    }

    noTaken = bruteForceWithMemory(index + 1, nums, preIndex, memory);

    memory[index][preIndex + 1] = std::max(noTaken, taken);

    return memory[index][preIndex + 1];
}

int lengthOfLIS(vector<int>& nums)
{
    int size = nums.size();

    if (size < 2) {
        return size;
    }

    int maxLen = 0;

    // DP
    // vector<int> res(size, 1);
    // for (int i = 0; i != size; ++i) {
    //     for (int j = 0; j != i; ++j) {
    //         if (nums[i] > nums[j]) {
    //             res[i] = std::max(res[i], res[j] + 1);
    //         }
    //     }

    //     maxLen = std::max(maxLen, res[i]);
    // }

    // binary search
    vector<int> res;
    for (int i = 0; i != size; ++i) {
        auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
        if (it != res.end()) {
            *it = nums[i];
        }
        else {
            res.push_back(nums[i]);
        }
    }

    maxLen = res.size();

    return maxLen;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {10,9,2,5,3,7,101,18};

    int ret = lengthOfLIS(nums);

    cout << "result = " << ret << endl;

    return 0;
}
