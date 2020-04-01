/*

Reorder List
Problem Description
Given a singly linked list A
 A: A0 → A1 → … → An-1 → An 
reorder it to:
 A0 → An → A1 → An-1 → A2 → An-2 → … 
You must do this in-place without altering the nodes' values. 


Problem Constraints
1 <= |A| <= 106


Input Format
The first and the only argument of input contains a pointer to the head of the linked list A.


Output Format
Return a pointer to the head of the modified linked list.


Example Input
Input 1:
 A = [1, 2, 3, 4, 5] 
Input 2:
 A = [1, 2, 3, 4] 


Example Output
Output 1:
 [1, 5, 2, 4, 3] 
Output 2:
 [1, 4, 2, 3] 


Example Explanation
In the first example, the array will be arranged to [A0, An, A1, An-1, A2]. 
In the second example, the array will be arranged to [A0, An, A1, An-1]. 

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
ListNode *reverseLL(ListNode *head, ListNode *prev){
    if (!head)
        return prev;
    
    ListNode *temp = head->next;
    head->next = prev;
    
    return reverseLL(temp, head);
}
 
ListNode* Solution::reorderList(ListNode* A) {
    
    if (!A->next)
        return A;
    
    ListNode *f = A, *s = A, *prev;
    
    while (f && f->next){
        prev = s;
        s = s->next;
        f = f->next->next;
    }
    
    prev->next = NULL;
    
    ListNode *h1 = A;
    ListNode *h2 = reverseLL(s,NULL);
    
    ListNode *temp = new ListNode(0);
    temp->next = A;
    
    while (h1 && h2){
        
        temp->next = h1;
        h1 = h1->next;
        temp = temp->next;
        
        temp->next = h2;
        h2 = h2->next;
        temp = temp->next;
        
        
    }
    if (h2)
        temp->next = h2;
    
    return A;
    
}
