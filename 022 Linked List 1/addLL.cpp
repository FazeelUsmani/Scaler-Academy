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

Node* addSameSize(Node* head1, Node* head2, int* carry){

    if (head1 == NULL && head2 == NULL)
        return NULL;

    Node *ans = new Node(0);
    ans->next = addSameSize(head1->next, head2->next, carry);
    
    if (ans->next != NULL){    
        ans->data = (head1->data + head2->data + *carry)%10;
        *carry = (head1->data + head2->data + *carry)/10;
    }
    else
    {
        ans->data = (head1->data + head2->data)%10;
        *carry = (head1->data + head2->data)/10;        
    }    

    return ans;
}


int main(){

    Node *head1 = NULL, *head2 = NULL;

    head1 = insertEnd(head1, 9);
    head1 = insertEnd(head1, 8);
    head1 = insertEnd(head1, 9);
    printLL(head1);

    head2 = insertEnd(head2, 4);
    head2 = insertEnd(head2, 5);
    head2 = insertEnd(head2, 6);
    printLL(head2);
    
    int carry = 0;
    Node *res = addSameSize(head1, head2, &carry);
    printLL(res);
        


    return 0;
}
