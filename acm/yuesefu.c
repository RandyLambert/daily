#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int n,m;
int d[100000];
int ci = 0;
typedef struct node{
    int shu;
    struct node *next;
}node;

void create(node **head,int n){
    node *p1,*p2;
    *head = (node*)malloc(sizeof(node));
    (*head)->shu = 1;
    p1 = *head;
    for(int i = 2;i <= n;i ++){
        p2 = (node*)malloc(sizeof(node));
        p2->shu = i;
        p1->next = p2;
        p1 = p2;
    }
    p1->next = *head;
    /* return head; */
}

void print(node *head){
    node *p1 = head->next;
        printf("%5d",p1->shu);
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
    node *p1 = head;
    node *p2;
    int i = 1;
    while(kong(p1)){
        if(i%m == m-1){
            p2 = p1->next;
            i++;
            d[ci++] = p1->next->shu;
            p1->next = p1->next->next;
            free(p2);
            /* printf("%d\n",d[ci]); */
        }
        else{
            p1=p1->next;
            i++;
        }
    }
    d[ci++] = p1->shu;
}
int main(){
    node *head;
    int y;
    printf("请输入约瑟夫环的长度：");
    scanf("%d",&y);
    create(&head,y);
    /* print(head); */
    int x;
    printf("请输入循环节大小：");
    scanf("%d",&x);
    shanchu(head,x);
    printf("删除顺序为：");
    if(y == 0 && x == 0){
        exit(0);
    }
    for(int i = 0;i < ci;i++){
        printf("%d ",d[i]);
    }
    return 0;
}
