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

//判断给定的二叉树t是否为二叉排序树。若是返回1，不是返回0
int Judge(bitree t)
{
    //先假定给定的二叉树是二叉排序树
    int key = 1;

    //递归出口
    if(!t)
        return;

    else
    {
        //如果左子结点的数据小于等于根结点的数据，就继续对左子树进行判断
        if(t->lchild->data <= t->data)
            Judge(t->lchild);

        //否则和假设矛盾，改key为0，并退出递归
        else
        {
            key = 0;
            return key;
        }

        //如果右子结点的数据大于等于根结点的数据，就继续对右子树进行判断
        if(t->rchild->data >= t->data)
            Judge(t->rchild);

        //否则和假设矛盾，改key为0，并退出递归
        else
        {
            key = 0;
            return key;
        }
    }

    //返回判断值
    return key;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
