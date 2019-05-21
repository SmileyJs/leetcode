#include <iostream>
#include <vector>
#include <queue>

class KthLargest {
public:
    KthLargest(int k, std::vector<int> nums) : kth(k) {
        for (auto i : nums) {
        	add(i);
        }
    }
    
    int add(int val) {
    	if (queue.size() < kth) {
    		queue.push(val);
    	}
    	else if (queue.top() < val ) {
    		queue.pop();
    		queue.push(val);
    	}

        return queue.top();
    }

private:
	std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
	int kth;
};

int
main(int argc, char const *argv[])
{
	KthLargest k(3, {4, 5, 8, 2});

	std::cout << k.add(3) << std::endl;

	std::cout << k.add(5) << std::endl;

	std::cout << k.add(10) << std::endl;

	std::cout << k.add(9) << std::endl;

	std::cout << k.add(4) << std::endl;

	return 0;
}