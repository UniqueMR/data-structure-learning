#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//定义二叉树结点
typedef struct _bitree
{
    ElemType data;
    struct _bitree *lchild;
    struct _bitree *rchild;
}*bitree;

ElemType ForValue(bitree t)
{
    if(!t->lchild)
    {
        return NULL;
    }

    else
    {
        if(!t->lchild->rchild)
            return t->lchild->data;

        else
        {
            bitree u;

            u = t->lchild;

            while(!u->rchild)
                u = u->rchild->data;

            return u;
        }
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
