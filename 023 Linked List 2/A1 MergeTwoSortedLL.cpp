/*
Merge Two Sorted Lists

Problem Description
Merge two sorted linked lists A and B and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted. 


Problem Constraints
0 <= |A|, |B| <= 105


Input Format
The first argument of input contains a pointer to the head of linked list A. 
The second argument of input contains a pointer to the head of linked list B. 


Output Format
Return a pointer to the head of the merged linked list.


Example Input
Input 1:
A = [5, 8, 20]
B = [4, 11, 15]
Input 2:
A = [1, 2, 3]
B = []


Example Output
Output 1:
[4, 5, 8, 11, 15, 20]
Output 2:
[1, 2, 3]


Example Explanation
For the first example, merging A and B will result in [4, 5, 8, 11, 15, 20]. 
For the second example, we don't need to merge as B is empty. 

*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    
    // Iterative SOlution:-  Too confusing isn't it?
    
//     ListNode *head;
//     if (A->val < B->val){
//         head = A;
//         A = A->next;
//     }
//     else{
//         head = B;
//         B = B->next;
//     }
    
//     ListNode *temp = head;
    
//     while (A != NULL && B != NULL){
//         if (A->val < B->val){
//             temp->next = A;
//             A = A->next;
//         }
//         else{
//             temp->next = B;
//             B = B->next;
//         }
//         temp = temp->next;
//     }
    
//     if (A != NULL)
//         temp->next = A;

//     if (B != NULL){
//         temp->next = B;
//       
//     return head;
// }



// Have a look at the recursive solution: Let's see the power of recursion


        if (A == NULL)
            return B;
        if (B == NULL)
            return A;
        
        if (A->val < B->val){
            A->next = mergeTwoLists(A->next, B);
            return A;
        }
        else{
            B->next = mergeTwoLists(A, B->next);
            return B;
        }
    }

