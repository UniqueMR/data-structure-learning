#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct Node
{
    Elemtype data;
    struct Node *next;
}Node;

typedef struct Node* Linklist;

void listInit(Linklist L)
{
    L->next = NULL;
}

int getElem(Linklist L,int i,Elemtype *e)
{
    int j;
    Linklist p;

    p = L->next;
    j = 1;

    while( p && j<i )
    {
        p = p->next;
        j++;
    }

    if( !p || j>i )
    {
        return 0;
    }

    *e = p->data;

    return 1;
}

int listInsert(Linklist L,int i,Elemtype e)
{
    Linklist p,s;
    int j;

    p = L->next;
    j = 1;

    while( p && j<i )
    {
        p = p->next;
        j++;
    }

    if( !p || j>i )
    {
        return 0;
        exit(1);
    }

    s = (Linklist)malloc(sizeof(Node));

    s->data = e;

    s->next = p->next;
    p->next = s;

    return 1;
}

int listDelete(Linklist L,int i,Elemtype *e)
{
    Linklist p;
    int j;

    p = L->next;
    j = 1;

    while( p && j<i )
    {
        p = p->next;
        j++;
    }

    if( !p || j>i )
    {
        return 0;
    }

    *e = p->next->data;
    p->next = p->next->next;

    free(p->next);

    return 1;
}

int clearList(Linklist L)
{
    Linklist p,q;

    p = L->next;

    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }

    L->next = NULL;

    return 1;
}

int listSwitch(Linklist L,int i,Elemtype e,Elemtype *m)
{
    int j;
    Linklist p;

    p = L->next;
    j = 1;

    while( p && i<j )
    {
        p = p->next;
        j++;
    }

    if( !p || i>j )
    {
        return 0;
    }

    *m = p->next->data;
    p->next->data = e;

    return 1;
}

int listSort(Linklist L)
{
    Linklist p;
    Elemtype temp;

    int i,j;

    p = L->next;
    i = j = 1;

    while( p )
    {
        while( p->next )
        {
            if(p->data > p->next->data)
            {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            j++;
        }
        i++;
    }
}

