#include <iostream>
#include <vector>
#include <queue>
#include <deque>

std::vector<int>
maxSlidingWindow(std::vector<int>& nums, int k) {
	if (nums.size() == 0) return {};

	std::vector<int> res;

	// priority queue
    // std::priority_queue<int, std::vector<int>, std::less<int> > window;
    
    // for (int index = 0; index <= (nums.size() - k); ++index) {
	//     while (window.size()) {
	//     	window.pop();
	//     }

	//     for (int i = 0; i != k; ++i) {
    // 		window.push(nums[index+i]);
	//     }

	//     res.push_back(window.top());
    // }

    // deque
    std::deque<int> window;

    for (int index = 0; index < nums.size(); ++index) {
		if (index >= k && (index - k) >= window.front()) {
			window.pop_front();
		}

		while (window.size() && nums[window.back()] < nums[index]) {
			window.pop_back();
		}

    	window.push_back(index);

    	if (index >= k-1)
			res.push_back(nums[window.front()]);
    }

    return res;
}

int
main(int argc, char const *argv[])
{
	std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};

	std::vector<int> res = maxSlidingWindow(nums, 3);

	for (auto i : res) {
		std::cout << i << std::endl;
	}

	return 0;
}