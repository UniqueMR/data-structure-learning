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

//创建约瑟夫环，传入队列和人数上限
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
    m = rand()%100;
    printf("%d\n",m);

    //输入成员总数
    printf("输入成员总数:\n");
    scanf("%d",&n);

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
