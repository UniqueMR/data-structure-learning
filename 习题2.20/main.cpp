#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

void Delete(LinkList &L);

int main()
{
    LNode L;
    LinkList p,head;

    head = &L;
    p = head;
    p = p->next;

    while(getchar()!='\0')
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        printf("%d",p->data);
        p = p->next;
    }

    Delete(head);

    p = head;
    p = p->next;

    while(p)
    {
        printf("%d",p->data);
        p = p->next;
    }
}
