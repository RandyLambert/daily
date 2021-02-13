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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        if(temp == nullptr)
            return temp;
        while(temp->next != nullptr) {
            if(temp->next->val == temp->val){
                if(temp->next->next != nullptr)
                    temp->next = temp->next->next;
                else 
                    temp->next = nullptr;
            } else {
                if(temp->next != nullptr)
                temp = temp->next;
            }
        }
        return head;
    }
};
