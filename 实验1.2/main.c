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
Queue Generate(Queue q,int n);

//���γ��У�������ֶ���q������m�������µ�����m��Ŀ���Ա�ı��
Queue OnceDeQueue(Queue q,int *m,int *e);

int main()
{
    Queue q;
    int m;
    int n;

    q = InitQueue(q);

    //������ɵ�һ������
    m = rand();

    //�����Ա����
//    printf("�����Ա����:\n");
//    scanf("%d",&n);

    n = 4000;

    q = Generate(q,n);

    int e;
    int i;

    //һ�δ�ӡÿһ�ֵĳ��г�Ա���
    for(i = 0;i < n;i++)
    {
        OnceDeQueue(q,&m,&e);
        printf("%d ",e);
    }

    return 0;
}
