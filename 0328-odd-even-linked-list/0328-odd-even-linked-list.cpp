/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* oddEvenList(ListNode* h)
    {
        if(!h || !h->next || !h->next->next)
        return h;
        ListNode *o, *e, *a;
        o = h;
        a = e = h->next;
        while(o->next && a->next)
        {
            o->next = o->next->next;
            o = o->next;
            a->next = a->next->next;
            a = a->next;
        }
        o->next = e;
        return h;
    }
};