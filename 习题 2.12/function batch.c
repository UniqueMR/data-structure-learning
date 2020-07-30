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
//找到initA,initB去除最大共同前缀后的字串，并用传指针的方式返回到ultA,ultB中
{
    int i,j;
    int temp;

    for(i = 0;i<=initA->length&&i<=initB->length;i++)//找到initA和initB的最大共同前缀
    {
        if(initA->data[i] != initB->data[i])
        {
            break;
        }
    }

    temp = i;//保存最大共同前缀结束的位置

    j = 0;

    while(i<=initA->length&&i<=initB->length)//将initA,initB最大共同前缀后面的数据拷贝到ultA,ultB中
    {
        ultA->data[j] = initA->data[i];
        ultB->data[j] = initB->data[i];
        j++;
        i++;
    }

    if(initA->length <= initB->length)//如果A更短，则继续拷贝B
    {
        while(i<=initB->length)
        {
            ultB->data[j] = initB->data[i];
            j++;
            i++;
        }
    }
    else//否则继续拷贝A
    {
        while(i<=initA->length)
        {
            ultA->data[j] = initA->data[i];
            j++;
            i++;
        }
    }
//更新ultA,ultB的长度
    ultA->length = initA->length - temp;
    ultB->length = initB->length - temp;
}

void Compare(LinearList A,LinearList B)//依据规则比较A’,B’的大小
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

