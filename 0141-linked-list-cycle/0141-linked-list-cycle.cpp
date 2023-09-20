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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *i,*j;
        i = j = head;j = j->next;
        while(i != j) {
            if(!j || !j->next) return false;
            i = i->next;
            j = j->next->next;
        }
        return true;
    }
};