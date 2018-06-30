/*
	problem:	Rotate List
	difficulty:	medium
	description:	Given a linked list, rotate the list to the right by k places, where k is non-negative.
  	tags:		List, Two Points
	
	solution:	This time I solve the problem as following: rotating the list is to find a place to cut the list, 
                        the left position of the cut-place should be the new tail while the right will be the new head.
			Firstly, get the length of the list, if k equals the length or zero, we can return the list directly;
			Then get the real value of k using the modulus, now we can find the palce to cut;
			Finally, re-define new head and tail.
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int listLength = 0;
        ListNode* p = head, *tail = NULL;
        while(p)
        {
            listLength++;
            tail = p;
            p = p->next;
        }
        if(k == 0 || k == listLength || head == NULL)   return head;
        k = k % listLength;
        k = listLength - k;
        p = head;
        while(--k)
        {
            p = p ->next;
        }
        tail->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};
