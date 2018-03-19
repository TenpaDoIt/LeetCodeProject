// AddTwoNumbers.cpp : Defines the entry point for the console application.
//
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include "stdafx.h"
#include "AddTwoNumbers.h"

ListNode* AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *ln1 = l1, *ln2 = l2, *Result, *currentPos = new ListNode(0);
	Result = currentPos;
	int tempN, NTens = 0, NOnes, val1, val2;
	while (ln1 != NULL || ln2 != NULL || NTens != 0) {
		val1 = (ln1 == NULL) ? 0 : ln1->val;
		val2 = (ln2 == NULL) ? 0 : ln2->val;
		tempN = val1 + val2 + NTens;

		NOnes = tempN % 10;
		NTens = (tempN > 9) ? 1 : 0;

		currentPos->next = new ListNode(NOnes);
		currentPos = currentPos->next;

		ln1 = (ln1 == NULL) ? NULL : ln1->next;
		ln2 = (ln2 == NULL) ? NULL : ln2->next;
	}
	return Result->next;
}

int AddTwoNumbers::Main()
{
	srand(time(NULL));

	ListNode *Head1 = new ListNode(rand() % 10), *Head2 = new ListNode(rand() % 10), *Temp, *CurrentPos;

	CurrentPos = Head1;
	for (int i = 0; i < 1; i++)
	{
		ListNode *CurrentPos = new ListNode(rand() % 10);
		CurrentPos->next = Head1;
		Head1 = CurrentPos;
	}
	Temp = Head1;
	while (Temp != NULL)
	{
		std::cout << Temp->val << "\t";
		Temp = Temp->next;
	}
	std::cout << "\n";

	CurrentPos = Head2;
	for (int i = 0; i < 1; i++)
	{
		ListNode *CurrentPos = new ListNode(rand() % 10);
		CurrentPos->next = Head2;
		Head2 = CurrentPos;
	}
	Temp = Head2;
	while (Temp != NULL)
	{
		std::cout << Temp->val << "\t";
		Temp = Temp->next;
	}
	std::cout << "\n";

	Temp = addTwoNumbers(Head1, Head2);
	while (Temp != NULL)
	{
		std::cout << Temp->val << "\t";
		Temp = Temp->next;
	}

	system("pause");
	return 0;
}
