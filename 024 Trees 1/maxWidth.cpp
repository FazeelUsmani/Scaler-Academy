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

// TC: O(N)   SC: Θ(N)
int maxWidth(Node *root){   
    
    if ( root == NULL )
        return 0;
    
    queue < Node * > q;
    q.push(root);
    int res = 0;

    while ( !q.empty() ){

        int count = q.size();
        res = max( res, count );

        for (int i = 0; i < count; i++){

            Node *curr = q.front();
            q.pop();

            if ( curr -> left != NULL )
                q.push( curr -> left );
            if ( curr -> right != NULL )
                q.push( curr -> right );
        }
    }
    return res;
}


int main(){

    /*
        Tree is 
            20
            8    12  
        3   5

        Here 3 + 5 = 8
        8 + 12 = 20
        Output is Yes
    */

    // Node *a = new Node(20);

    // a->left = new Node(8);
    // a->right = new Node(12);

    // a->left->left = new Node(3);
    // a->left->right = new Node(5); 

    // bool ans = isBalanced(a);

    // if (ans)
    //     cout<<"YES\n";
    // else
    //     cout<<"NO\n";  

    /* 
    Tree is 
                            10
                    20             30           
             40           50
          60   70     100    120        // Here you can see the maximum width is 4
        80

    */


    Node *a = new Node(10);

    a->left = new Node(20);
    a->right = new Node(30);

    a->left->left = new Node(40);
    a->left->right = new Node(50);

    a->left->left->left = new Node(60);
    a->left->left->right = new Node(70); 
    a->left->right->left = new Node(100);
    a->left->right->right = new Node(120); 

    a->left->left->left->left = new Node(80);

    cout<<"Max width is "<<maxWidth(a);


    return 0;
}    

 



