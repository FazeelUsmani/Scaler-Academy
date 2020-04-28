/*
Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. 

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {

    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = A;
    ListNode *temp = A, *prev = dummyHead;
    
    while (temp != NULL){
        
        bool flag = false;
        
        while (temp->next != NULL && temp->val == temp->next->val){
            flag = true;
            temp->next = temp->next->next;
        }
        
        if (flag){
            prev->next = temp->next;
        }
        else{
            prev->next = temp;
            prev = temp;
        }
        
        temp = temp->next;
    }
        
    return dummyHead->next;
}
