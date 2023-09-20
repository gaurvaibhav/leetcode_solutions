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
    ListNode* reverseList(ListNode* head) {
        FASTIO;
        if(!head || !head->next) return head;
        ListNode *newHead = NULL, *headNext = NULL;
        newHead = reverseList(head->next);
        headNext = head->next;
        headNext->next = head;
        head->next = NULL;
        return newHead;
    }
};