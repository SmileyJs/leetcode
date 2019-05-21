#include <iostream>

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};

void
showNode(ListNode *head) {
	while (head) {
		std::cout << head->val << std::endl;
		head = head->next;
	}
};

class Solution {
public:
	static ListNode* swapNodeInPair(ListNode *head) {
		// iterate
		ListNode *cur = head, *next = NULL, *pre = NULL, *first = new ListNode(-1);
		first->next = head;
		pre = first;

		while (cur && cur->next) {
			next = cur->next;
			
			cur->next = next->next;
			next->next = cur;

			pre->next = next;
			pre = cur;

			cur = cur->next;
		}	

		return first->next;

		// recurse
		// if (NULL == head || NULL == head->next)
		// 	return head;

		// ListNode *next = head->next;
		// head->next = swapNodeInPair(head->next->next);
		// next->next = head;

		// return next;
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

	showNode(&a);

	showNode(Solution::swapNodeInPair(&a));

	return 0;
}