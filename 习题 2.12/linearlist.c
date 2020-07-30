#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int Elemtype;

struct List
{
    Elemtype data[MAXSIZE];
    int length;
};

typedef struct List* LinearList;

void InitLinearList(LinearList L)//��ʼ�����Ա�����һ���յ����Ա�
{
    L = (LinearList)malloc(sizeof(struct List));
    L->length = -1;

    printf("���Ա��ʼ���ɹ���\n");
}

int FindLinearList(LinearList L,Elemtype e)
{
    int i = 0;

    while( i <= L->length && L->data[i] != e )
    {
        i++;
    }

    if(i > L->length)
        return -1;

    else
        return i;
}

void InsertLinearList(LinearList L,int i,Elemtype e)
{
    int j;

    if(L->length + 2 >= MAXSIZE)
    {
        printf("���Ա�������");
        return;
    }

    if( i < 1 || i > L->length + 2 )
    {
        printf("����λ�÷Ƿ���");
        return;
    }

    for( j = L->length;j >= i-1;j--)
    {
        L->data[j+1] = L->data[j];
    }

    L->data[i-1] = L->data;

    L->length++;

    return;
}

void DeleteLinearList(LinearList L,int i)
{
    int j;

    if( i < 1 || i > L->length+1 )
    {
        printf("ɾ��λ�ò��Ϸ���");
        return;
    }

    for( j = i;j <= L->length; j++ )
    {
        L->data[i-1] = L->data[i];
    }

    L->length--;

    return;
}
