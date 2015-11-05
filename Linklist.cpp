#include <bits/stdc++.h>
using namespace std;

const int NUM = 5;

class ListNode
{
public:
    int val;
    ListNode * next;
    ListNode(int x): val(x), next(nullptr) {}
    ~ListNode()
    {
        val = 999;
        next = nullptr;
    }
};

ListNode* removeNthFromEnd1(ListNode* head, int n)
{
    ListNode** t1 = &head, *t2 = head;
    for(int i = 1; i < n; ++i)
    {
        t2 = t2->next;
    }
    while(t2->next != NULL)
    {
        t1 = &((*t1)->next);
        t2 = t2->next;
    }
    t2 = *t1;
    *t1 = (*t1)->next;
    delete t2;
    return head;
}

// 多开一个空间, 避免删掉head.
ListNode *removeNthFromEnd2(ListNode *head, int n)
{
    if (!head)
        return nullptr;

    ListNode new_head(-1);
    new_head.next = head;

    ListNode *slow = &new_head, *fast = &new_head;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *to_be_deleted = slow->next;
    slow->next = slow->next->next;

    delete to_be_deleted;
    to_be_deleted = nullptr;

    cout<<to_be_deleted<<endl;

    return new_head.next;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode dummy(INT_MAX);
    dummy.next = head;

    int num = 0;
    ListNode * cur = head, *nxt;
    while(cur)
    {
        num++;
        cur = cur->next;
    }

    ListNode * pre = &dummy;
    while(num >= k)
    {
        cur = pre->next;
        nxt = cur->next;
        for(int i = 1; i< k; i++)
        {
            cur->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
            nxt = cur->next;

        }
        pre = cur;
        num -= k;
    }

    return dummy.next;
}

void check(const vector<ListNode *> & v)
{
    cout<<"-----------------------check begin"<<endl;
    for(int i = 0; i< v.size(); i++)
    {
        cout<<"&& "<<&v[i]<<endl;
        cout<<v[i]<<" "<<v[i]->val<<endl;
        if(v[i] == nullptr) cout<<"INVALID v[i]"<<endl;
        if(i!= v.size() - 1 && v[i]->next == nullptr) cout<<"INVALID v[i] nxt"<<endl;
    }


    cout<<"-----------------------check finished"<<endl;

}

void restore(const vector<ListNode *> & v)
{
        for(int i= 0; i< NUM-1; i++)
        v[i]->next = v[i+1];

}
int main()
{
    vector<ListNode *> v;

    for(int i = 1; i<= NUM; i++)
    {
        v.push_back(new ListNode(i));
    }

    for(int i= 0; i< NUM-1; i++)
        v[i]->next = v[i+1];

    check(v);

    {
        ListNode* x = reverseKGroup(v[0], 2);
        while(x != nullptr)
        {
            cout<<x<<" "<<x->val<<endl;
            x= x->next;
        }

        check(v);
    }
    restore(v);

    {
        ListNode* x = removeNthFromEnd1(v[0], 5);

        cout<<"list=================="<<endl;
//        cout<<x<<" "<<x->val<<endl;

        while(x != nullptr)
        {
            cout<<x<<" "<<x->val<<endl;
            x= x->next;
        }

        check(v);

    }
    restore(v);


//    check(v);
    check(v);
    {
        ListNode* x = removeNthFromEnd2(v[0], 5);

        cout<<"list=================="<<endl;


        while(x != nullptr)
        {
            cout<<x<<" "<<x->val<<endl;
            x= x->next;
        }

        check(v);

    }

}
