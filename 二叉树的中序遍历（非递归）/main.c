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
    TreeNode data[StackSize];
    int rear;
    int size;
}SNode,*Stack;

void InitStack(Stack s);

Elemtype Search(BiTree t);

int main()
{
    printf("Hello world!\n");
    return 0;
}
