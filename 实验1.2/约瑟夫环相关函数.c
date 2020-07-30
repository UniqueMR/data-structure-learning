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
Queue InitQueue(Queue q);

//���в���
Queue EnQueue(Queue q,QPtr p);

//���в��������г�Ա�ı�ŷ��ظ�*e��
Queue DeQueue(Queue q,int *e);

//����Լɪ�򻷣�������к���������
//������ɺ�rearָ�����β����rear����һ�������Ƕ���ͷ��
Queue Generate(Queue q,int n)
{
    int i;
    QPtr p;

    for(i = 1;i <= n;i++)
    {
        p = (QPtr)malloc(sizeof(QNode));
        //��Ա���Ϊi
        p->data.number = i;
        //��Ա����������ɣ���Χ������0~99�ڣ��ɸ���ʵ�������������޸ģ�
        p->data.code = rand();
        q = EnQueue(q,p);
    }
    return q;
}

//���γ��У�������ֶ���q������m�������µ�����m��Ŀ���Ա�ı��
Queue OnceDeQueue(Queue q,int *m,int *e)
{
    QPtr p;
    int i;

    //pָ��ͷ���
    p = q.rear->next;

    //��1��ʼ������ֱ������m
    //���ڶ��о��д�ͷ�����е�Ҫ������βָ��ҲҪ�����ƶ�
    for(i = 1;i < *m;i++)
    {
        q.rear = p;
        p = p->next;
    }

    //�����µ�����m
    *m = p->data.code;

    //��Ӧ��Ա���У����س�Ա���
    //����βָ��rear��p��һ����㣬��˶�Ӧ��Ա���к�βָ��rear����һ��������ԭ��p����һ�����
    q = DeQueue(q,e);

    return q;
}


