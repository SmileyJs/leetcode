#include <iostream>
#include <queue>

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
    	send2Store();
    	inOut.push(x);
    	sendBack2InOut();
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = inOut.front();
        inOut.pop();

        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return inOut.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return inOut.empty();
    }
private:
	void send2Store() {
		while (0 != inOut.size()) {
			store.push(inOut.front());
			inOut.pop();
		}
	}

	void sendBack2InOut() {
		while (0 != store.size()) {
			inOut.push(store.front());
			store.pop();
		}
	}

	std::queue<int> inOut;
	std::queue<int> store;
};

int
main(int argc, char const *argv[])
{
	MyStack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	while (!stack.empty()) {
		std::cout << stack.pop() << std::endl;
	}

	return 0;
}