#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

//弧结构
typedef struct ArcNode
{
    //该弧所指向的顶点位置
    int adjvex;
    //指向下一条弧的指针
    struct ArcNode *nextares;
}ArcNode;

//顶点结构
typedef struct VNode
{
    //顶点信息
    int data;
    //指向依附该顶点第一条弧的指针
    ArcNode *firstarc;
}VNode,AdjList[MAXSIZE];

//图结构
typedef struct
{
    //包含邻接表
    AdjList verties;
    //顶点总数
    int vexnum;
    //弧总数
    int arcnum;
}ALGraph;

//传入邻接表a，搜索起点i，搜索终点j，辅助数组visit
//如果找到路径，返回1，没找到，返回0
//由于有向图的邻接表反映的是入度的情况，因此深度优先可以搜索到的结果必然是路径
int DfsSearch(ALGraph a,int i,int j,int *visit)
{
    //如果起点等于终点，则找到路径，返回1
    if(i == j)
    {
        return 1;
    }

    //起点不等于终点
    else
    {
        //第i个元素已经访问
        visit[i] = 1;

        ArcNode *p;

        //p为起点的第一个邻接点
        p = a.verties[i].firstarc;

        //当p存在时
        while(p)
        {
            //更新i
            i = p->adjvex;
            //如果邻接点没有被访问，则继续深度搜索该邻接点所对应的起点
            if(!visit[i])
                DfsSearch(a,i,j,visit);
            //深度优先搜索完成后，p指向下一个邻接点
            p = p->nextares;
        }

        //如果深度优先搜索完成后依然没有找到vj，说明没有找到vi到vj的路径，返回0
        return 0;
    }
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
