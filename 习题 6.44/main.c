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

//���������������
int Depth(bitree t)
{
    int depth;
    int depthLeft,depthRight;

    //�ݹ����
    if(!t)    depth = 0;
    //����������ȵ����ֵ+1
    else
    {
        depthLeft = Depth(t->lchild);
        depthRight = Depth(t->rchild);
        depth = 1 + (depthLeft > depthRight ? depthLeft: depthRight);
    }

    return depth;
}

//�����������Ԫ��ֵΪx�Ľ��Ϊ�������������
//����Ԫ��Ϊx�Ľ��Ψһ
int DepthX(bitree t,ElemType x)
{
    //������Ϊ�գ�����0
    if(!t)    return 0;
    //�ݹ���ڣ��ҵ�Ԫ��ֵΪx�Ľ�㣬�����Ըý��Ϊͷ�������
    if(t->data == x)
    {
        return Depth(t);
    }
    else
    {
        //��Ԫ��Ϊx�Ľ��Ψһ��ʱ�򣬲��ҵ���x��㡱�ķ�֧�᷵��һ������0��ֵ��û�в��ҵ��ķ�֧�᷵��0
        //���ظ���ķ���ֵ�����Ƿ��ز��ҵ���x��㡱�ķ�֧�ķ���ֵ
        //�����û�в��ҵ���x��㡱�����ջ᷵��0
        return (DepthX(t->lchild,x) > DepthX(t->rchild,x))?DepthX(t->lchild,x):DepthX(t->rchild,x);
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
