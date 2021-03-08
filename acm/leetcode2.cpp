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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a1 = l1,*a2 = l2;
        int flag = false;
        while(a1 != NULL || a2 != NULL) {
            if(a1 !=NULL && a2 != NULL){
                if(a1->val + a2->val >= 10){
                    if(a1->next != NULL){
                        a1->next->val += (a1->val + a2->val)/10;
                        a1->val = (a1->val + a2->val)%10;
                    } else {
                        ListNode *temp = new ListNode((a1->val + a2->val)/10);
                        a1->val = (a1->val + a2->val)%10;
                        a1->next = temp;
                    } 
                } else {
                    a1->val += a2->val;
                }
                a1 = a1->next;
                a2 = a2->next;
            } else if(a1 != NULL){
                if(a1->val >= 10){
                    if(a1->next != NULL){
                        a1->next->val += a1->val/10;
                        a1->val = a1->val%10;
                    } else {
                        ListNode *temp = new ListNode(a1->val/10);
                        a1->val = a1->val%10;
                        a1->next = temp;
                    } 
                }
                a1 = a1->next;
            } else if(a2 != NULL){
                flag = true;
                if(a2->val >= 10){
                    if(a2->next != NULL){
                        a2->next->val += a2->val/10;
                        a2->val = a2->val%10;
                    } else {
                        ListNode *temp = new ListNode(a2->val/10);
                        a2->val = a2->val%10;
                        a2->next = temp;
                    } 
                }
                a2 = a2->next;
            }
        }
        if(a1 == NULL){
            if(flag == true){
                // cout<<"xx"<<endl;
                ListNode *b1 = l1,*b2 = l2;
                while(b1!=NULL){
                    if(b1->val < 10)
                        b2->val = b1->val;
                    else{
                        if(b2->next != NULL){
                            b2->next->val = b1->val/10;
                            b2->val = b1->val%10;
                        } else {
                            b2->next = new ListNode(b1->val/10);
                            b2->val = b1->val%10;
                        }
                    }
                    b2 = b2->next;
                    b1 = b1->next;
                }
                return l2;
            } else {
                return l1;
            }
        } else{
            return l1;
        }
    }
};
