#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//二叉树结点
typedef struct node
{
    ElemType data;
    struct node *left_child,*right_child;
}Node,*Tree;

//创建二叉树
//由于利用了递归，p始终为树的根
Tree BuildTree()
{
    char c;
    Tree p;

    c = getchar();
    if(c == '0')
    {
        return 0;
    }

    else
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = c;
        p->left_child = BuildTree();
        p->right_child = BuildTree();
        return p;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
