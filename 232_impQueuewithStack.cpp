#include <iostream>
#include <stack>

class MyQueue {
public:
	MyQueue() {

	}

	void push(int x) {
		in.push(x);
	}

	int pop() {
		if (0 == out.size()) {
			sendIn2Out();
		}

		int ret = out.top();
		out.pop();

		return ret;
	}

	int peek() {
		if (0 == out.size()) {
			sendIn2Out();
		}

		return out.top();
	}

	bool empty() {
		return 0 == in.size() && 0 == out.size();
	}

private:
	void sendIn2Out() {
		while (0 != in.size()) {
			out.push(in.top());
			in.pop();
		}
	}

	std::stack<int> in;
	std::stack<int> out;
};

int
main(int argc, char const *argv[])
{
	MyQueue queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);

	while (!queue.empty()) {
		std::cout << queue.peek() << " " << queue.pop() << std::endl;
	}

	return 0;
}