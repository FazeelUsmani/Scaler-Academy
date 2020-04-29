/*

Length of longest palindromic list

Given a linked list of integers. Find and return the length of the longest palindrome list that exists in that linked list. 
Note: A palindrome list is a list that reads the same backward and forward.
Expected memory complexity : O(1) 

Input Format
The only argument given is head pointer of the linked list.

Output Format
Return the length of the longest palindrome list.

Constraints
1 <= length of the linked list <= 2000
1 <= Node value <= 100 

For Example
Input 1:
    2 -> 3 -> 3 -> 3
Output 1:
   3 

Input 2:
    A = 2 -> 1 -> 2 -> 1 ->  2 -> 2 -> 1 -> 3 -> 2 -> 2
Output 2:
    5
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A) {
    
    ListNode *curr = A;
    ListNode *temp1, *temp2, *prev = NULL;
    int ans = 0, cnt;
    
    while (curr != NULL){
        // Checking Even Linked List
        temp1 = curr;
        temp2 = prev;
        cnt = 0;
        while (temp1!=NULL && temp2!=NULL && temp1->val == temp2->val){
            cnt += 2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        ans = max(ans, cnt);
        
        // Checking Odd Linked List
        cnt = 1;
        temp1 = curr->next;
        temp2 = prev;
        while (temp1!=NULL && temp2!=NULL && temp1->val == temp2->val){
            cnt += 2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        ans = max(ans, cnt);
        
        ListNode *next1 = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next1;
    }
    
    return ans;
}
