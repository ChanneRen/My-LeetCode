
/*
	problem:	Merge Two Sorted Lists
	difficulty:	easy
	description:	Merge two sorted linked lists and return it as a new list. 
    			The new list should be made by splicing together the nodes of the first two lists.
  	tags:		Linked List
	
	solution:	A classical problem for #Linked List#.
			Just be carefule of the NULL nodes or pointer.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *cur, *head = new ListNode(0);
        cur = head;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur ->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1 == NULL) cur->next = l2;
        else    cur->next = l1;
        cur = head->next;
        delete head;
        return cur;
    }
};
