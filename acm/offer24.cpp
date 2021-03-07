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
    ListNode* reverseList(ListNode* head) {
        ListNode *ans = NULL;
        ListNode *temp = NULL;
        if(head == NULL){
            return ans;
        } else if(head->next == NULL){
            return head;
        } else{
            while(head != NULL){
                temp = head;
                head = head->next;
                temp->next = ans;
                ans = temp;
            }
            return ans;
        }
    }
};
