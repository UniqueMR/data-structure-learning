#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

typedef struct Node
{
    int data;
    struct Node *prior;
    struct Node *next;
    int freq;
}Node,*LinkedList;

void LOCATE(LinkedList &L,int x)//输入结点和x，输出结点
{
    LinkedList p,q;

    p = L->next;

    while(p != L&&p->data != x)
        p = p->next;//查找数据域为x的结点

    if(p == L)
    {
        printf("未找到数据域为x的结点");
        return;
    }

    else
    {
        p->freq++;
        p->prior->next = p->next;
        p->next->prior = p->prior;//删除结点p

        q = L->next;
        while(q != L&&q->freq > p->freq)//寻找合适的插入位置（由于初始化freq均为0，每次操作后都将结点移动到合适的位置，因此链表由非升序排列
            q = q->next;

        p->next = q;
        q->prior->next = p;

        p->prior = q->prior;
        q->prior = p;//插入结点p
    }
}
