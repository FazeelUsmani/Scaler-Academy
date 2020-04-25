
Node *reverseLL(Node *head, Node *prev = NULL){

    if (head == NULL)
        return prev;
    Node *next = head -> next;
    head -> next = prev;
    
    return reverseLL(next, head);
}


Node *reverseGroupsRecursive(Node *head, int k){
    // If k <= no. of nodes in LL then kth node will be the head of the LL
    // If k > length of LL then after the first pass whatever 
    // is the last node of LL you processed will be the head

    Node *ptr = head, *prev = head;
    int count = 0;

    while (count < k && ptr != NULL){
        prev = ptr;
        ptr = ptr->next;
        count++;
    }

    if (count == k){
        prev -> next = NULL;
        Node *newHead = reverseLL (head, NULL);
        head -> next = reverseGroupsRecursive(ptr, k);
        return newHead;
    }
    else
    {
        return head;
    }     
}
