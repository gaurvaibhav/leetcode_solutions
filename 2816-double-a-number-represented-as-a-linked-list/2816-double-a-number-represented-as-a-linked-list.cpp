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
#define op ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        op;
        if(head == NULL || head->next == NULL) return head ;
        ListNode *newHead, *headNext ;
        newHead = headNext = NULL ;
        newHead = reverseList(head->next) ;
        headNext = head->next ;
        headNext->next = head ;
        head->next = NULL ;
        return newHead ;
    }
    ListNode* addTwoLists(ListNode* first, ListNode* second)
    {
        op;
        ListNode* ans = NULL;
        ListNode *aux, *prev = NULL;
        int carry = 0, sum;
        while (first != NULL || second != NULL) {
            sum = carry + (first ? first->val : 0) + (second ? second->val : 0);
            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;
            aux = new ListNode(sum);
            if (ans == NULL)
                ans = aux;
            else
                prev->next = aux;
            prev = aux;
            if (first)
                first = first->next;
            if (second)
                second = second->next;
        }
        if (carry > 0)
            aux->next = new ListNode(carry);
        return ans;
    }
    ListNode* doubleIt(ListNode* head) {
        op;
        ListNode* revl = reverseList(head);
        return reverseList(addTwoLists(revl,revl));
    }
};