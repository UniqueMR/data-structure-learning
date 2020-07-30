#include <stdio.h>
#include <stdlib.h>

struct SNode
{
    char data;
    struct SNode *next;
};

typedef struct SNode* Stack;

char Transform(char *str);

void Push(Stack s,char x);

char Pop(Stack s);

int main()
{
    printf("Hello world!\n");
    return 0;
}

char Transform(char *str)//����׺���ʽת��Ϊ��׺���ʽ
{
    char temp[100];//������ź�׺���ʽ���
    Stack s;//������������������
    char *p;//����������ַ���
    int i;

    s = (Stack)malloc(sizeof(struct SNode));
    s ->next = NULL;

    i = 0;
    p = str;

    while(*p != '\0')
    {
        //����ǳ˳����㣬��ֱ�Ӵ����ջ�����ȼ������ǰ�������ͣ�
        if(*p == '*'||*p == '/')
        {
            Push(s,*p);
            p++;
        }
        //����ǼӼ����㣬��ǰ��ıȽ�
        else if(*p == '+'||*p == '-')
        {   //���ǰ���ǳ˳����ͰѶ�ջ�е������ַ����������ȳ������������ַ�ѹ���ջ
            if(s->next->data == '*'||s->next->data == '/')
            {
                while(s->next != NULL)
                {
                     temp[i] = Pop(s);
                     i++;
                }
                Push(s,*p);
                p++;
            }
            //���ǰ���ǼӼ�����ֱ�Ӵ����ջ
            else
            {
                Push(s,*p);
                p++;
            }
        }
        //�������ĸ������ĸ�����������
        else
        {
            temp[i] = *p;
            i++;
            p++;
        }
    }
    return temp;//�������������׵�ַ
}

void Push(Stack s,char x)//��Ԫ��xѹ���ջ
{
    Stack p;
    p = (Stack)malloc(sizeof(struct SNode));
    p->data = x;
    p->next = s->next;
    s->next =p;
}

char Pop(Stack s)//��Ԫ�شӶ�ջ��ȡ�������ظ�x
{
    char x;
    Stack p;
    p = s->next;
    x = p->data;
    s->next = p->next;
    return x;
    free(p);
}
