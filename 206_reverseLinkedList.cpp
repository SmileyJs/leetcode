#include <iostream>

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x)
		: val(x)
		, next(NULL) {}
};

void
showList(ListNode *head) {
	while (head) {
		std::cout << head->val << std::endl;
		head = head->next;
	}
}

class Solution {
public:
	static ListNode* reverseList(ListNode *head) {
		// recursion
		if (NULL == head || NULL == head->next)
			return head;

		ListNode *p = reverseList(head->next);

		head->next->next = head;
		head->next = NULL;

		return p;

		// iterate
		ListNode *cur = head;
		ListNode *prev = NULL;
		ListNode *post;

		while (cur) {
			post = cur->next;
			cur->next = prev;
			prev = cur;
			cur = post;
		}

		return prev;
	}
};

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

	showList(&a);

	showList(Solution::reverseList(&a));

	return 0;
}