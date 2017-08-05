/*
	problem:	Swap Nodes in Pairs
	difficulty:	medium
	description:	Given a linked list, swap every two adjacent nodes and return its head.
			For example: Given 1->2->3->4, you should return the list as 2->1->4->3.
			Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
	note:		Given n will always be valid. Try to do this in one pass.
  	tags:		Linked List
	
	solution:	What you should pay attention to are POINTERS for #Linked List# problems.
			1. in case of NULL pointer; 2. be care of pointer changes, especially in a loop; 3. new and delete for node.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)  return head;
        ListNode *helper = new ListNode(0);
        helper->next = head;
        ListNode *pre = helper, *cur = head;
        while(cur && cur->next)
        {
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = cur;
            pre = cur;
            cur = cur->next;
        }
        head = helper->next;
        delete helper;
        return head;
    }
};
