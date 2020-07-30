#include <stdio.h>
#include <stdlib.h>

#define DATASIZE 100

//定义Data数据类型，包括字符以及相应字符的权值
typedef struct
{
    char character;
    int weight;
}Data;

//定义数据顺序表数据类型
typedef struct
{
    Data data[DATASIZE];
    int size;
}DataList;

//定义队列数据类型
typedef struct
{
    Data data[DATASIZE + 1];
    int i;
    int j;
    int size;
}Queue;

//队列初始化操作
void InitQueue(Queue q)
{
    q.i = 0;
    q.j = 0;
    q.size = 0;
}

//排序操作
Queue Rank(Queue q)
{
    int k;

    for(k = 2;k <= q.size;k++)
    {
        q.data[0] = q.data[k];

        int high;
        int low;
        int mid;

        low = 1;
        high = k - 1;

        while(low <= high)
        {
            mid = (low + high) / 2;

            if(q.data[0].weight <= q.data[mid].weight)
            {
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }

        int m;

        for(m = k - 1;m >= high + 1;m--)
        {
            q.data[m + 1] = q.data[m];
        }

        q.data[high + 1] = q.data[0];
    }

    q.i = 1;
    q.j = q.size;

    return q;
}

int main()
{
    Queue q;

    InitQueue(q);

    int i;

    q.size = 8;

    for(i = 1;i < 9;i++)
    {
        printf("Enter weight\n");
        scanf("%d",&q.data[i].weight);
    }

    q = Rank(q);

    printf("%d",q.data[2].weight);

    return 0;
}
