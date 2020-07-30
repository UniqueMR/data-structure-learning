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

//对每一个元素值为x的结点，删除以它为根的子树，并释放相应的空间
bitree DeleteX(bitree t,ElemType x)
{
    //指向t的父结点
    bitree pre;

    //递归出口：如果t是空结点，返回0
    if(!t)
    {
        return 0;
    }

    //如果头结点的数据域就是x，那么将整个树删除
    if(t->data == x)
    {
        free(t);
    }

    pre = t;
    //t指向原来t的左子树的根
    t = pre->lchild;

    //如果数据域等于x，就将t结点父结点的左指针空指，同时释放该结点
    if(t->data == x)
    {
        pre->lchild = NULL;
        free(t);
    }

    //否则就将以t为根的子树中所有根数据域为x的子树删除
    //由于此时t->data != x，所以肯定不会进入t->data == x，也就是t->data == x只是用来处理树的头结点就等于x的情况
    else
    {
        t = DeleteX(t,x);
    }

    //同理
    t = pre->rchild;
    if(t->data == x)
    {
        pre->rchild = NULL;
        free(t);
    }

    else
    {
        t = DeleteX(t,x);
    }

    return pre;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
