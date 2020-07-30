#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

//���ṹ
typedef struct ArcNode
{
    //�û���ָ��Ķ���λ��
    int adjvex;
    //ָ����һ������ָ��
    struct ArcNode *nextares;
}ArcNode;

//����ṹ
typedef struct VNode
{
    //������Ϣ
    int data;
    //ָ�������ö����һ������ָ��
    ArcNode *firstarc;
}VNode,AdjList[MAXSIZE];

//ͼ�ṹ
typedef struct
{
    //�����ڽӱ�
    AdjList verties;
    //��������
    int vexnum;
    //������
    int arcnum;
}ALGraph;

//�����ڽӱ�a���������i�������յ�j����������visit
//����ҵ�·��������1��û�ҵ�������0
//��������ͼ���ڽӱ�ӳ������ȵ���������������ȿ����������Ľ����Ȼ��·��
int DfsSearch(ALGraph a,int i,int j,int *visit)
{
    //����������յ㣬���ҵ�·��������1
    if(i == j)
    {
        return 1;
    }

    //��㲻�����յ�
    else
    {
        //��i��Ԫ���Ѿ�����
        visit[i] = 1;

        ArcNode *p;

        //pΪ���ĵ�һ���ڽӵ�
        p = a.verties[i].firstarc;

        //��p����ʱ
        while(p)
        {
            //����i
            i = p->adjvex;
            //����ڽӵ�û�б����ʣ����������������ڽӵ�����Ӧ�����
            if(!visit[i])
                DfsSearch(a,i,j,visit);
            //�������������ɺ�pָ����һ���ڽӵ�
            p = p->nextares;
        }

        //����������������ɺ���Ȼû���ҵ�vj��˵��û���ҵ�vi��vj��·��������0
        return 0;
    }
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
