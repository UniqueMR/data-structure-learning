#include <stdio.h>
#include <stdlib.h>

//定义元素类型
typedef struct
{
    //元素关键字
    int data;
    //suml和sumg分别统计比该元素大的元素的数目，和比该元素小的元素的数目
    int suml;
    int sumg;
}Elem;

typedef struct
{
    Elem *elem;
    int length;
}List;

int main()
{
    printf("Hello world!\n");
    return 0;
}

//中值记录函数
Elem MidValue(List L)
{
    int i,j;

    //初始化计数为0
    for(i = 0;i < L.length;i++)
    {
        L.elem[i].sumg = 0;
        L.elem[i].suml = 0;
    }

    //遍历序列
    for(i = 0;i < L.length - 1;i++)
    {
        for(j = i + 1;j < L.length;j++)
        {
            if(L.elem[i].data < L.elem[j].data)
            {
                //找到一个比i大的，找到一个比j小的
                L.elem[i].sumg++;
                L.elem[j].suml++;
            }
            else
            {
                //找到一个比i小的，找到一个比j大的
                L.elem[i].suml++;
                L.elem[j].sumg++;
            }
        }
        //由于对每一个元素，都和前面的元素比较过，也和后面的元素比较过，因此可以做到不重不漏
    }

    int k;

    for(i = 0;i < L.length;i++)
    {
        //k为比i大的和比i小元素数目的差值
        k = (L.elem[i].sumg > L.elem[i].suml)?(L.elem[i].sumg - L.elem[i].suml):(L.elem[i].suml - L.elem[i].sumg);

        //如果差值为0（元素共有奇数个）或者差值为1（元素共有偶数个），就返回相应的结点
        if(k == 0||k == 1)
            return L.elem[i];
    }
    return;
}
