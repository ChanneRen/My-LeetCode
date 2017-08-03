/*
	problem:	Merge k Sorted Lists
	difficulty:	hard
	description:	Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
  	tags:		Divide and Conquer, Linked List, Heap
	
	solution:	On seeing this problem, I know #Heap# works.
			The key is to implement a small-root-heap.
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
    struct cmp{  
    bool operator()(ListNode* a,ListNode* b){  
        return a->val > b->val;
        }  
    }; 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(auto node : lists)
            if(node)
                q.push(node);
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while(!q.empty())
        {
            ListNode *p = q.top();
            q.pop();
            cur->next = p;
            cur = cur->next;
            if(p->next) q.push(p->next);
        }
        cur = head->next;
        delete head;
        return cur;
    }
};
