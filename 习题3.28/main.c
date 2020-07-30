#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct Node
{
    Elemtype data;
    struct Node *next;
}QNode,*QPtr;

//利用尾指针和队列尺寸来构建循环队列
typedef struct
{
    QPtr rear;
    int size;
}*QList;

//循环队列的初始化
void InitQList(QList q)
{
    q->rear = NULL;
    q->size = 0;
}

//入队列的方法
void EnQList(QList q,Elemtype e)
{
    QPtr p;
    p = (QPtr)malloc(sizeof(QNode));

    //将数据存入p指向的结点中
    p->data = e;

    //如果循环队列尚未存放任何元素
    if(q->rear == NULL)
    {//构建一个双结点的循环队列（你指我，我指你）
        q->rear = p;
        p->next = q->rear;
    }
    else
    {
        //从循环队列尾部插入新结点
        p->next = q->rear->next;
        q->rear->next =p;
        //重置尾指针的位置
        q->rear = p;
    }
    q->size++;//插入后，队列尺寸+1
}

void DeQList(QList q,Elemtype *e)
{
    QPtr p;
    //如果队列长度为0
    if(q->size == 0)
    {
        printf("队列为空，无法继续删除！");
        exit(1);
    }

    //如果队列长度为1
    else if(q->size == 1)
    {
        p = q->rear;
        *e = p->data;
        q->rear = NULL;
        free(p);
    }

    //如果队列长度大于1
    else
    {
        //从循环队列的头部删除结点（尾指针的下一个结点就是头指针）
        p = q->rear->next;
        q->rear->next = p->next;
        *e = p->data;
        free(p);
    }
    q->size--;//删除后，队列尺寸-1
}

int main()
{
    printf("Hello world!\n");
    return 0;
}

