#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//������Ԫ���±��Լ�ֵ��װ��ΪTriple��������
typedef struct
{
    int i;
    int j;
    ElemType e;
}Triple;

//����ʮ������Ľ�㣬������Ԫ�����͵����ݣ���ָ�����ָ��
typedef struct _TsNode
{
    Triple data;
    struct _TsNode *down;
    struct _TsNode *right;
}TsNode;

//����ʮ������������㣬����mu������nu������Ԫ�ĸ���tu
typedef struct
{
    TsNode e;
    int mu;
    int nu;
    int tu;
}*TsMatrix;

//�������Դ���������Ԫ��
//��Ԫ�飬������飬��������������������Ԫ���ܸ�����ÿ�з���Ԫ�ظ�����ÿ�е�һ������Ԫ������Ԫ���е�λ��
//���Ϊѹ��������Ϣ
typedef struct
{
    Triple data[MAXSIZE];

    //����������
    int mu;
    //����������
    int nu;
    //�����з���Ԫ�صĸ���
    int tu;
}TsMatrixOutput;

//����Ԫ�����ʽ�����ʮ�������ʾ��ϡ������з���Ԫ�ؼ����±���㷨
//tָ��ʮ�������ͷ���
TsMatrixOutput OutputTsMatrix(TsMatrix t)
{
    //�����洢�������Ԫ��
    TsMatrixOutput o;

    //k�������������Ԫ��
    int k = 0;

    TsNode *p;
    TsNode *q;

    //p����������,q����������
    //pָ��ʮ������ÿ�е�ͷ���
    //qָ��ʮ������ÿ�еĵ�һ��Ԫ�ؽ��
    p = t->e.down;
    q = p->right;

    while(p->down != &t->e)
    {
        while(q->right != p)
        {
            o.data[k] = q->data;
            k++;
            q = q->right;
        }
        //pָ��ʮ������ÿ�е�ͷ���
        //qָ��ʮ������ÿ�еĵ�һ��Ԫ�ؽ��
        p = p->down;
        q = p->right;
    }

    //��ɾ�������������������������Ԫ�ܸ����Ľ���
    o.mu = t->mu;
    o.nu = t->nu;
    o.tu = t->tu;
    return o;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
