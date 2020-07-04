#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 256;

/*
https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/

**LOGIC:** 
The idea is to use a DLL (Doubly Linked List) to efficiently get the first non-repeating character from a stream. The DLL contains all non-repeating characters in order, i.e., the head of DLL contains first non-repeating character, the second node contains the second non-repeating and so on.
We also maintain two arrays: one array is to maintain characters that are already visited two or more times, we call it repeated[], the other array is an array of pointers to linked list nodes, we call it inDLL[]. The size of both arrays is equal to alphabet size which is typically 256.

Create an empty DLL. Also create two arrays inDLL[] and repeated[] of size 256. inDLL is an array of pointers to DLL nodes. repeated[] is a boolean array, repeated[x] is true if x is repeated two or more times, otherwise false. inDLL[x] contains a pointer to a DLL node if character x is present in DLL, otherwise NULL.
Initialize all entries of inDLL[] as NULL and repeated[] as false.
To get the first non-repeating character, return character at head of DLL.
Following are steps to process a new character ‘x’ in a stream.
If repeated[x] is true, ignore this character (x is already repeated two or more times in the stream)
If repeated[x] is false and inDLL[x] is NULL (x is seen first time). Append x to DLL and store address of new DLL node in inDLL[x].
If repeated[x] is false and inDLL[x] is not NULL (x is seen second time). Get DLL node of x using inDLL[x] and remove the node. Also, mark inDLL[x] as NULL and repeated[x] as true.
Note that appending a new node to DLL is O(1) operation if we maintain tail pointer. Removing a node from DLL is also O(1). So both operations, addition of new character and finding first non-repeating character take O(1) time

*/

struct Node{
    char data;
    Node *next;
    Node *prev;
    Node (char x){
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

void appendNode(Node** head, Node** tail, char val){

    Node* temp = new Node(val);

    if (*head == NULL){
        *head = *tail = temp;
        return;
    }
    (*tail)->next = temp;
    temp->prev = *tail;
    *tail = temp;
}

void removeNode(Node **head, Node **tail, Node  *temp){

    if (*head == NULL)
        return;

    if (*head == temp){
        *head = (*head)->next;
        (*head)->prev = NULL;
        return;
    }
    if (*tail == temp){
        temp->prev->next = NULL;
        return;
    }

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;          

    delete(temp);    
}


char firstNonRepeating(string &s){

    cout<<"start \n";
    string ans;
    struct Node* inDLL[MAX_CHAR] = {NULL};
    bool repeated[MAX_CHAR] = {false};
    
    struct Node *head = NULL, *tail = NULL; 
    
    for (int i = 0; i < s.size(); ++i){

        char x = s[i];

        if (!repeated[x]){
            if (inDLL[x] == NULL){
                appendNode(&head, &tail, x);
                inDLL[x] = tail;                                
            }
            else{
                removeNode(&head, &tail, inDLL[x]);
                inDLL[x] = NULL;
                repeated[x] = true;           
            }
        }
    
        if (head != NULL)
            ans.push_back(head->data);
        else
            ans.push_back('#');        

        cout<<ans<<endl;
    }

    return head->data;
}


int main(){

    string s = "geeksForgeeks";
    char ans = firstNonRepeating(s);
    
    cout<<ans;

    return 0;    
}
