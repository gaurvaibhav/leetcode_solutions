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
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        FASTIO;
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* p = temp;
        for(int i=1; i<left; ++i) p = p->next;
        ListNode* c = p->next;
        for(int i=1; i<=right-left; ++i) {
            ListNode* f = c->next;
            c->next = f->next;
            f->next = p->next;
            p->next = f;
        }
        return temp->next;
    }
};