#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        op;
        ListNode *h1=NULL,*h2=NULL,*a1,*a2,*temp = NULL;
        a1 = h1; a2 = h2;
        while(head) {
            if(head->val < x) {
                if(!h1) {
                    temp = head;
                    head = head->next;
                    temp->next = NULL;
                    h1 = temp;
                    a1 = h1;
                }
                else {
                    temp = head;
                    head = head->next;
                    temp->next = NULL;
                    a1->next = temp;
                    a1 = a1->next;
                }
            }
            else {
                if(!h2) {
                    temp = head;
                    head = head->next;
                    temp->next = NULL;
                    h2 = temp;
                    a2 = h2;
                }
                else {
                    temp = head;
                    head = head->next;
                    temp->next = NULL;
                    a2->next = temp;
                    a2 = a2->next;
                }
            }   
        }
        if(!h1) return h2;
        if(!h2) return h1;
        if(a1) a1->next = h2;
        return h1;
    }
};