#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int x){
        data = x;
        next = NULL;
    }
};

Node *insertBegin(Node *head, int data){
    Node *temp = new Node(data);
    temp -> next = head;
    return temp;
}

Node *insertEnd(Node *head, int data){
    if (head == NULL)
        return new Node(data);

    Node *temp = head;
    while (temp -> next != NULL){
        temp = temp -> next;
    }

    temp->next = new Node(data);
    return head;
}

void printLL(Node *head){
    cout<<"printLL() ";
    while (head != NULL){
        cout<< head->data <<" ";
        head = head -> next;
    }
    cout<<endl;
}


Node *reverseGroupsRecursive(Node *head, int k){
    // If k <= no. of nodes in LL then kth node will be the head of the LL
    // If k > length of LL then after the first pass whatever 
    // is the last node of LL you processed will be the head

    Node *curr = head, *next = NULL, *prev = NULL;
    int count = 0;

    while (curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    if (next != NULL)
        head->next = reverseGroupsRecursive(next, k);

    return prev;
}


// Input:  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
//         k = 3

// Output: 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 8 -> 7 -> NULL

// Reverse even if the nodes are not upto K at the last


int main(){

    Node *head = NULL;

    for (int i = 1; i <= 7+1; i++)
        head = insertEnd(head, i*10);
    
    int k = 3;                               // Reverse in k groups

    cout<<"Our linked list is ";
    printLL(head);

    cout<<"\nReversing a LL in k groups\n";
    head = reverseGroupsRecursive(head, k);
    printLL(head);

    return 0;
}
