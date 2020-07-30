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

//用链式结构的队列存储结点
//链式队列的结点
typedef struct _QNode
{
    bitree data;
    struct _QNode* next;
}QNode,*QPtr;

//链式队列，封装头指针和尾指针
typedef struct
{
    QPtr front;
    QPtr rear;
    int size;
}Queue;

//入列操作
void EnQueue(Queue q,bitree e)
{
    //如果该树结点为空，就不如列
    if(!e)    return;

    QPtr p;

    p = (QPtr)malloc(sizeof(QNode));
    //利用队列结点指针存储元素e
    p->data = e;
    //从尾部插入结点
    p->next = q.rear->next;
    q.rear->next = p;
    //更新尾结点
    q.rear = p;
    q.size++;
}

//出列操作
bitree DeQueue(Queue q)
{
    QPtr p;

    p = q.front;
    q.front = p->next;
    q.size--;
    return p->data;
    free(p);
}

//层次遍历算法
void GradationTraverse(bitree t,ElemType *e)
{
    int i = 0;

    Queue q;
    q.front = NULL;
    q.rear = q.front;
    q.size = 0;

    EnQueue(q,t);

    //重复以下过程，直到队列为空
    while(q.size != 0)
    {
        //t的左右孩子入列，先左后右
        //在此之前，上一层元素已经全部入列
        EnQueue(q,t->lchild);
        EnQueue(q,t->rchild);
        //出列一个结点，并将该结点的值存入数组e中
        e[i] = DeQueue(q)->data;
        i++;
        //重置树指针指向出列后的队首
        t = q.front->data;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
