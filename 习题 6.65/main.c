#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//�洢�������к��������е���������
typedef struct
{
    ElemType data[MAXSIZE];
    int low;
    int high;
}sqlist;

//������������
typedef struct _bitree
{
    ElemType data;
    struct _bitree *lchild;
    struct _bitree *rchild;
}bitree;

//���������к��������н��������������ؽ�����ɵĶ�����
bitree* transform(sqlist s1,sqlist s2)
{
    //l1,l2,h1,h2�ֱ������洢s1��s2�ĵ�λ���λ
    int l1,l2,h1,h2;

    //�����λ�͵�λ��ֵ
    l1 = s1.low;
    h1 = s1.high;
    l2 = s2.low;
    h2 = s2.high;

    //p�����������Ľ��
    bitree *p;

    int j;

    //�ݹ���ڣ���λ���ڸ�λ��ʱ��˵��������ɣ������˳�
    if(s1.low > s1.high||s2.low > s2.high)
    {
        return 0;
    }

    else
    {
        p = (bitree*)malloc(sizeof(bitree));
        //�������������ҵ���
        p->data = s1.data[l1];
        //�������������ҵ�����λ��
        for(j = l2;j <= h2;j++)
        {
            if(s2.data[j] == s1.data[l1])
                break;
        }
        //������������Ӧ������
        s2.high = j - 1;
        s2.low = l2;
        //���������еĸ����ҵ���Ӧ���ȵ�һ�Σ���Ӧ������
        s1.low = l1 + 1;
        s1.high = l1 + j - l2;
        //�ҵ���������Ӧ��ͷ���
        p->lchild = transform(s1,s2);
        //���������Ҳ��Ӧ������
        s2.low = j + 1;
        s2.high = h2;
        //�����������Ҳ��ҵ���Ӧ���ȵ�һ�Σ���Ӧ������
        s1.low = l1 + j - l2 + 1;
        s1.high = h1;
        p->rchild = transform(s1,s2);
        return p;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
