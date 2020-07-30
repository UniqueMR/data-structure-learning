#include <stdio.h>
#include <stdlib.h>

//����ṹ����������person��ÿ��person���͵����ݶ��б��number������code
typedef struct person
{
    int number;
    int code;
}Elemtype;

//����ѭ������������
typedef struct _QNode
{
    Elemtype data;
    struct _QNode *next;
}QNode,*QPtr;

//����ѭ������ÿ��ѭ���������βָ��rear�������Сsize
typedef struct
{
    QPtr rear;
    int size;
}Queue;

//��ʼ��ѭ������
Queue InitQueue(Queue q)
{
    q.rear = NULL;
    q.size = 0;
    return q;
}

//���в���
Queue EnQueue(Queue q,QPtr p)
{
    //���һ��Ԫ�ض�û��
    if(q.size == 0)
    {
        q.rear = p;
    }

    //���ֻ��һ��Ԫ��
    else if(q.size == 1)
    {
        q.rear->next = p;
        p->next = q.rear;
    }

    //�����һ�����ϵ�Ԫ��
    else
    {
        //��β�����в���
        p->next = q.rear->next;
        q.rear->next = p;
        //����βָ��
        q.rear = p;
    }
    q.size++;
    return q;
}

//���в��������г�Ա�ı�ŷ��ظ�*e��
Queue DeQueue(Queue q,int *e)
{
    QPtr p;
    //���ѭ�������Ѿ�Ϊ�վͱ���
    if(q.size == 0)
    {
        printf("ѭ�������Ѿ�Ϊ�գ�");
        exit(1);
    }

    //���ֻʣһ��Ԫ��
    else if(q.size == 1)
    {
        p = q.rear;
        q.rear = p->next;
        q.rear->next = NULL;
        *e = p->data.number;
        free(p);
    }

    //�����ʣһ�����ϵ�Ԫ��
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
