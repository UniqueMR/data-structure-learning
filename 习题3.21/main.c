#include <stdio.h>
#include <stdlib.h>

struct SNode
{
    char data;
    struct SNode *next;
};

typedef struct SNode* Stack;

char Transform(char *str);

void Push(Stack s,char x);

char Pop(Stack s);

int main()
{
    printf("Hello world!\n");
    return 0;
}

char Transform(char *str)//将中缀表达式转化为后缀表达式
{
    char temp[100];//用来存放后缀表达式输出
    Stack s;//用来存放四则运算符号
    char *p;//检索输入的字符串
    int i;

    s = (Stack)malloc(sizeof(struct SNode));
    s ->next = NULL;

    i = 0;
    p = str;

    while(*p != '\0')
    {
        //如果是乘除运算，则直接存入堆栈（优先级不会比前面的运算低）
        if(*p == '*'||*p == '/')
        {
            Push(s,*p);
            p++;
        }
        //如果是加减运算，和前面的比较
        else if(*p == '+'||*p == '-')
        {   //如果前面是乘除，就把堆栈中的所有字符输出（后进先出），并将新字符压入堆栈
            if(s->next->data == '*'||s->next->data == '/')
            {
                while(s->next != NULL)
                {
                     temp[i] = Pop(s);
                     i++;
                }
                Push(s,*p);
                p++;
            }
            //如果前面是加减，则直接存入堆栈
            else
            {
                Push(s,*p);
                p++;
            }
        }
        //如果是字母，则将字母存入输出数组
        else
        {
            temp[i] = *p;
            i++;
            p++;
        }
    }
    return temp;//返回输出数组的首地址
}

void Push(Stack s,char x)//将元素x压入堆栈
{
    Stack p;
    p = (Stack)malloc(sizeof(struct SNode));
    p->data = x;
    p->next = s->next;
    s->next =p;
}

char Pop(Stack s)//将元素从堆栈中取出，返回给x
{
    char x;
    Stack p;
    p = s->next;
    x = p->data;
    s->next = p->next;
    return x;
    free(p);
}
