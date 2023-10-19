class Solution
{
public:
    ListNode* oddEvenList(ListNode* h)
    {
        if(!h || !h->next)
        return h;
        ListNode *o, *e, *a;
        o = h;
        e = h->next;
        a = e;
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