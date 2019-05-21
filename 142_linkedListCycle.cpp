#include <iostream>
#include <set>

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	static ListNode* hasCycle(ListNode *head) {
		// set
		// std::set<ListNode*> nodeSet;
		// while (head) {
		// 	auto ret = nodeSet.find(head);
		// 	if (nodeSet.end() != ret) {
		// 		return *ret;
		// 	}
		// 	nodeSet.insert(head);
		// 	head = head->next;
		// }

		// return false;

		// quick and slow pointer
		ListNode *quick = head;
		ListNode *slow = head;
		ListNode *entry = NULL;

		while (NULL != quick && NULL != quick->next) {
			slow = slow->next;
			quick = quick->next->next;

			if (quick == slow) {
				entry = head;
				while (slow != entry) {
					slow = slow->next;
					entry = entry->next;
				}
				return entry;
			}
		}

		return NULL;
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
	d.next = &b;

	ListNode *ret = Solution::hasCycle(&a);

	if (NULL != ret) {
		std::cout << "begin at " << ret->val << std::endl;
	}
	else {
		std::cout << "there is no cycle" << std::endl;
	}

	return 0;
}