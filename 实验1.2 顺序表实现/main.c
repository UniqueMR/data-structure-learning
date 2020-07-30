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

//����Լɪ�򻷣�������к���������
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
    m = rand()%100;
    printf("%d\n",m);

    //�����Ա����
    printf("�����Ա����:\n");
    scanf("%d",&n);

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
