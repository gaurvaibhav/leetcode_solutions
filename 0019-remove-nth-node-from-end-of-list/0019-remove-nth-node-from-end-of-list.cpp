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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(!head || !head->next) return NULL;
        ListNode *prev, *curr, *temp;
        curr = head; 
        int k = 1; 
        while(curr)
        {
            if(k == n) {
                prev = head;
            }
            else if(k > n){
                temp = prev;
                prev = prev->next;
            }
            k++;
            curr = curr->next;
        }
        if(prev == head) return head->next;
        temp->next = prev->next;
        delete (prev);
        return head;
    }
};