#include <stdio.h>
#include <stdlib.h>

struct SNode
{
    char data;
    struct SNode next;
};

typedef struct SNode* Stack;

int TrueOrFaluse(Stack S);

void Push(Stack s,char x);

int Pop(Stack s);

int main()
{
    printf("Hello world!\n");
    return 0;
}

void TrueOrFaluse(char *str)
{
    Stack s;
    char *p;
    //����һ���ն�ջ
    s = (Stack)malloc(sizeof(struct SNode));
    s->next = NULL;

    //����ָ��p�����ַ���
    P = str;

    while(*(p + 1) != '\0')
    {
        //����������ţ���ѹ�룬����ָ�����
        if(*p=='('||*p=='['||*p=='{')
        {
            Push(s,*p);
            p++;
        }
        //����Ƿ����ţ������Ƿ����
        else if(*p==')')
        {
            //�����ԣ����Ѿ���Ե����������ָ�����
            if(*s->next->data == '(')
            {
                Pop(s);
                p++;
            }
            //�������ԣ���������Ϊ����
            else
            {
                printf("error!");
                break;
            }
        }
        //ͬ��
        else if(*p==']')
        {
            if(*s->next->data == '[')
            {
                Pop(s);
                p++;
            }
            else
            {
                printf("error!");
                break;
            }
        }
        //ͬ��
        else if(*p=='}')
        {
            if(*s->next->data == '{')
            {
                Pop(s);
                p++;
            }
            else
            {
                printf("error!");
                break;
            }
        }
        //����������ַ�������ָ�����
        else    p++;
    }

    if(s->next == NULL)    printf("right!");//���ն�ջΪ�գ����еĶ���ԣ�˵�������ȷ
    else    printf("error!");//������Դ���
}

void Push(Stack s,char x)//��Ԫ��xѹ���ջ
{
    Stack p;
    p = (Stack)malloc(sizeof(struct SNode));
    p->data = x;
    p->next = s->next;
    s->next =p;
}

int Pop(Stack s)//��Ԫ�شӶ�ջ��ȡ�������ظ�x
{
    int x;

    Stack p;
    p = s->next;
    x = *p;
    s->next = p->next;
    return x;
    free(p);
}
