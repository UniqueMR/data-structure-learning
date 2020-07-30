#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct Node
{
    Elemtype data;
    struct Node *next;
}QNode,*QPtr;

//����βָ��Ͷ��гߴ�������ѭ������
typedef struct
{
    QPtr rear;
    int size;
}*QList;

//ѭ�����еĳ�ʼ��
void InitQList(QList q)
{
    q->rear = NULL;
    q->size = 0;
}

//����еķ���
void EnQList(QList q,Elemtype e)
{
    QPtr p;
    p = (QPtr)malloc(sizeof(QNode));

    //�����ݴ���pָ��Ľ����
    p->data = e;

    //���ѭ��������δ����κ�Ԫ��
    if(q->rear == NULL)
    {//����һ��˫����ѭ�����У���ָ�ң���ָ�㣩
        q->rear = p;
        p->next = q->rear;
    }
    else
    {
        //��ѭ������β�������½��
        p->next = q->rear->next;
        q->rear->next =p;
        //����βָ���λ��
        q->rear = p;
    }
    q->size++;//����󣬶��гߴ�+1
}

void DeQList(QList q,Elemtype *e)
{
    QPtr p;
    //������г���Ϊ0
    if(q->size == 0)
    {
        printf("����Ϊ�գ��޷�����ɾ����");
        exit(1);
    }

    //������г���Ϊ1
    else if(q->size == 1)
    {
        p = q->rear;
        *e = p->data;
        q->rear = NULL;
        free(p);
    }

    //������г��ȴ���1
    else
    {
        //��ѭ�����е�ͷ��ɾ����㣨βָ�����һ��������ͷָ�룩
        p = q->rear->next;
        q->rear->next = p->next;
        *e = p->data;
        free(p);
    }
    q->size--;//ɾ���󣬶��гߴ�-1
}

int main()
{
    printf("Hello world!\n");
    return 0;
}

