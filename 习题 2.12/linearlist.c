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

void InitLinearList(LinearList L)//初始化线性表（建立一个空的线性表）
{
    L = (LinearList)malloc(sizeof(struct List));
    L->length = -1;

    printf("线性表初始化成功！\n");
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
        printf("线性表已满！");
        return;
    }

    if( i < 1 || i > L->length + 2 )
    {
        printf("插入位置非法！");
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
        printf("删除位置不合法！");
        return;
    }

    for( j = i;j <= L->length; j++ )
    {
        L->data[i-1] = L->data[i];
    }

    L->length--;

    return;
}
