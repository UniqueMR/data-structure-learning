#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//将非零元的下标以及值封装成为Triple数据类型
typedef struct
{
    int i;
    int j;
    ElemType e;
}Triple;

//创建十字链表的结点，包含三元组类型的数据，下指针和右指针
typedef struct _TsNode
{
    Triple data;
    struct _TsNode *down;
    struct _TsNode *right;
}TsNode;

//创建十字链表，包含结点，行数mu，列数nu，非零元的个数tu
typedef struct
{
    TsNode e;
    int mu;
    int nu;
    int tu;
}*TsMatrix;

//创建用以存放输出的三元组
//三元组，存放区块，总行数，总列数，非零元素总个数，每行非零元素个数，每行第一个非零元素在三元组中的位置
//理解为压缩矩阵信息
typedef struct
{
    Triple data[MAXSIZE];

    //矩阵总行数
    int mu;
    //矩阵总列数
    int nu;
    //矩阵中非零元素的个数
    int tu;
}TsMatrixOutput;

//以三元组的形式输出用十字链表表示的稀疏矩阵中非零元素及其下标的算法
//t指向十字链表的头结点
TsMatrixOutput OutputTsMatrix(TsMatrix t)
{
    //用来存储输出的三元组
    TsMatrixOutput o;

    //k用来索引输出三元组
    int k = 0;

    TsNode *p;
    TsNode *q;

    //p用来遍历行,q用来遍历列
    //p指向十字链表每行的头结点
    //q指向十字链表每行的第一个元素结点
    p = t->e.down;
    q = p->right;

    while(p->down != &t->e)
    {
        while(q->right != p)
        {
            o.data[k] = q->data;
            k++;
            q = q->right;
        }
        //p指向十字链表每行的头结点
        //q指向十字链表每行的第一个元素结点
        p = p->down;
        q = p->right;
    }

    //完成矩阵组总行数，总列数，非零元总个数的交接
    o.mu = t->mu;
    o.nu = t->nu;
    o.tu = t->tu;
    return o;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
