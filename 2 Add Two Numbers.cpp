/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode preHead(0), * p = &preHead;
        while(l1||l2||carry)
        {
            int val = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            carry = val/10;
            p->next = new ListNode(val%10);
            p = p->next;
            l1 = l1? l1->next:nullptr;
            l2 = l2? l2->next:nullptr;
        }
        return preHead.next;
    }
};

