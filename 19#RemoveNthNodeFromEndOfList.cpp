
/*
	problem:	Remove Nth Node From End of List
	difficulty:	medium
	description:	Given a linked list, remove the nth node from the end of list and return its head. 
	note:		Given n will always be valid. Try to do this in one pass.
  	tags:		Linked List, Two Pointers
	
	solution:	Many problem for linked list always can be solved with two pointers in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *runner = newHead, *walker = newHead;
        while(n)
        {
            runner = runner->next;
            --n;
        }
        while(runner->next)
        {
            runner = runner->next;
            walker = walker->next;
        }
        ListNode *p = walker->next;
        walker->next = p->next;
        head = newHead->next;
        delete newHead;
        delete p;
        return head;
    }
};
