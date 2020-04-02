void detectRemoveLoop (Node *head){
    Node *slow = head, *fast = head;

    while (!fast && !fast->next){
        slow =slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow != fast)
        return;
    slow = head;
    while (slow->next != fast->next){       // Because we need to remove the loop
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;     // Removing loop by changing the next of last node (*fast ptr) to NULL

}
