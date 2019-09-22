#include <stdio.h>
#include <stdlib.h>
typedef struct List{
    int n;
    struct List* next;
}*list,node;

void headinit(list *head)
{
    (*head) = (list)malloc(sizeof(node));
    (*head)->next = NULL;
}
void nodeadd(list head,int x)
{
    list p1,p2;
    p1 = head;
    while(p1->next!=NULL)
    {
        p1 = p1->next;
    }

    p2 = (list)malloc(sizeof(node));
    p2->n = x;
    p1->next = p2;
    p2->next = NULL;
    
}

void nodeinset(list head,int pos,int x){
    list p1,p2;
    p1 = head;
    for(int i = 0;i <= pos;i++)
    {
        p1=p1->next;
    }
    p2 = (list)malloc(sizeof(node));
    p2->n = x;
    p2->next = p1->next;
    p1->next = p2;
    
}

void print(list head){
    list p1 = head;
    while(p1->next!=NULL)
    {
        p1=p1->next;
        printf("%d\n",p1->n);
    }
}

void listdelete(list head)
{
    list p1 = head,p2;
    while(p1->next!=NULL)
    {
        p2 = p1->next;
        p1->next = p1->next->next;
        free(p2);
    }
}
int main(){

    list head;
    headinit(&head);
    nodeadd(head,10);
    nodeadd(head,10);
    nodeadd(head,10);
    nodeadd(head,10);
    nodeadd(head,10);
    
    print(head);

    listdelete(head);

    print(head);
    
    nodeadd(head,10);
    nodeadd(head,10);
    nodeadd(head,10);
    nodeadd(head,10);
    nodeadd(head,10);
    
    print(head);
    return 0;
}

