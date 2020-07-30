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

void PrintX(bitree t,int x)
{
    //�ݹ���ڣ������������ڣ����ҽ���������С��x,������ý�������
    //���������Ҳ�����ڣ��Ϳ��˳��ݹ���
    //������������ڣ����������������
    if(!t->rchild)
    {
        if(t->data >= x)
            printf("%d",t->data);

        if(!t->lchild)
            return;

        else
        {
            PrintX(t->lchild,x);
        }
    }

    //������������ڣ��ͼ�������������
    else
    {
        PrintX(t->rchild,x);
        //������������ɺ�����ý���ֵ��С��x����ӡ�ý���ֵ
        if(t->data >= x)
            printf("%d",t->data);

        //���ͬʱ������Ҳ���ڣ��ͼ�������������
        if(t->lchild)
            PrintX(t->lchild,x);
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
