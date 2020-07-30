#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

void ListReverse(LinkList &L)//单链表的逆置
{
    LinkList p,q;

    p = L;
    p = p->next;
    L->next = NULL;

    while(p)
    {
        q = p;//q后退一个结点
        p = p->next;//p为q的后继
        q->next = L->next;//此时L->next指向q前面的结点，因而此步骤可以使得q指向前一个结点
        L->next = q;//更新L->next指向q,在q后移一个结点后，L->next可以再次指向q前面的结点
    }//
}
