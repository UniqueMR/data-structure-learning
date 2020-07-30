#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//������������
typedef struct _bitree
{
    ElemType data;
    struct _bitree *lchild;
    struct _bitree *rchild;
}bitree;

int main()
{
    printf("Hello world!\n");
    return 0;
}

//��������
int JudgeBitree(bitree *t)
{
    //��Ϊ�Ƿ�Ϊ��ȫ�������ı�ǣ�����Ǿ�Ϊ1�����Ϊ0
    //�ȼ���t����ȫ������
    int tag = 1;

    //������������ӽ�㶼Ϊ�գ��ͼ��費ì�ܣ�tag����
    //tag���䲢��ָtagΪ1��ֻ��˵���������㴦û�г�����������ì�ܵ���ʵ�������������������������ì�ܵ���ʵ��tag����Ϊ0���ò���Ҳ��ԭ�ⲻ���ر�������λ�õ��ж�
    if(t->lchild == 0&&t->rchild == 0);

    //��������ӽ�㶼��Ϊ�գ����ж����������Ƿ���ֵ��ӽ��
    else if(t->lchild&&t->rchild)
    {
        tag = JudgeBitree(t->lchild);
        tag = JudgeBitree(t->rchild);
    }

    //��������ӽ��Ȳ���Ϊ����Ҳ����Ϊ�գ�˵���ø���������ȫ���������ͼ���ì�ܣ������жϸ����Ķ�����������ȫ������
    else
    {
        return 0;
    }

    //�����ۺϸ�����㴦���жϣ����ʼ��û�г����������ì�ܵĵط�����ôtag����Ϊ1����������������ì�ܵĵط���tag�ͻ�Ϊ0
    return tag;
}
