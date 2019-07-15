#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

static vector<vector<int>>
threeSum(vector<int>& nums) {
    int size = nums.size();
    vector<vector<int>> res;
    
    if (size == 0)
        return res;

    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < size - 2; ++i) {
        if (i > 0 && nums[i-1] == nums[i]) {
            continue;
        }
        // unordered_map<int, int> numMap;
        // for (int j = i + 1; j != size; ++j) {
        //     //  这里的处理并不是把需要找的值 -nums[i]-nums[j]直接去寻找,而是记录在容器中,继续向后遍历, 在后续的遍历中判断 当前遍历到的值是否是之前需要的, 这样做减少了一层遍历
        //     if (numMap.end() != numMap.find(nums[j]) && 1 == numMap[nums[j]]) {
        //         res.push_back({nums[i], -nums[i] - nums[j], nums[j]});
        //         numMap[nums[j]] = 0;
        //     }
        //     else {
        //         numMap.insert({-nums[i] - nums[j], 1});
        //     }
        // }
        int l = i+1;
        int r = size - 1;

        while (l < r) {
			int s = nums[i] + nums[l] + nums[r];

			if (s > 0) {
				r--;
			}
			else if (s < 0) {
				l++;
			}
			else {
				res.push_back({nums[i], nums[l], nums[r]});
				while (l < r && nums[l] == nums[l+1]) {
					l++;
				}
				while (l < r && nums[r] == nums[r-1]) {
					r--;
				}
				l++;
				r--;
			}
        }
    }

    return res;
}

int
main(int argc, char const *argv[])
{
    vector<int> array = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> res = threeSum(array);

    for (auto i : res) {
        cout << "[";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "]";
    }
    
    return 0;
}
