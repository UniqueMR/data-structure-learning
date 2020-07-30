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

//��ÿһ��Ԫ��ֵΪx�Ľ�㣬ɾ������Ϊ�������������ͷ���Ӧ�Ŀռ�
bitree DeleteX(bitree t,ElemType x)
{
    //ָ��t�ĸ����
    bitree pre;

    //�ݹ���ڣ����t�ǿս�㣬����0
    if(!t)
    {
        return 0;
    }

    //���ͷ�������������x����ô��������ɾ��
    if(t->data == x)
    {
        free(t);
    }

    pre = t;
    //tָ��ԭ��t���������ĸ�
    t = pre->lchild;

    //������������x���ͽ�t��㸸������ָ���ָ��ͬʱ�ͷŸý��
    if(t->data == x)
    {
        pre->lchild = NULL;
        free(t);
    }

    //����ͽ���tΪ�������������и�������Ϊx������ɾ��
    //���ڴ�ʱt->data != x�����Կ϶��������t->data == x��Ҳ����t->data == xֻ��������������ͷ���͵���x�����
    else
    {
        t = DeleteX(t,x);
    }

    //ͬ��
    t = pre->rchild;
    if(t->data == x)
    {
        pre->rchild = NULL;
        free(t);
    }

    else
    {
        t = DeleteX(t,x);
    }

    return pre;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
