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
Queue InitQueue(Queue q);

//入列操作
Queue EnQueue(Queue q,QPtr p);

//出列操作（出列成员的编号返回给*e）
Queue DeQueue(Queue q,int *e);

//创建约瑟夫环，传入队列和人数上限
//创建完成后，rear指向队列尾部，rear的下一个结点就是队列头部
Queue Generate(Queue q,int n)
{
    int i;
    QPtr p;

    for(i = 1;i <= n;i++)
    {
        p = (QPtr)malloc(sizeof(QNode));
        //成员编号为i
        p->data.number = i;
        //成员密码随机生成（范围限制在0~99内，可根据实际问题需求作修改）
        p->data.code = rand();
        q = EnQueue(q,p);
    }
    return q;
}

//单次出列，传入此轮队列q和密码m，传出新的密码m和目标成员的编号
Queue OnceDeQueue(Queue q,int *m,int *e)
{
    QPtr p;
    int i;

    //p指向头结点
    p = q.rear->next;

    //从1开始报数，直到报到m
    //由于队列具有从头部出列的要求，所以尾指针也要跟着移动
    for(i = 1;i < *m;i++)
    {
        q.rear = p;
        p = p->next;
    }

    //重置新的密码m
    *m = p->data.code;

    //对应成员出列，返回成员编号
    //由于尾指针rear在p上一个结点，因此对应成员出列后，尾指针rear的下一个结点就是原来p的下一个结点
    q = DeQueue(q,e);

    return q;
}


