#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//������������
typedef struct _bitree
{
    ElemType data;
    struct _bitree *lchild;
    struct _bitree *rchild;
}*bitree;

//�жϸ����Ķ�����t�Ƿ�Ϊ���������������Ƿ���1�����Ƿ���0
int Judge(bitree t)
{
    //�ȼٶ������Ķ������Ƕ���������
    int key = 1;

    //�ݹ����
    if(!t)
        return;

    else
    {
        //������ӽ�������С�ڵ��ڸ��������ݣ��ͼ����������������ж�
        if(t->lchild->data <= t->data)
            Judge(t->lchild);

        //����ͼ���ì�ܣ���keyΪ0�����˳��ݹ�
        else
        {
            key = 0;
            return key;
        }

        //������ӽ������ݴ��ڵ��ڸ��������ݣ��ͼ����������������ж�
        if(t->rchild->data >= t->data)
            Judge(t->rchild);

        //����ͼ���ì�ܣ���keyΪ0�����˳��ݹ�
        else
        {
            key = 0;
            return key;
        }
    }

    //�����ж�ֵ
    return key;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
