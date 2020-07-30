#include <stdio.h>
#include <stdlib.h>

#define StackSize 100

typedef int Elemtype;

typedef struct _TreeNode
{
    Elemtype data;
    struct _TreeNode *lchild;
    struct _TreeNode *rchild;
}TreeNode,*BiTree;

typedef struct _Stack
{
    TreeNode* data[StackSize];
    int rear;
    int size;
}SNode,*Stack;

void InitStack(Stack s)
{
    s->rear = 0;
    s->size = 0;
}

void Push(Stack s,TreeNode* t)
{
    s->data[s->rear] = t;
    s->rear++;
    s->size++;
}

TreeNode* Pop(Stack s)
{
    TreeNode* t;

    t = s->data[s->rear];

    s->rear--;
    s->size--;

    return t;
}

void Search(BiTree t)
{
    BiTree p;

    Stack s;

    s = (Stack)malloc(sizeof(SNode));

    InitStack(s);

    p = t;

    Push(s,p);

    while(s->size != 0)
    {
        while(!p)
        {
            p = p->lchild;
            Push(s,p);
        }
        printf("%d",p->data);

        p = Pop(s);

        p = p->rchild;
    }
}
