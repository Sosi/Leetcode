class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if(head==NULL||k==1) return head;
        int num=0;
        ListNode preheader = ListNode(-1);
        preheader.next = head;
        ListNode *cur = &preheader, *nex, *pre = &preheader;
        while(cur = cur->next)
            num++;
        while(num>=k)
        {
            cur = pre->next;
            nex = cur->next;
            for(int i=1; i<k; ++i)
            {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            num-=k;
        }
        return preheader.next;
    }
};


class Solution
{
public:

    ListNode* reverse(ListNode* first, ListNode* last)
    {
        ListNode* prev = last;
        while ( first != last )
        {
            auto tmp = first->next;
            first->next = prev;
            prev = first;
            first = tmp;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        auto node=head;
        for (int i=0; i < k; ++i)
        {
            if ( ! node  )
                return head; // nothing to do list too sort
            node = node->next;
        }
        auto new_head = reverse( head, node);
        head->next = reverseKGroup( node, k);
        return new_head;
    }
};

