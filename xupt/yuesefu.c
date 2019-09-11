#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int n,m;
int d[10];
int ci = 0;
typedef struct node{
    int shu;
    struct node *next;
}node;

void create(node **head,int n){
    node *p1,*p2;
    *head = (node*)malloc(sizeof(node));
    p1 = *head;
    for(int i = 1;i <= n;i ++){
        p2 = (node*)malloc(sizeof(node));
        p2->shu = i;
        p1->next = p2;
        p1 = p2;
    }
    p1->next = *head;
    /* return head; */
}

void print(node *head){
    node *p1 = head;
        printf("%5d",p1->shu);
        p1 = p1->next;
        printf("%5d",p1->next->next->next->shu);
        printf("%5d",p1->next->next->shu);
        printf("%5d",p1->next->shu);

}

bool kong(node *head){
    node *p1 = head;
    if(p1->next == p1){
        return 0;
    }
    else{
        return 1;
    }
}
void shanchu(node *head,int m){
    node *p1 = head->next;
    node *p2;
    while(kong(p1)){
        p2 = p1;
        p1 = p1->next;
        if(p1->shu%m==0){
            d[ci] = p1->shu;
            ci++;
            p2->next = p1->next;
            free(p1);
        }
    }
}
int main(){
    node *head;
    create(&head,10);
    /* print(head); */
    shanchu(head,m);
    for(int i = 0;i < ci;i++){
        printf("%d",d[i]);
    }
    return 0;

}
