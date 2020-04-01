/*

Linked-List

Problem Description

Design and implement a Linked List data structure. 
A node in a linked list should have the following attributes - an integer value and a pointer to the next node. 

It should support the following operations: 
insert_node(position, value) - To insert the input value at the given position in the linked list.
delete_node(position) - Delete the value at the given position from the linked list.
print_ll() - Print the entire linked list, such that each element is followed by a single space.
Note:
If an input position does not satisfy the constraint, no action is required.
Each print query has to be executed in new line.
 


Problem Constraints
1 <= position <= n where, n is the size of the linked-list.


Input Format
First line contains an integer denoting number of cases, let's say t.
Next t line denotes the cases.


Output Format
When there is a case of print_ll(),  Print the entire linked list, such that each element is followed by a single space.
NOTE: You don't need to return anything.


Example Input
5
i 1 23
i 2 24
p
d 1
p


Example Output
23 24
24


Example Explanation
After first two cases linked list contains two elements 23 and 24.
At third case print: 23 24.
At fourth case delete value at first position, only one element left 24.
At fifth case print: 24.


*/


#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int x){
        data = x;
        next = NULL;
    }
};


struct Node *root = NULL;
int size_of_ll = 0;

void insert_node(int position, int value) {
    
    if (position >= 1 && position <= size_of_ll+1){  
        
        if (position == 1){
            Node *dummy = new Node(value);
            dummy->next = root;
            root = dummy;
        }

        else {
            Node *prev = NULL, *curr = root;
            while (--position){
                prev = curr;
                curr = curr->next;
            }
            prev->next = new Node(value);
            prev->next->next = curr;
        }
        
        size_of_ll++;
    }
    
}

void delete_node(int position) {
    
    if (position >= 1 && position <= size_of_ll){
        
        if (position == 1){
            root = root->next;
        }
        else{
            Node *prev = NULL, *curr = root;
            while (--position){
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            free(curr);
        }
        size_of_ll--;
    }
}


void print_ll() {
    Node *temp = root;
    
    while (temp != NULL&&temp->next != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data;
}
