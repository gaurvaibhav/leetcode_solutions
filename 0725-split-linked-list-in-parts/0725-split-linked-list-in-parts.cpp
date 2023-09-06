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
private:
    int nodes(ListNode* head) {
        int n = 0;
        while(head) n++, head=head->next;
        return n;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = nodes(head);
        vector<ListNode* > ans;
        if(k>=n)  {
            while(head) {
                ans.push_back(new ListNode(head->val));
                head=head->next;
            }
            k-=n;
            while(k){
                ans.push_back(NULL);k--;
            }
        }
        else {
            int groups = k, extras = n%k;
            ListNode *aux = head, *mov = head;
            while(groups) {
                for(int temp = 0; temp < n/k-1; temp++) 
                    mov = mov->next;
                ListNode *t = mov;
                if(extras) {
                    t = t->next;
                    mov = mov->next->next;
                    extras--;
                }
                else mov = mov->next;
                t->next = NULL;
                ans.push_back(aux);
                aux = mov;
                groups--;
            }
        }
        return ans;
    }
};