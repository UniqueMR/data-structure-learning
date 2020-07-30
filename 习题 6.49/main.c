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

//�ж��Ƿ�Ϊ��ȫ������
int JudgeBitree(bitree t)
{
    int d;

    if(t)
    {
        //�õ�����������ȵĲ�ֵ
        d = Depth(t->lchild) - Depth(t->rchild);
        //�����������ȱ�������С��������������ȱ����������С1���ϣ�˵���ͼ���ì��
        if(d < 0 || d > 1)    return 0;
        //��������ֱ��ж���������
        else
        {
            //�������������û��������ì�ܵ���ʵ������1
            if(JudgeBitree(t->lchild)&&JudgeBitree(t->rchild))    return 1;
            //���򷵻�0
            else    return 0;
        }
    }
    //����û����0�����أ��ͷ���1
    return 1;

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
