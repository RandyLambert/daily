#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *reverse( struct ListNode *head );
void printlist( struct ListNode *head )
{
     struct ListNode *p = head;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode  *head;

    head = createlist();
    head = reverse(head);
    printlist(head);
	
    return 0;
}
struct ListNode *reverse( struct ListNode *head ){
    struct ListNode *head1;
    struct ListNode *p2;
    head = head->next;
    while(head!=NULL){
        struct ListNode *s = (struct ListNode *)malloc(sizeof(struct ListNode));
        s->data = head->data;
        p2 = head1->next;
        head1->next = s;
        head1->next->next = p2;
        head = head->next;
    }
    return head1;
}
