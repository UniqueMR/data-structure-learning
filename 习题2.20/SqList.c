#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

void Delete(LinkList &L)//删除链表中的相同元素
{
    LinkList p,prev,q;
    //prev和p都是指向结点的指针,prev作为p的前驱
    p = L;
    prev = p;
    p = p->next;

    while(p)
    {
        prev = p;
        p = p->next;//prev和p不断向前移动
        if(p&&p->data == prev->data)
        {
            prev->next = p->next;
            q = p;
            p = p->next;
            free(q);
        }//如果prev的数据部和p的数据部相等，则跃过p结点重新连接链表，并释放掉p结点
    }
}
