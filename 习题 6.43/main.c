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

//�����������н���������������
bitree SwitchLR(bitree t)
{
    bitree temp;

    //�ݹ���ڣ�����������������Ϊ�գ����ظý��
    if(t->lchild == 0&&t->rchild == 0)
    {
        return t;
    }

    else
    {
        //�Ƚ��������������н���������������
        t->lchild = SwitchLR(t->lchild);
        t->rchild = SwitchLR(t->rchild);
        //�ٽ�������������
        temp = t->lchild;
        t->lchild = t->rchild;
        t->rchild = temp;
        //���ظý��
        return t;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
