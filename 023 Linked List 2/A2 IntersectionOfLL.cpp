/*
Intersection of Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins. 
For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.


Problem approach completely explained : VIDEO: https://www.youtube.com/watch?v=gE0GopCq378 

Complete code in the hints section.

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    
    int m = 0, n = 0, diff = 0;
    
    ListNode *head1 = A, *head2 = B;
    
    while (head1!= NULL){
        m++;
        head1 = head1->next;
    }
    
    while (head2 != NULL){
        n++;
        head2 = head2->next;
    }
    
    if (m>n){
        diff = m-n;
        while (diff--)
            A = A->next;
    }
    else{
        diff = n-m;
        while (diff--)
            B = B->next;
    }
    
    while (A != NULL || B != NULL){
        if (A == B){
            return A;
        }
        A = A ->next;
        B = B -> next;
    }
    return NULL;
}
