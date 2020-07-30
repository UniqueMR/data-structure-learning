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

//测量二叉树的深度
int Depth(bitree t)
{
    int depth;
    int depthLeft,depthRight;

    //递归出口
    if(!t)    depth = 0;
    //左右子树深度的最大值+1
    else
    {
        depthLeft = Depth(t->lchild);
        depthRight = Depth(t->rchild);
        depth = 1 + (depthLeft > depthRight ? depthLeft: depthRight);
    }

    return depth;
}

//求二叉树中以元素值为x的结点为根的子树的深度
//假设元素为x的结点唯一
int DepthX(bitree t,ElemType x)
{
    //如果结点为空，返回0
    if(!t)    return 0;
    //递归出口：找到元素值为x的结点，返回以该结点为头结点的深度
    if(t->data == x)
    {
        return Depth(t);
    }
    else
    {
        //当元素为x的结点唯一的时候，查找到“x结点”的分支会返回一个大于0的值，没有查找到的分支会返回0
        //返回更大的返回值，就是返回查找到“x结点”的分支的返回值
        //如果都没有查找到“x结点”，最终会返回0
        return (DepthX(t->lchild,x) > DepthX(t->rchild,x))?DepthX(t->lchild,x):DepthX(t->rchild,x);
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
