#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//定义队列
typedef struct List
{
    ElemType *data;
    int size;
    int front;
    int  rear;
}QList,*Queue;


//初始化循环队列，q是指向队列的指针，k是队列容量大小
void InitQueue(Queue q,int k)
{
    //为队列顺序表的数据域分配k个元素的连续空间
    q->data = (ElemType*)malloc(sizeof(ElemType) * k);
    //初始化顺序表长度为0
    q->size = 0;
    //队列的首尾指针都指向顺序表的起始位置
    q->front = 0;
    q->rear = 0;
}

//定义入队列的操作，传入队列、入队的元素和队列容量
void EnQueue(Queue q,ElemType e,int k)
{
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % k;
    q->size++;
}

//定义出队列的操作，传入队列、接收出队元素的变量和队列容量
void DeQueue(Queue q,ElemType *x,int k)
{
    q->data[q->front] = *x;
    q->front = (q->front + 1) % k;
    q->size--;
}

//求k阶斐波那契数列的第n项
int Fibonacci(int k,int n)
{
    //阶数必须大于等于1
    if(k < 1)
    {
        printf("error!");
        exit(1);
    }

    //创建容量为k的队列
    Queue q;
    InitQueue(q,k);

    ElemType *x,e;

    int i = 0;

    //求斐波那契数列的第n项，结果保存在变量e中
    while(i <= n)
    {
        //前k - 1项为0
        if(i<k - 1)
        {
            EnQueue(q,0,k);
        }
        //第k项为1
        else if(i = k - 1)
        {
            EnQueue(q,1,k);
        }
        else
        {
            int j;
            //对队列中的所有元素求和（所求项前k项的和）得到第i项e
            for(j = 0;j < k;j++)
            {
                e += q->data[j];
            }
            //第i+1项的前k项以前的元素出列
            DeQueue(q,x,k);
            //第i+1项的前一项入列
            EnQueue(q,e,k);
        }
        i++;//下一次求第i+1项
    }
    return e;
}

//求斐波那契数列的前n+1项
void Answer(int k,int n)
{
    int i;
    for(i = 1;i <= n + 1;i++)
    {
        printf("%d\n",Fibonacci(k,i));
    }
}


int main()
{
    int k,n;

    printf("Enter your k and n");
    scanf("%d%d",&k,&n);

    Answer(k,n);
    return 0;
}
