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
Queue InitQueue(Queue q);

//从尾部入列
Queue EnQueue(Queue q,Elemtype e);

//从头部出列
Queue DeQueue(Queue q,int *e);

//创建约瑟夫环，传入队列和人数上限
Queue Generate(Queue q,int n)
{
    //如果人数超过上限，则报错
    if(n > MAXSIZE)
    {
        printf("人数超过上限！");
        exit(1);
    }

    else
    {
        Elemtype p;
        int i;

        for(i = 1;i <= n;i++)
        {
            //密码为100以内的随机数
            p.code = rand()%100;
            //编号为i
            p.number = i;
            q = EnQueue(q,p);
        }
    }
    return q;
}

//单次出列，传入此轮队列q和密码m，传出新的密码m和目标成员的编号
Queue OnceDeQueue(Queue q,int *m,int *e)
{
    int i;

    //从1开始报数，直到报到m
    //由于队列具有从头部出列的要求，所以尾指针也要跟着移动
    for(i = 1;i < *m;i++)
    {
        q.head = (q.head + 1) % MAXSIZE;
        q.rear = (q.rear + 1) % MAXSIZE;
    }

     //重置新的密码m
     *m = q.data[q.head].code;

     //对应成员出列，返回成员编号
     q = DeQueue(q,e);

     return q;
}

