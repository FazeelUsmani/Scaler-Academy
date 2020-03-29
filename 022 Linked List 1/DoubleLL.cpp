#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
    Node (int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};


void printDLL(Node *head){

    while (head!= NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node *insertBegin(Node *head, int data){
    
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    
    cout<<"Inesrtion\n";
    printDLL(temp);
    

    return temp;
}


int main(){

    Node *head = NULL;
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    head = insertBegin(head, 40);
    printDLL(head);

    return 0;
}
