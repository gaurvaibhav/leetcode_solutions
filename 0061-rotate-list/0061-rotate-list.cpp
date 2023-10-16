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
private:
    int findLength(ListNode* head)
    {
        int res;
        res = 0;
        while(head)
        {
            head = head->next;
            res++;
        }
        return res;
    }
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(!head) return head;
        ListNode *p, *c, *n;
        int l;
        c = head;
        l = findLength(head);
        if(k % l == 0) return head;
        l -= k % l;
        l--;
        while(l)
        {
            c = c->next;
            l--;
        }
        p = c;
        c = c->next;
        n = c;
        while(n->next) n = n->next;
        n->next = head;
        p->next = NULL;
        return c;
    }
};