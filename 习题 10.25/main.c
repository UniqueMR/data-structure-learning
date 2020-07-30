#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

//�������������ͣ������������ָ����
typedef struct _LNode
{
    Elemtype data;
    struct _LNode *next;
}LNode;

//�����������ͣ���������ͷָ�루���洢��㣩��������
typedef struct
{
    LNode *head;
    int length;
}LinkedList;

//��������в���������������L����������L
LinkedList InsertSort(LinkedList L)
{
    //pָ��ָ����һ����Ҫ�����Ԫ��
    //preָ��ָ���Ѿ���������е�ĩβ��Ҳ����p��ǰһ�����
    //indexָ��������������
    LNode *p,*index,*pre;

    int i;

    int j;

    //������ΪL.length�������Ѿ�������ɣ���־������̽���
    for(i = 1;i <= L.length;i++)
    {
        //��ʼ������ָ��Ϊ��ͷ���
        p = pre = index = L.head;


        //��ǰ��ָ��pre�ƶ����Ѿ���������е�ĩβ
        for(j = 1;j <= i;j++)
        {
            pre = pre->next;
        }

        //pָ����pre�ĺ���һ��λ��
        p = pre->next;

        //�����Ѿ�����õ�ǰ������
        for(j = 1;j <= i;j++)
        {
            //�������Ŀ��Ĺؼ�ֵС�ڼ���ָ��ָ��Ľ�㣬�Ͱ�Ŀ����뵽����ָ��ǰһ��λ��
            if(p->data < index->data)
            {
                //���Ƚ�Ŀ�����ԭ����λ����ɾ��
                pre->next = p->next;
                //Ȼ��Ŀ������뵽����ָ��ָ�����ǰһ��λ��
                p->next = index->next;
                index->next = p;
            }

            //�������ָ��ͼ�������ƶ�
            else
            {
                index = index->next;
            }
        }
    }

    return L;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
