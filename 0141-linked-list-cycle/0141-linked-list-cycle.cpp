/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        FASTIO;
        ListNode *i,*j;
        i = j = head;
        while(j && j->next) 
        {
            i = i->next;
            j = j->next->next;
            if(i == j) return true;
        }
        return false;
    }
};