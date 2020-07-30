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
Queue Generate(Queue q,int n);

//单次出列，传入此轮队列q和密码m，传出新的密码m和目标成员的编号
Queue OnceDeQueue(Queue q,int *m,int *e);

int main()
{
    Queue q;
    int m;
    int n;

    q = InitQueue(q);

    //随机生成第一个密码
    m = rand();

    //输入成员总数
//    printf("输入成员总数:\n");
//    scanf("%d",&n);

    n = 4000;

    q = Generate(q,n);

    int e;
    int i;

    //一次打印每一轮的出列成员编号
    for(i = 0;i < n;i++)
    {
        OnceDeQueue(q,&m,&e);
        printf("%d ",e);
    }

    return 0;
}
