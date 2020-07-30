#include <stdio.h>
#include <stdlib.h>

//定义结构体数据类型person，每个person类型的数据都有编号number和密码code
typedef struct person
{
    int number;
    int code;
}Elemtype;

//定义循环链表结点类型
typedef struct _QNode
{
    Elemtype data;
    struct _QNode *next;
}QNode,*QPtr;

//定义循环链表，每个循环链表包括尾指针rear和链表大小size
typedef struct
{
    QPtr rear;
    int size;
}Queue;

//初始化循环链表
Queue InitQueue(Queue q)
{
    q.rear = NULL;
    q.size = 0;
    return q;
}

//入列操作
Queue EnQueue(Queue q,QPtr p)
{
    //如果一个元素都没有
    if(q.size == 0)
    {
        q.rear = p;
    }

    //如果只有一个元素
    else if(q.size == 1)
    {
        q.rear->next = p;
        p->next = q.rear;
    }

    //如果有一个以上的元素
    else
    {
        //在尾部进行插入
        p->next = q.rear->next;
        q.rear->next = p;
        //更新尾指针
        q.rear = p;
    }
    q.size++;
    return q;
}

//出列操作（出列成员的编号返回给*e）
Queue DeQueue(Queue q,int *e)
{
    QPtr p;
    //如果循环链表已经为空就报错
    if(q.size == 0)
    {
        printf("循环链表已经为空！");
        exit(1);
    }

    //如果只剩一个元素
    else if(q.size == 1)
    {
        p = q.rear;
        q.rear = p->next;
        q.rear->next = NULL;
        *e = p->data.number;
        free(p);
    }

    //如果还剩一个以上的元素
    else
    {
        p = q.rear->next;
        q.rear->next = p->next;
        *e = p->data.number;
        free(p);
    }
    q.size--;
    return q;
}
