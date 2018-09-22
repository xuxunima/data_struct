#include <stdio.h>
 
#define MAXSIZE 1000
 
typedef struct{
    int data[MAXSIZE];
    int top;
}SqStack;
 
int InitStack(SqStack *s)
{
    s->top = -1;
    return 0;
}
 
int Push(SqStack *s, int e)
{
    if(s->top==MAXSIZE)return 1;
    s->top++;
    s->data[s->top]=e;
    return 0;
}
 
int Pop(SqStack *s){
    int e;
    if(s->top==-1)return 1;
    e=s->data[s->top];
    s->top--;
    return e;
}
 
int main()
{
    int m, n, k,i,h;
    SqStack s,t;
    scanf("%d%d%d",&m,&n,&k);
    while(k--){
        InitStack(&s);/*初始化栈s和栈t*/
        InitStack(&t);
        for(i=n-1;i>=0;i--){    /*将给出的序列依次压入栈t中(首元素为栈顶)*/
            scanf("%d",&(t.data[i]));
        }
        t.top=n-1;
        i=0;
        while(i<=n){    /*模拟进栈出栈*/
            if(s.data[s.top]==t.data[t.top]&&s.top!=-1){/*如果s的栈顶元素和t的栈顶元素相同*/
                Pop(&s);
                Pop(&t);
            }else if(s.top<m-1 && i<n){/*如果不相同且s栈未满*/
                i++;
                Push(&s,i);
            }else{  /*以上两种情况都不匹配则说明匹配失败*/
                break;
            }
        }
        if(s.top==-1 && t.top==-1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
 
    }
    return 0;
}