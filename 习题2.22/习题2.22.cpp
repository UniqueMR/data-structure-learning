#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

void ListReverse(LinkList &L)//�����������
{
    LinkList p,q;

    p = L;
    p = p->next;
    L->next = NULL;

    while(p)
    {
        q = p;//q����һ�����
        p = p->next;//pΪq�ĺ��
        q->next = L->next;//��ʱL->nextָ��qǰ��Ľ�㣬����˲������ʹ��qָ��ǰһ�����
        L->next = q;//����L->nextָ��q,��q����һ������L->next�����ٴ�ָ��qǰ��Ľ��
    }//
}
