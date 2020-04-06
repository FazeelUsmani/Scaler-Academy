#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


vector< int > postOrder(Node *root) 
{     
    stack < Node *> s;
    vector<int> ans;
    s.push(root);    

    while ( !s.empty() ){

        Node *x = s.top();
        s.pop();      
        
        if (x -> left != NULL)
            s.push(x -> left);

        if (x -> right != NULL)
            s.push(x -> right);
        
        ans.push_back(x -> data);

    }

    reverse(ans.begin(), ans.end());

    return ans;
} 


void postOrderRecursive (Node *root){
    if (root == NULL)
        return;

    postOrderRecursive(root->left);
    postOrderRecursive(root->right);    
    cout<<root->data<<" ";
}


int main(){

    Node *a = new Node(10);

    a->left = new Node(20);
    a->right = new Node(30);

    a->left->left = new Node(40);
    a->left->right = new Node(50);

    a->right->left = new Node(60);
    a->right->right = new Node(70);
    
    postOrderRecursive(a);                       // Using Recursion

    cout<<endl;
    vector<int> ans = postOrder(a);              // Using stack

    cout<<"Iterative Solution ";
    for (auto i: ans)
        cout<<i<<" ";


    return 0;
}

