#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <iterator>

bool
isValid(const std::string &s) {
	std::stack<char> stack;
	std::map<char, char> parentMap = {{']','['}, {')', '('}, {'}', '{'}};

	for (char c : s) {
		auto it = parentMap.find(c);
		if (it == parentMap.end()) {
			stack.push(c);
		}
		else {
			if (0 == stack.size() || parentMap[c] != stack.top())
				return false;

			stack.pop();
		}
	}

	return 0 == stack.size();
}

int
main(int argc, char const *argv[])
{
	std::string input;
	
	std::cin >> input;

	if (isValid(input)) {
		std::cout << "is valid" << std::endl;
	}
	else {
		std::cout << "invalid" << std::endl;
	}
	
	return 0;
}