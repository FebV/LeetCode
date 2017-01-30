#include <vector>
#include <iostream>
using namespace std;

typedef struct listnode {
    int val;
    listnode *next;
    listnode(int x) : val(x), next(nullptr) {}
} ListNode;

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		int carry = 0;
		ListNode *ori1 = l1;
		ListNode *last = nullptr;
		
		while (l1 != nullptr && l2 != nullptr) {
			int curNum = l1->val + l2->val + carry;
			carry = 0;
			if (curNum > 9) {
				curNum -= 10;
				carry = 1;
			}
			l1->val = curNum;
			last = l1;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1 == nullptr && l2 == nullptr) {
			if (carry != 0) {
				ListNode *lastOne = new ListNode(1);
				last->next = lastOne;
				return ori1;
			}
			else
				return ori1;
		}
		if (l1 == nullptr) {
			if (l2 != nullptr) {
				last->next = l2;
				l1 = l2;
			}
		}

		while (l1 != nullptr && carry != 0) {
			int curNum = l1->val + carry;
			carry = 0;
			if (curNum > 9) {
				l1->val = curNum - 10;
				carry = 1;
			}
			else {
				l1->val = curNum;
			}
			last = l1;
			l1 = l1->next;
		}
		if (carry != 0) {
			ListNode *lastOne = new ListNode(1);
			last->next = lastOne;
		}
		return ori1;
	}
};

void testAddTwoNumbers() {

	//beat 60.37% on 2017-01-30
	//same code runtime varies every submit.

	Solution s;
	ListNode ln11(1);
	//ListNode ln12(8);
	//ListNode ln13(3);
	//ln11.next = &ln12;
	//ln12.next = &ln13;
	
	ListNode ln21(9);
	ListNode ln22(9);
	//ListNode ln23(4);
	ln21.next = &ln22;
	//ln22.next = &ln23;


	ListNode *ln = s.addTwoNumbers(&ln11, &ln21);
	while (ln != nullptr) {
		cout << ln->val << endl;
		ln = ln->next;
	}
	system("pause");
}
