int sumLeaf(Node* root)
{
    if (root == NULL)
        return 0;
    
    if (root->left == NULL && root->right == NULL)
        return root->data;
    
    return sumLeaf(root->left) + sumLeaf(root->right);
}
