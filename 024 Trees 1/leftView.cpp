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

int maxLevel = 0;

void leftViewRecursive(Node *root, int level){
    // Using PreOrder Traversal - And printing only the first occuring element

    if ( !root )
        return;
    
    if (maxLevel < level){
        cout<<root -> data<<" ";
        maxLevel = level;
    }
    leftViewRecursive(root -> left, level+1);
    leftViewRecursive(root -> right, level+1);
    
}

vector<int> leftViewIterative(Node *root){

    // if (!root)
    //     return NULL;
    queue < Node *> q;
    q.push( root );
    vector<int> ans;

    while ( !q.empty() ){

        int count = q.size();
        for (int i = 0; i < count; i++){
            Node *curr = q.front();
            q.pop();

            if (i == 0)
                ans.push_back(curr->data);
                //cout<<curr -> data<<" ";

            if ( curr -> left != NULL)
                q.push( curr -> left );

            if ( curr -> right != NULL )
                q.push( curr -> right );
        }
    }
    return ans;
}


int main(){

    Node *a = new Node(9);

    a->left = new Node(6);
    a->right = new Node(17);

    a->left->left = new Node(23);
    a->left->right = new Node(7);

    // a->right->left = new Node(60);
    // a->right->right = new Node(70);
    
    cout<<"Left view of tree is\n";     
    cout<<"Recursive Solution ";     
    leftViewRecursive(a, 1);               // Recursive Solution
    cout<<"\nIterative Solution ";     
    vector<int> ans = leftViewIterative(a);                 // Iterative Solution
    cout<<"ANswer is \n";
    for (auto i: ans)
        cout<<i<<" ";
       
    return 0;
}    

 
