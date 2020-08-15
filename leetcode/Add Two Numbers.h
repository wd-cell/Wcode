#pragma once
#include<iostream>
using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res = new ListNode(0);
		ListNode* cur = res;
		int num1, num2;
		int carry = 0;

		//figure out
		while (l1 || l2) {
			num1 = (l1 == NULL) ? 0 : l1->val;	// 0表示 l1为0 或 l1结束 
			num2 = (l2 == NULL) ? 0 : l2->val;
			cur->next = new ListNode((num1 + num2 + carry) % 10);
			carry = (num1 + num2 + carry >= 10) ? 1 : 0;

			l1 = l1->next;
			l2 = l2->next;
		}
		if (carry == 1) // 最高位进位
			cur->next = new ListNode(carry);
		if (res->next != NULL)
			res = res->next;

		return res;
	}
};