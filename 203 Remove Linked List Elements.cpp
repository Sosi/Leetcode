ListNode *removeElements(ListNode *head, int val)
{
    ListNode **list = &head;

    while (*list != nullptr)
    {
        if ((*list)->val == val)
        {
            *list = (*list)->next;
        }
        else
        {
            list = &(*list)->next;
        }
    }

    return head;
}
//Original recursive version:

void removeHelper(ListNode *&head, int val)
{
    if (head == nullptr)
    {
        return;
    }
    else if (head->val == val)
    {
        head = head->next;
    }
    else
    {
        removeHelper(head->next, val);
    }
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pseudo_head = new ListNode(0);
        pseudo_head->next = head;
        ListNode *cur = pseudo_head;
        while(cur){
            if(cur->next && cur->next->val == val)   cur->next = cur->next->next;
            else    cur = cur->next;
        }
        return pseudo_head->next;
    }
};
