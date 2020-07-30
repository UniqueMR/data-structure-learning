#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

//定义结构体数据类型person，每个person类型的数据都有编号number和密码code
typedef struct person
{
    int number;
    int code;
}Elemtype;

//定义队列，以成员为元素，包含头索引，尾索引和现有长度
typedef struct
{
    Elemtype *data;
    int head;
    int rear;
    int size;
}Queue;

//初始化循环队列
Queue InitQueue(Queue q)
{
    q.data = (Elemtype*)malloc(MAXSIZE*sizeof(Elemtype));
    q.head = q.rear = 0;
    q.size = 0;
    return q;
}

//从尾部入列
Queue EnQueue(Queue q,Elemtype e)
{
    //如果队列已满，就退出
    if(q.size == MAXSIZE)
    {
        printf("队列已满！");
        exit(1);
    }

    //如果未满就插入元素，尾索引后移，现现有长度+1
    else
    {
        q.data[q.rear] = e;
        q.rear = (q.rear + 1) % MAXSIZE;
        q.size++;
    }
    return q;
}

//从头部出列
Queue DeQueue(Queue q,int *e)
{
    if(q.size == 0)
    {
        printf("队列已空！");
        exit(1);
    }

    else
    {
        *e = q.data[q.head].number;
        q.head = (q.head + 1) % MAXSIZE;
        q.size--;
    }
    return q;
}

