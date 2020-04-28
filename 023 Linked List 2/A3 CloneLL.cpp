/*
Clone a linked list

Given a doubly linked list of integers with one pointer of each node pointing to the next node 
(just like in a single link list) while the second pointer, however, can point to any node in 
the list and not just the previous node. You have to create a copy of this list and return the 
head pointer of the duplicated list. 

Input Format
The only argument given is head pointer of the doubly linked list.

Output Format
Return the head pointer of the duplicated list. 

Constraints
1 <= length of the list <= 100000
1 <= Value of node <= 10^5

For Example
Input 1:
     1 -> 2 -> 3 -> 4 -> 5
     random pointer of each node 
     1 -> 5 2 -> 4 3 -> 3 4 -> 2 5 -> 1


Output 1:
    1 -> 2 -> 3 -> 4 -> 5
    random pointer of each node 
    1 -> 5 2 -> 4 3 -> 3 4 -> 2 5 -> 1
*/



/*
struct ListNode { 
    int val; 
    ListNode *next,*random; 
    ListNode(int x) { 
        val = x; 
        next = random = NULL; 
    } 
}; 
*/
ListNode* clonelist(ListNode *A) {
    
    ListNode *curr, *next;
    
    for (curr = A; curr != NULL; ){
        next = curr ->next;
        curr->next = new ListNode(curr->val);
        curr->next->next = next;
        curr = next;
    }
    
    for (curr = A; curr!=NULL; curr = curr->next->next)
        curr->next->random = (curr->random!=NULL) ? curr->random->next : NULL;

    ListNode *cloneHead = A->next, *clone = A->next;
    curr = A;
    
    while (clone->next->next != NULL){
        clone = curr->next;
        next = clone->next;
        clone->next = clone->next->next;
        curr->next = next;
        curr = next;
    }
    
    return cloneHead;
}
