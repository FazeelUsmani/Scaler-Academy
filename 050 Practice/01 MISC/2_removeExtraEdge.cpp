#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


unordered_map <TreeNode *, TreeNode *> umap;

void preOrder(TreeNode *root){
    
    if (root == NULL)
        return;
        
    if (root->left != NULL){
        if (umap.find(root->left) != umap.end()){
            if (umap[root->left]->val > root->val){
                umap[root->left]->right = NULL;
                return;
            }
            else{
                root->left = NULL;
                return;
            }
        }
        else{
            umap[root->left] = root;
        }
        preOrder(root->left);
    }
    
    if (root->right != NULL){
        if (umap.find(root->right) != umap.end()){
            if(umap[root->right]->val > root->val){
                umap[root->right]->left = NULL;
                return;
            }
            else{
                root->right = NULL;
                return;
            }
        }
        else{
            umap[root->right] = root;
        }
        preOrder(root->right);
    }
}

 
TreeNode* solve(TreeNode* A) {
    
    umap.clear();
    preOrder(A);
    
    return A;
}

void printTree(TreeNode *a){

    queue<TreeNode *> q;
    q.push(a);
    while (!q.empty()){
        int sz = q.size();
        for (int i = 0; i < sz; ++i){
            TreeNode *top = q.front();
            q.pop();
            cout<<top->val<<" ";
            if (top->left != NULL)
                q.push(top->left);
            if (top->right != NULL)
                q.push(top->right);
        }
        cout<<endl;
    }
}

int main(){

    TreeNode *a = new TreeNode(1);
    a->left = new TreeNode(3);
    a->right = new TreeNode(2);
    a->left->right = new TreeNode(5);
    a->right->left = a->left->right;
    
    printTree(a);
    TreeNode *b = solve(a);
    cout<<"Tree after removeEdge()\n";
    printTree(a);

    return 0;
}