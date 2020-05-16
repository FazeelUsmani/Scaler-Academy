
/* Should convert tree to its mirror */
void mirror(Node* node) 
{
    if (node == NULL)
        return;
        
    Node *curr = node;
    stack <Node *> s;
    
    while (!s.empty() || curr != NULL){
        if (curr != NULL){
            s.push (curr);
            curr = curr->right;
        }
        else{
            curr = s.top();
            s.pop();
            cout << curr->data<< " ";
            curr = curr->left;
        }
    }
    
}
