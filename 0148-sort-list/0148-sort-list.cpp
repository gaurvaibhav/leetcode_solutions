#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution
{
private:
    ListNode* merge(ListNode* l, ListNode* r)
    {
        FASTIO;
        ListNode *dummy = new ListNode(0), *node;
        node = dummy;
        while(l && r)
        {
            if(l->val < r->val)
            {
                node->next = l;
                l = l->next;
            }
            else 
            {
                node->next = r;
                r = r->next;
            }
            node = node->next;
        }
        if(l) node->next = l;
        else node->next = r;
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head)
    {
        FASTIO;
        if(!head || !head->next)
        {
            return head;
        }
        ListNode* f = head->next->next, *s = head;
        while(f && f->next)
        {
            f = f->next->next;
            s = s->next;
        }
        ListNode *r = sortList(s->next);
        s->next = NULL;
        ListNode* l = sortList(head);
        return merge(l, r);
    }
};