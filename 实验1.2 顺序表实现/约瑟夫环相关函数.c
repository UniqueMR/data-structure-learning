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
Queue InitQueue(Queue q);

//��β������
Queue EnQueue(Queue q,Elemtype e);

//��ͷ������
Queue DeQueue(Queue q,int *e);

//����Լɪ�򻷣�������к���������
Queue Generate(Queue q,int n)
{
    //��������������ޣ��򱨴�
    if(n > MAXSIZE)
    {
        printf("�����������ޣ�");
        exit(1);
    }

    else
    {
        Elemtype p;
        int i;

        for(i = 1;i <= n;i++)
        {
            //����Ϊ100���ڵ������
            p.code = rand()%100;
            //���Ϊi
            p.number = i;
            q = EnQueue(q,p);
        }
    }
    return q;
}

//���γ��У�������ֶ���q������m�������µ�����m��Ŀ���Ա�ı��
Queue OnceDeQueue(Queue q,int *m,int *e)
{
    int i;

    //��1��ʼ������ֱ������m
    //���ڶ��о��д�ͷ�����е�Ҫ������βָ��ҲҪ�����ƶ�
    for(i = 1;i < *m;i++)
    {
        q.head = (q.head + 1) % MAXSIZE;
        q.rear = (q.rear + 1) % MAXSIZE;
    }

     //�����µ�����m
     *m = q.data[q.head].code;

     //��Ӧ��Ա���У����س�Ա���
     q = DeQueue(q,e);

     return q;
}

