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
    ListNode* middleNode(ListNode* head) {
        FASTIO;
        ListNode *s,*f;
        s = head, f = head;
        while(f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
};