#pragma once
#include <stdlib.h>
#include <time.h>
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class AddTwoNumbers {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	int Main();
	~AddTwoNumbers() {};
};