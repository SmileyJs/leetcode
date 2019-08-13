#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int majorityElement(std::vector<int> vec)
{
    int ret = 0;
    int size = vec.size();
    
    // count
    // std::map<int, int> container; 

    // for (int i : vec) {
    //     if (container.end() != container.find(i)) {
    //         container[i] ++;
    //         if (container[i] > size/2)
    //             return i;
    //     }
    //     else {
    //         container[i] = 1;
    //     }
    // }

    // sort and return middle number
    // std::sort(vec.begin(), vec.end());

    // return vec[size/2];

    // boyce-moore vote
    int count = 0;
    
    for (auto i : vec) {
        if (count == 0) {
            ret = i;
        }

        count += (i == ret) ? 1 : -1;
    }
    
    return ret;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec = {2, 4, 2, 5, 6, 3, 2, 6, 2, 2, 2};

    std::cout << "result = " << majorityElement(vec) << std::endl; 

    return 0;
}
