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

//判断是否为完全二叉树
int JudgeBitree(bitree t)
{
    int d;

    if(t)
    {
        //得到左右子树深度的差值
        d = Depth(t->lchild) - Depth(t->rchild);
        //如果左子树深度比右子树小，或者右子树深度比左子树深度小1以上，说明和假设矛盾
        if(d < 0 || d > 1)    return 0;
        //否则继续分别判断左右子树
        else
        {
            //如果左右子树都没有与题设矛盾的事实，返回1
            if(JudgeBitree(t->lchild)&&JudgeBitree(t->rchild))    return 1;
            //否则返回0
            else    return 0;
        }
    }
    //最终没有在0处返回，就返回1
    return 1;

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
