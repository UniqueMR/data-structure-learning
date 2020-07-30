#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//存储先序序列和中序序列的数据类型
typedef struct
{
    ElemType data[MAXSIZE];
    int low;
    int high;
}sqlist;

//定义二叉树结点
typedef struct _bitree
{
    ElemType data;
    struct _bitree *lchild;
    struct _bitree *rchild;
}bitree;

//由先序序列和中序序列建立二叉树，返回建立完成的二叉树
bitree* transform(sqlist s1,sqlist s2)
{
    //l1,l2,h1,h2分别用来存储s1和s2的低位与高位
    int l1,l2,h1,h2;

    //保存高位和低位的值
    l1 = s1.low;
    h1 = s1.high;
    l2 = s2.low;
    h2 = s2.high;

    //p用来创建树的结点
    bitree *p;

    int j;

    //递归出口，低位大于高位的时候，说明遍历完成，可以退出
    if(s1.low > s1.high||s2.low > s2.high)
    {
        return 0;
    }

    else
    {
        p = (bitree*)malloc(sizeof(bitree));
        //利用先序序列找到根
        p->data = s1.data[l1];
        //在中序序列中找到根的位置
        for(j = l2;j <= h2;j++)
        {
            if(s2.data[j] == s1.data[l1])
                break;
        }
        //中序序列左侧对应左子树
        s2.high = j - 1;
        s2.low = l2;
        //在先序序列的根后找到对应长度的一段，对应左子树
        s1.low = l1 + 1;
        s1.high = l1 + j - l2;
        //找到左子树对应的头结点
        p->lchild = transform(s1,s2);
        //中序序列右侧对应右子树
        s2.low = j + 1;
        s2.high = h2;
        //在先序序列右侧找到对应长度的一段，对应右子树
        s1.low = l1 + j - l2 + 1;
        s1.high = h1;
        p->rchild = transform(s1,s2);
        return p;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
