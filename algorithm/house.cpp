#include<stdio.h>
#include<stdlib.h>

#define OK      1
#define TRUE    1
#define ERROR   0
#define FALSE   0

#define M 8
#define N 8

    int direction[2][9]={{0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1}};       //增量数组 
    int pow[M][N];
    int check[M][N],next[M][N];         //创建棋盘，初始为0 
struct Element //数据域 
{
    int x,y; //x行,y列
    int d; //下一步的方向
};
typedef struct LStack //链栈
{
    Element data;
    struct LStack *next;
}*PLStack;

typedef struct check //定义棋盘内点的坐标
{
    int x; 
    int y;
}Check;   

/*************栈函数****************/
int InitStack(PLStack &S)//构造空栈
{
    S=NULL;
    return OK;
}
int StackEmpty(PLStack S)//判断栈是否为空
{
    if(S==NULL)
        return OK;
    else
        return FALSE;
}
int Push(PLStack &S, Element e)//元素入栈
{
    PLStack p;
    p=(PLStack)malloc(sizeof(LStack));
    p->data=e;
    p->next=S;
    S=p;
    return OK;
}
int Pop(PLStack &S,Element &e) //元素出栈 
{
    PLStack p;
    if(!StackEmpty(S))
    {
        e=S->data;
        p=S;
        S=S->next;
        free(p);
        return OK;
    }
    else
        return FALSE;
}

/********贪心权值函数********/

void Printf(int p[M][N]){          //打印权值数组 
	for(int i=0;i<M;i++){
	    for(int j=0;j<N;j++)
             printf(" %2d ",p[i][j]);
        printf("\n");
	}
}
void InitWeight(){    //创建权值数组并初始化每个位置的权值 
	for(int i=0;i<M;i++)
	    for(int j=0;j<N;j++)
            pow[i][j]=0;
             
	for(int i=0;i<M;i++){
	    for(int j=0;j<N;j++){
		    for(int dir=1;dir<=8;dir++){
		    	int x1=i+direction[0][dir];
		    	int y1=j+direction[1][dir];
		    	if(x1>=0&&x1<=7&&y1>=0&&y1<=7)
		    	    pow[i][j]++;
			}	        	
		} 
	}
}

void SetWeight(int x,int y) {   //位置（x,y）设置为  被占用  时，修改权值数组 ,被占用时为9 
 	pow[x][y]=9;
 	for(int dir=1;dir<=8;dir++){
 		int x1=x+direction[0][dir];
		int y1=y+direction[1][dir];
		if(x1>=0&&x1<=7&&y1>=0&&y1<=7&&pow[x1][y1]!=9)
		    pow[x1][y1]--;
	 }
 }
 
void UnSetWeight(int x,int y){  //位置（x,y）设置为  未占用  时，修改权值数组
	for(int dir=1;dir<=8;dir++){
 		int x1=x+direction[0][dir];
		int y1=y+direction[1][dir];
		if(x1>=0&&x1<=7&&y1>=0&&y1<=7&&pow[x1][y1]!=9){
			pow[x1][y1]++;
			pow[x][y]++;
		}
		    
} 
}



/*******马踏棋盘函数*******/
int Step(Check start,PLStack &H) {
	Element data;
	int x=start.x-1,y=start.y-1;//将输入位置建议，数组从0，0开始存储 
	int i=1;
	while(i<=64){
     check[x][y]=i;     //将当前步数写入棋盘数组
	 SetWeight(x,y);
     struct Element t,data;
     int pow_min=9;
	 for(int dir=1;dir<=8;dir++){     //探测下一步可走的方向 
	 	int x1=x+direction[0][dir];
		int y1=y+direction[1][dir];
		if(x1>=0&&x1<=7&&y1>=0&&y1<=7&&pow[x1][y1]!=9)
		{
	       if(pow_min>pow[x1][y1])       //找出下一步位置中权值最小的 
	       {
		       pow_min=pow[x1][y1];
	           t.d=dir;  //上一步的方向 
	           t.x=x1;
	           t.y=y1;
	   }
	   }
			   
	 }
	 data.x=x;    //入栈 
	 data.y=y;
	 data.d=t.d;
	 Push(H,data);
	 x=t.x;        //坐标更新 
	 y=t.y;
	 i++;         //步数增加 
	}
	
	return OK;
}

int main(){
     
	for(int i=0;i<M;i++)          //棋盘初始化 
        for(int j=0;j<N;j++){
            check[i][j]=0;       //棋盘 
            next[i][j]=0;     //轨迹棋盘 
	    }        
	InitWeight();     //建立权值棋盘 
	
	PLStack H;
	InitStack(H);   //构造空栈H
	
	Check start;
	printf("请输入起始坐标x y：");
	scanf("%d%d",&start.x,&start.y); 
	
	Step(start,H);
	Printf(check); 
	return 0;
}
