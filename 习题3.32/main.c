#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//�������
typedef struct List
{
    ElemType *data;
    int size;
    int front;
    int  rear;
}QList,*Queue;


//��ʼ��ѭ�����У�q��ָ����е�ָ�룬k�Ƕ���������С
void InitQueue(Queue q,int k)
{
    //Ϊ����˳�������������k��Ԫ�ص������ռ�
    q->data = (ElemType*)malloc(sizeof(ElemType) * k);
    //��ʼ��˳�����Ϊ0
    q->size = 0;
    //���е���βָ�붼ָ��˳������ʼλ��
    q->front = 0;
    q->rear = 0;
}

//��������еĲ�����������С���ӵ�Ԫ�غͶ�������
void EnQueue(Queue q,ElemType e,int k)
{
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % k;
    q->size++;
}

//��������еĲ�����������С����ճ���Ԫ�صı����Ͷ�������
void DeQueue(Queue q,ElemType *x,int k)
{
    q->data[q->front] = *x;
    q->front = (q->front + 1) % k;
    q->size--;
}

//��k��쳲��������еĵ�n��
int Fibonacci(int k,int n)
{
    //����������ڵ���1
    if(k < 1)
    {
        printf("error!");
        exit(1);
    }

    //��������Ϊk�Ķ���
    Queue q;
    InitQueue(q,k);

    ElemType *x,e;

    int i = 0;

    //��쳲��������еĵ�n���������ڱ���e��
    while(i <= n)
    {
        //ǰk - 1��Ϊ0
        if(i<k - 1)
        {
            EnQueue(q,0,k);
        }
        //��k��Ϊ1
        else if(i = k - 1)
        {
            EnQueue(q,1,k);
        }
        else
        {
            int j;
            //�Զ����е�����Ԫ����ͣ�������ǰk��ĺͣ��õ���i��e
            for(j = 0;j < k;j++)
            {
                e += q->data[j];
            }
            //��i+1���ǰk����ǰ��Ԫ�س���
            DeQueue(q,x,k);
            //��i+1���ǰһ������
            EnQueue(q,e,k);
        }
        i++;//��һ�����i+1��
    }
    return e;
}

//��쳲��������е�ǰn+1��
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
