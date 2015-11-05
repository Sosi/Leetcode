ListNode* swapPairs(ListNode* head)
{
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next))
    {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
}

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if(!head) return NULL;

        if(head->next)
        {
            ListNode *temp = head, *nextHead = head->next->next;
            head = head->next;
            head->next = temp;
            head->next->next = swapPairs(nextHead);
        }
        return head;
    }
};

class Solution
{
public:
    void swapNode(ListNode* pre, ListNode *first, ListNode* second)
    {
        pre -> next = second;
        first -> next = second -> next;
        second -> next = first;
    }
    ListNode *swapPairs(ListNode *head)
    {
        ListNode preHead(0);
        preHead.next = head;
        ListNode * pre = &preHead;
        while (pre && pre ->next && pre -> next -> next)
        {
            swapNode(pre, pre -> next, pre -> next -> next);
            pre = pre -> next -> next;
        }
        return preHead.next;
    }
};
