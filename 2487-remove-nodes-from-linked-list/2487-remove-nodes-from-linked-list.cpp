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
class Solution {
public:
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *reversed = reverseList(head);
        ListNode *prev = reversed;
        ListNode *curr = reversed->next;
        if (curr == NULL){
            return head;
        }
        int curr_max = prev->val;
        while (curr != NULL){
            if (curr->val < curr_max){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                curr_max = curr->val;
                prev = curr;
                curr = curr->next;
            }
        }
        return reverseList(reversed);
    }
    ListNode *reverseList(ListNode *head){
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL){
            ListNode *next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;  
    }
};