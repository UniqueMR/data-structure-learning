#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

//����ṹ����������person��ÿ��person���͵����ݶ��б��number������code
typedef struct person
{
    int number;
    int code;
}Elemtype;

//������У��Գ�ԱΪԪ�أ�����ͷ������β���������г���
typedef struct
{
    Elemtype *data;
    int head;
    int rear;
    int size;
}Queue;

//��ʼ��ѭ������
Queue InitQueue(Queue q)
{
    q.data = (Elemtype*)malloc(MAXSIZE*sizeof(Elemtype));
    q.head = q.rear = 0;
    q.size = 0;
    return q;
}

//��β������
Queue EnQueue(Queue q,Elemtype e)
{
    //����������������˳�
    if(q.size == MAXSIZE)
    {
        printf("����������");
        exit(1);
    }

    //���δ���Ͳ���Ԫ�أ�β�������ƣ������г���+1
    else
    {
        q.data[q.rear] = e;
        q.rear = (q.rear + 1) % MAXSIZE;
        q.size++;
    }
    return q;
}

//��ͷ������
Queue DeQueue(Queue q,int *e)
{
    if(q.size == 0)
    {
        printf("�����ѿգ�");
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

