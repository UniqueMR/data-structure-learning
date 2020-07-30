#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//定义二叉树结点
typedef struct _bitree
{
    ElemType data;
    struct _bitree *lchild;
    struct _bitree *rchild;
}bitree;

int main()
{
    printf("Hello world!\n");
    return 0;
}

//传入根结点
int JudgeBitree(bitree *t)
{
    //作为是否为完全二叉树的标记，如果是就为1，否就为0
    //先假设t是完全二叉树
    int tag = 1;

    //根的如果左右子结点都为空，和假设不矛盾，tag不变
    //tag不变并非指tag为1，只是说明在这个结点处没有出现与题设相矛盾的事实，而若在其它点出现与题设相矛盾的事实，tag被置为0，该操作也会原封不动地保留其它位置的判断
    if(t->lchild == 0&&t->rchild == 0);

    //如果左右子结点都不为空，就判断左右子树是否出现单子结点
    else if(t->lchild&&t->rchild)
    {
        tag = JudgeBitree(t->lchild);
        tag = JudgeBitree(t->rchild);
    }

    //如果左右子结点既不都为满，也不都为空，说明该该树不是完全二叉树，和假设矛盾，足以判断给定的二叉树并非完全二叉树
    else
    {
        return 0;
    }

    //最终综合各个结点处的判断，如果始终没有出现与假设相矛盾的地方，那么tag保持为1，如果出现与假设相矛盾的地方，tag就会为0
    return tag;
}
