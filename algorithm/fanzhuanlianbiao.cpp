/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
// nc78
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* first = pHead;
        ListNode* tmp = NULL;
        while(first != NULL){
//             cout<<first->val<<endl;
//             cout<<first->next->val<<endl;
            ListNode *tmp1 = first;
            first = first->next;
            tmp1->next = tmp;
            tmp = tmp1;

        }
        return tmp;
    }
};
