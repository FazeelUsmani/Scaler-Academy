/*

Merge K Sorted Lists
Problem Description

Given a list containing head pointers of N sorted linked lists. Merge these N given sorted linked lists and return it as one sorted list.



Problem Constraints
1 <= total number of elements in given linked lists <= 100000



Input Format
First and only argument is a list containing N head pointers.



Output Format
Return a pointer to the head of the sorted linked list after merging all the given linked lists.



Example Input
Input 1:

 1 -> 10 -> 20
 4 -> 11 -> 13
 3 -> 8 -> 9
Input 2:

 10 -> 12
 13
 5 -> 6


Example Output
Output 1:

 1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
Output 2:

 5 -> 6 -> 10 -> 12 ->13


Example Explanation
Explanation 1:

 The resulting sorted Linked List formed after merging is 1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20.
Explanation 2:

 The resulting sorted Linked List formed after merging is 5 -> 6 -> 10 -> 12 ->13.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct CompareNode {
    bool operator()(ListNode* const & p1, ListNode* const & p2) {
        return p1->val > p2->val;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    
    priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;
    
    ListNode* dummyHead = new ListNode(0);
    ListNode* tail = dummyHead;
    
    for (int i = 0; i < A.size(); i++)
        if (A[i] != NULL)
            pq.push(A[i]);
            
    while (!pq.empty()){
        tail->next = pq.top();
        pq.pop();
        tail = tail->next;
        if (tail->next)
            pq.push(tail->next);
    }
    
    return dummyHead->next;
}
