#include <stdio.h>
#include <stdlib.h>

//规定数组非零元的最大个数
#define MAXSIZE 100

typedef int ElemType;

//将数据的值和位置进行封装
//理解为完整矩阵信息
typedef struct
{
    int i;
    int j;
    ElemType e;
}Triple;

//三元组，存放区块，总行数，总列数，非零元素总个数，每行非零元素个数，每行第一个非零元素在三元组中的位置
//理解为压缩矩阵信息
typedef struct
{
    Triple data[MAXSIZE];

    //矩阵总行数
    int mu;
    //矩阵总列数
    int nu;
    //矩阵中非零元素的个数
    int tu;
}TsMatrix;


//计算矩阵相加
TsMatrix SumTsMatrix(TsMatrix t1,TsMatrix t2)
{
    TsMatrix t;
    //m，n用来索引输入的两个矩阵t1,t2
    int m = 0,n = 0;
    //k用来索引输出的矩阵
    int k = 0;

    if(t1.mu != t2.mu||t1.nu != t2.nu)
    {
        printf("矩阵等阶才能相加！");
        exit(1);
    }

    else
    {
        while(m < t1.mu&&n < t2.mu)
        {
            //行数不等，则把行数小的压入
            if(t1.data[m].i < t2.data[n].i)
            {
                t.data[k] = t1.data[m];
                //压入元素后，压入三元组和存储三元组的索引各自前移一位
                k++;
                m++;
            }
            //行数相等
            else if(t1.data[m].i == t2.data[n].i)
            {
                //行数相等，但列数不等则将列数小的压入
                if(t1.data[m].j < t2.data[n].j)
                {
                    t.data[k] = t1.data[m];
                    k++;
                    m++;
                }
                else if(t1.data[m].j > t2.data[n].j)
                {
                    t.data[k] = t2.data[n];
                    k++;
                    n++;
                }
                //行数相等，列数也相等，就把元素值相加，复制位置，三个三元组索引前移
                else
                {
                    t.data[k].e = t1.data[m].e + t2.data[n].e;
                    t.data[k].i = t1.data[m].i;
                    t.data[k].j = t1.data[m].j;
                    k++;
                    m++;
                    n++;

                }
            }
            //行数不等，则把行数小的压入
            else
            {
                t.data[k] = t2.data[n];
                k++;
                n++;
            }
        }

        //添加新三元组的总行数，总列数，总非零元个数
        t.tu = k + 1;
        t.mu = t1.mu;
        t.nu = t1.nu;

        //返回存储相加结果的三元组
        return t;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
