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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast,*slow;
        fast = head;
        slow = head;
        while(fast != NULL && k){
            fast = fast->next;
            k--;
        }
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
