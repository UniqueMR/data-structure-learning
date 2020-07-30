#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODESIZE 100

//�����ջ��������
//���ö�ջ�����ݹ����������ַ����й���������
typedef struct
{
    char HFCode[CODESIZE];
    int rear;
    int size;
}Stack;

//��ʼ����ջ
Stack InitStack(Stack s)
{
    s.rear = 0;
    s.size = 0;

    return s;
}

//ѹջ
Stack Push(Stack s,char c)
{
    s.HFCode[s.rear] = c;
    s.rear++;
    s.size++;

    return s;
}

//��ջ
char Pop(Stack *s)
{
    s->rear--;
    s->size--;

    return s->HFCode[s->rear];
}


int main()
{
    Stack s;

    s = InitStack(s);

    int i;

    for(i = 0;i < 5;i++)
        s = Push(s,'1');

    for(i = 0;i < 5;i++)
        printf("%c",Pop(&s));

    return 0;
}
