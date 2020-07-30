#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int Elemtype;

struct List
{
    Elemtype data[MAXSIZE];
    int length;
}a,b,a1,b1;

typedef struct List* LinearList;

void InitLinearList(LinearList L);

int FindLinearList(LinearList L,Elemtype e);

void InsertLinearList(LinearList L,int i,Elemtype e);

void DeleteLinearList(LinearList L,int i);

void FindSubStr(LinearList initA,LinearList initB,LinearList ultA,LinearList ultB);

int main()
{
    LinearList A,B;
    LinearList A1,B1;

    A = &a;
    B = &b;
    A1 = &a1;
    B1 = &b1;

    int i;

    printf("Enter A elements :\n");

    i = 0;

    while(getchar() != '\n')
    {
        scanf("%d",&A->data[i]);
        A->length++;
        i++;
    }

    printf("Enter B elements:\n");

    i=0;

    while(getchar() != '\n')
    {
        scanf("%d",&B->data[i]);
        B->length++;
        i++;
    }

    FindSubStr(A,B,A1,B1);

    Compare(A1,B1);
}
