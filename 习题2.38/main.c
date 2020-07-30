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

void LOCATE(LinkedList &L,int x)//�������x��������
{
    LinkedList p,q;

    p = L->next;

    while(p != L&&p->data != x)
        p = p->next;//����������Ϊx�Ľ��

    if(p == L)
    {
        printf("δ�ҵ�������Ϊx�Ľ��");
        return;
    }

    else
    {
        p->freq++;
        p->prior->next = p->next;
        p->next->prior = p->prior;//ɾ�����p

        q = L->next;
        while(q != L&&q->freq > p->freq)//Ѱ�Һ��ʵĲ���λ�ã����ڳ�ʼ��freq��Ϊ0��ÿ�β����󶼽�����ƶ������ʵ�λ�ã���������ɷ���������
            q = q->next;

        p->next = q;
        q->prior->next = p;

        p->prior = q->prior;
        q->prior = p;//������p
    }
}
