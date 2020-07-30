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

//将二叉树所有结点的左右子树交换
bitree SwitchLR(bitree t)
{
    bitree temp;

    //递归出口：左子树和右子树都为空，返回该结点
    if(t->lchild == 0&&t->rchild == 0)
    {
        return t;
    }

    else
    {
        //先将左右子树的所有结点的左右子树交换
        t->lchild = SwitchLR(t->lchild);
        t->rchild = SwitchLR(t->rchild);
        //再将左右子树交换
        temp = t->lchild;
        t->lchild = t->rchild;
        t->rchild = temp;
        //返回该结点
        return t;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
