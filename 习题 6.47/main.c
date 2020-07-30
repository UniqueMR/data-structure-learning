#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//������������
typedef struct _bitree
{
    ElemType data;
    struct _bitree *lchild;
    struct _bitree *rchild;
}*bitree;

//����ʽ�ṹ�Ķ��д洢���
//��ʽ���еĽ��
typedef struct _QNode
{
    bitree data;
    struct _QNode* next;
}QNode,*QPtr;

//��ʽ���У���װͷָ���βָ��
typedef struct
{
    QPtr front;
    QPtr rear;
    int size;
}Queue;

//���в���
void EnQueue(Queue q,bitree e)
{
    //����������Ϊ�գ��Ͳ�����
    if(!e)    return;

    QPtr p;

    p = (QPtr)malloc(sizeof(QNode));
    //���ö��н��ָ��洢Ԫ��e
    p->data = e;
    //��β��������
    p->next = q.rear->next;
    q.rear->next = p;
    //����β���
    q.rear = p;
    q.size++;
}

//���в���
bitree DeQueue(Queue q)
{
    QPtr p;

    p = q.front;
    q.front = p->next;
    q.size--;
    return p->data;
    free(p);
}

//��α����㷨
void GradationTraverse(bitree t,ElemType *e)
{
    int i = 0;

    Queue q;
    q.front = NULL;
    q.rear = q.front;
    q.size = 0;

    EnQueue(q,t);

    //�ظ����¹��̣�ֱ������Ϊ��
    while(q.size != 0)
    {
        //t�����Һ������У��������
        //�ڴ�֮ǰ����һ��Ԫ���Ѿ�ȫ������
        EnQueue(q,t->lchild);
        EnQueue(q,t->rchild);
        //����һ����㣬�����ý���ֵ��������e��
        e[i] = DeQueue(q)->data;
        i++;
        //������ָ��ָ����к�Ķ���
        t = q.front->data;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
