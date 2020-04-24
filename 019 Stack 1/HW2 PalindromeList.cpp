/*
Palindrome List
Problem Description
Given a singly linked list A, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.


Problem Constraints
1 <= |A| <= 105


Input Format
The first and the only argument of input contains a pointer to the head of the given linked list.


Output Format
Return 0, if the linked list is not a palindrome. Return 1, if the linked list is a palindrome. 


Example Input
Input 1:
A = [1, 2, 2, 1]
Input 2:
A = [1, 3, 2]


Example Output
Output 1:
 1 
Output 2:
 0 


Example Explanation
The first linked list is a palindrome as [1, 2, 2, 1] is equal to its reversed form. 
The second linked list is not a palindrom as [1, 3, 2] is not equal to [2, 3, 1]. 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode *reverseLL( ListNode *root, ListNode *prev ){
    
    if ( root == NULL )
        return prev;
    
    ListNode *next1 = root -> next;
    root -> next = prev;
    //prev = root;
    
    return reverseLL( next1, root );
}

int Solution::lPalin(ListNode* A) {
    
    if (A->next == NULL)
        return 1;
    
    if (A -> next -> next == NULL)
        if (A->val != A->next->val)
            return 0;
        else
            return 1;
    
    
    ListNode *fast = A, *slow = A, *prev;

    while ( fast != NULL && fast -> next != NULL){
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    prev -> next = NULL;
    
    ListNode *head2 = reverseLL(slow, NULL);
    
    while ( A != NULL){
        if ( A -> val != head2 -> val)
            return 0;
        
        A = A -> next;
        head2 = head2 -> next;
    }
    
    return 1;
}
