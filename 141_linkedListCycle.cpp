#include <iostream>
#include <set>

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	static bool hasCycle(ListNode *head) {
		// set
		// std::set<ListNode*> nodeSet;
		// while (head) {
		// 	if (nodeSet.end() != nodeSet.find(head)) {
		// 		return true;
		// 	}
		// 	nodeSet.insert(head);
		// 	head = head->next;
		// }

		// return false;

		// quick and slow pointer
		ListNode *quick = head;
		ListNode *slow = head;

		while (NULL != quick && NULL != quick->next) {
			slow = slow->next;
			quick = quick->next->next;

			if (quick == slow) {
				return true;
			}
		}

		return false;
	}
};

void
showList(ListNode *head) {
	while (head) {
		std::cout << head->val << std::endl;
		head = head->next;
	}
}

int
main(int argc, char const *argv[])
{
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	// showList(&a);

	if (Solution::hasCycle(&a)) {
		std::cout << "hasCycle" << std::endl;
	}
	else {
		std::cout << "has no cycle" << std::endl;
	}

	return 0;
}