#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

void Delete(LinkList &L)//ɾ�������е���ͬԪ��
{
    LinkList p,prev,q;
    //prev��p����ָ�����ָ��,prev��Ϊp��ǰ��
    p = L;
    prev = p;
    p = p->next;

    while(p)
    {
        prev = p;
        p = p->next;//prev��p������ǰ�ƶ�
        if(p&&p->data == prev->data)
        {
            prev->next = p->next;
            q = p;
            p = p->next;
            free(q);
        }//���prev�����ݲ���p�����ݲ���ȣ���Ծ��p������������������ͷŵ�p���
    }
}
