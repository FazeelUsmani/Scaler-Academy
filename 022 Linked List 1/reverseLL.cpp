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

void printMiddle(Node *head){
    if (head == NULL)
        return;
       
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"Middle element in a LL is "<<slow -> data<<endl;;
}

Node *reverseLL(Node *head){
    vector<int> arr;
    for (Node *curr = head; curr != NULL; curr = curr->next)
        arr.push_back(curr->data);

    for (Node *curr = head; curr != NULL; curr = curr->next){
        curr->data = arr.back();
        arr.pop_back();
    }

    return head;
}

Node *reverseLL1(Node *head){

    if (head == NULL)   return head;

    Node *prev = NULL, *curr = head, *next;

    while (curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}


Node *reverseLL2(Node *head){

    if (head == NULL)
        return NULL;

    if (head->next == NULL)
        return head;
    
    Node *ans = reverseLL2(head->next);
    head->next->next = head;
    head->next = NULL;
    return ans;
}

Node *reverseLL3(Node *head, Node *prev){

    if (head == NULL)
        return prev;
        
    Node *next = head -> next;
    head->next = prev;
    prev = head;

    return reverseLL3(next, prev);     // return reverseLL3(next, head) Can we write this instead?
}


int main(){

    Node *head = NULL;

    for (int i = 1; i <= 5; i++)
        head = insertEnd(head, i);
    
    cout<<"Our linked list is ";
    printLL(head);

    cout<<"\nReverse of LL using changing of data \n";
    head = reverseLL(head);

    printLL(head);

    cout<<"\nReverse of LL by changing links (Iterative) \n";
    head = reverseLL1(head);
    printLL(head);

    cout<<"\nReverse of LL by changing links (Recursive - I) \n";
    head = reverseLL2(head);
    printLL(head);

    cout<<"\nReverse of LL by changing links (Recursive - II) {**Tail Recursion} \n";
    head = reverseLL3(head, NULL);           // Passing prev ptr as NULL
    printLL(head);


    return 0;
}
