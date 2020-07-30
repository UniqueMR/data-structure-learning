#include <stdio.h>
#include <stdlib.h>

struct SNode
{
    char data;
    struct SNode next;
};

typedef struct SNode* Stack;

int TrueOrFaluse(Stack S);

void Push(Stack s,char x);

int Pop(Stack s);

int main()
{
    printf("Hello world!\n");
    return 0;
}

void TrueOrFaluse(char *str)
{
    Stack s;
    char *p;
    //创建一个空堆栈
    s = (Stack)malloc(sizeof(struct SNode));
    s->next = NULL;

    //利用指针p遍历字符串
    P = str;

    while(*(p + 1) != '\0')
    {
        //如果是正括号，则压入，检索指针后移
        if(*p=='('||*p=='['||*p=='{')
        {
            Push(s,*p);
            p++;
        }
        //如果是反括号，则检查是否配对
        else if(*p==')')
        {
            //如果配对，则将已经配对的清除，检索指针后移
            if(*s->next->data == '(')
            {
                Pop(s);
                p++;
            }
            //如果不配对，则输出结果为错误
            else
            {
                printf("error!");
                break;
            }
        }
        //同理
        else if(*p==']')
        {
            if(*s->next->data == '[')
            {
                Pop(s);
                p++;
            }
            else
            {
                printf("error!");
                break;
            }
        }
        //同理
        else if(*p=='}')
        {
            if(*s->next->data == '{')
            {
                Pop(s);
                p++;
            }
            else
            {
                printf("error!");
                break;
            }
        }
        //如果是其它字符，检索指针后移
        else    p++;
    }

    if(s->next == NULL)    printf("right!");//最终堆栈为空（所有的都配对）说明配对正确
    else    printf("error!");//否则配对错误
}

void Push(Stack s,char x)//将元素x压入堆栈
{
    Stack p;
    p = (Stack)malloc(sizeof(struct SNode));
    p->data = x;
    p->next = s->next;
    s->next =p;
}

int Pop(Stack s)//将元素从堆栈中取出，返回给x
{
    int x;

    Stack p;
    p = s->next;
    x = *p;
    s->next = p->next;
    return x;
    free(p);
}
