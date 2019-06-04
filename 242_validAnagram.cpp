#include <iostream>
#include <algorithm>
#include <map>

static bool isAnagram(std::string s, std::string t) {
    // sort O(NlogN)
    // std::sort(s.begin(), s.end());
    // std::sort(t.begin(), t.end());

    // if(s == t) {
    //     return true;
    // }
    // return false;

    if (s.size() != t.size())
        return false;

    // map
    char m[26] = {0};

    for (auto i : s) {
        m[i - 'a']++;
    }

    for (auto i : t) {
        if (0 > --m[i - 'a'])
            return false;
    }

    return true;
}

int
main(int argc, char const *argv[])
{
    std::string s1 = "anr";
    std::string s2 = "rna";

    std::cout << isAnagram(s1, s2) << std::endl;

    return 0;
}
