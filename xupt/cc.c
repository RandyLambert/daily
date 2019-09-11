#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char a[4][5];
    scanf("%s",a[1]);
    printf("%ld",strlen(a[1]));
    memset(a,0,sizeof(a));
    printf("\n%ld",strlen(a[1]));


    {
     //   system("clear");
        char ch[10];
        for(int i=0;i<=buf->rowsCount;i++)
        {
            for(int j=0;j<=buf->colsCount;j++)
            {
                if(i==0)
                {
                    printf("%3d",j);
                    continue;
                }
                else if(j==0)
                {
                    printf("%3d",i);
                    continue;
                } 
                /*
                 else if(list->next->data.row==i && list->next->data.column==j)
                 {
                    printf("%c",Seat_UI_Status2Char(list->next->data.status));
                    List_FreeNode(list->next);
                }//用于每次显示一个座位的符号 
                */
                else
                {
                    int flag=0;
                    seat_list_t temp;
                    List_ForEach(list,temp)
                    {
                        if(temp->data.row==i && temp->data.column==j)
                        {
                            flag=1;
                            printf("%3c",Seat_UI_Status2Char(temp->data.status));
                            break;
                        }
                    }
                    if(!flag) printf("  ");//此处没有座位
                }
            }
            putchar('\n');
        } //用于显示座位情况列表
        printf("按任意键退出!\n");
        scanf("%s",ch);
        break;
    }

    return 0;
}
