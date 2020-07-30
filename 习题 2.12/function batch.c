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

void FindSubStr(LinearList initA,LinearList initB,LinearList ultA,LinearList ultB)
//�ҵ�initA,initBȥ�����ͬǰ׺����ִ������ô�ָ��ķ�ʽ���ص�ultA,ultB��
{
    int i,j;
    int temp;

    for(i = 0;i<=initA->length&&i<=initB->length;i++)//�ҵ�initA��initB�����ͬǰ׺
    {
        if(initA->data[i] != initB->data[i])
        {
            break;
        }
    }

    temp = i;//�������ͬǰ׺������λ��

    j = 0;

    while(i<=initA->length&&i<=initB->length)//��initA,initB���ͬǰ׺��������ݿ�����ultA,ultB��
    {
        ultA->data[j] = initA->data[i];
        ultB->data[j] = initB->data[i];
        j++;
        i++;
    }

    if(initA->length <= initB->length)//���A���̣����������B
    {
        while(i<=initB->length)
        {
            ultB->data[j] = initB->data[i];
            j++;
            i++;
        }
    }
    else//�����������A
    {
        while(i<=initA->length)
        {
            ultA->data[j] = initA->data[i];
            j++;
            i++;
        }
    }
//����ultA,ultB�ĳ���
    ultA->length = initA->length - temp;
    ultB->length = initB->length - temp;
}

void Compare(LinearList A,LinearList B)//���ݹ���Ƚ�A��,B���Ĵ�С
{
    if(A->length == -1&&B->length == -1)
    {
        printf("A = B");
    }

    else if(A->length == -1&& B->length != -1)
    {
        printf("A < B");
    }

    else if(A->length != -1&& B->length != -1)
    {
        if(A->data[0] < B->data[0])
        {
            printf("A < B");
        }

        else
        {
            printf("A > B");
        }
    }

    else
    {
        printf("A > B");
    }
}

