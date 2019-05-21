#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Pair {
	int value;
	int count;

	Pair(int a, int b) {
		value = a;
		count = b;
	}
};

class Solution {
public:
	static string countAndSay(int n) {
		if (n == 0)
			return "";

		string res = "1";

		while (--n) {
			string str = "";
			int count = 1;
			for (int i = 0; i != res.length(); ++i) {
				
				if ((i + 1) != res.length() && res[i] == res[i + 1]) {
					count++;
				}
				else {
					str += to_string(count) + res[i];
					count = 1;
				}
			}

			res = str;
		}

		return res;
	}
};

int
main(int argc, char const *argv[])
{
	if (argc != 2) {
		cout << "argument error!" << endl;
	}

	int arg = atoi(argv[1]);

	cout <<  Solution::countAndSay(arg) << endl;
	return 0;
}