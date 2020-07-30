#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

struct SNode
{
    int data[MAXSIZE];
    int top;
};

typedef struct SNode* Stack;

void test(int *sum);

int main()
{
    printf("Hello world!\n");
    return 0;
}

void test(int *sum)
{
    Stack s;

    s = (Stack)malloc(sizeof(struct SNode));
    s->top = -1;

    int x;

    while(x != 0)
    {
        scanf("%d",&x);
        Push(s,x);
    }

    while(s->top != -1)
    {
        Pop(s,&x);
        *sum += x;
    }

    printf("%d",*sum);
}

void Push(Stack s,int x)
{
    if(s->top == MAXSIZE - 1)
    {
        printf("¶ÑÕ»Âú£¡");
        exit(1);
    }
    else
        s->data[++s->top] = x;
}

void Pop(Stack s,int *x)
{
    if(s->top == -1)
    {
        printf("¶ÑÕ»¿Õ!");
        exit(1);
    }

    else
    {
        *x = s->data[s->top--];
    }
}
