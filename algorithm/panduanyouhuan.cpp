/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// nc4
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* quick = head;
        ListNode* slow = head;
        while(quick){
            if(quick == NULL){
                return false;
            }
            quick = quick->next;
            if(quick == NULL){
                return false;
            }
            if(quick == slow){
                return true;
            }
            quick = quick->next;
            slow = slow->next;
        }
        return false;
    }
};
