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
    //Node *curr = head;
    // while (curr != NULL){
    //     cout<< curr->data<<" ";
    //     curr = curr -> next;
    // }
    // cout<<endl;
    //head->data = 100;  // We can change values of the head but not addresses
    cout<<"printLL() ";
    while (head != NULL){
        cout<< head->data <<" ";
        head = head -> next;
    }
    cout<<endl;
    // No return type, you can use either of the way
}


int main(){

    Node *head = NULL;

    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    head = insertBegin(head, 40);
    printLL(head);

    head = insertEnd(head, 10);
    printLL(head);
    
    while (head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }

    return 0;
}
