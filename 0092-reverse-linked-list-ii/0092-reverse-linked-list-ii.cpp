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
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
private:
    ListNode *revllIter(ListNode *head)
    {
        FASTIO;
        ListNode *p = NULL, *c = NULL, *n = NULL;
        p = NULL;
        c = head;
        while (c != NULL)
        {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        FASTIO;
        if(!head || !head->next || left==right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        ListNode *s=NULL, *e=NULL, *t=head, *p=NULL;
        int k = 0;
        while(t) {
            if(k+1==left) p=t;
            if(k==left) s=t;
            if(k==right) e=t;
            k++;
            t = t->next;
        }
        t = e;
        e = e->next;
        t->next=NULL;
        s=revllIter(s);
        p->next = s;
        while(s->next) s=s->next;
        s->next = e;
        return dummy->next;
    }
};