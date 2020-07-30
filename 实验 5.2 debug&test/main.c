#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CODESIZE 100

//定义堆栈数据类型
//利用堆栈，依据哈夫曼树对字符进行哈夫曼编码
typedef struct
{
    char HFCode[CODESIZE];
    int rear;
    int size;
}Stack;

//初始化堆栈
Stack InitStack(Stack s)
{
    s.rear = 0;
    s.size = 0;

    return s;
}

//压栈
Stack Push(Stack s,char c)
{
    s.HFCode[s.rear] = c;
    s.rear++;
    s.size++;

    return s;
}

//出栈
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
