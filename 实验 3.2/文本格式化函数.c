#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10000

//封装得到文本数据类型
typedef struct
{
    char *text[MAXSIZE];
    int PageLength;
    int PageWidth;
    int LeftMargin;
    int HeadingLength;
    int FootingLength;
    int StartingPageNumber;
}Text,*TPtr;

//输出函数
void Output(Text t,int size)
{
    //统计每行的字符数
    int countchar = 0;
    //统计行数
    int countrow = 1;
    //统计页数
    int countpage = t.StartingPageNumber;

    int i,j;

    //每页页顶所空行数
    for(j = 0;j < t.HeadingLength;j++)
    {
        printf("\n");
    }

    //左空白
    for(j = 0;j < t.LeftMargin;j++)
    {
        printf(" ");
    }

    for(i = 0;i < size;i++)
    {
        //计算如果下一次输出继续在同一行，累积字符串长度（含空格）
        countchar += strlen(t.text[i]) + 1;
        //如果累积长度超过要求的最大页宽时，考虑换行还是换页

        //@作为控制字符，指示它后面的正文另起一段，即空一行，并在段首缩入8个字符位置
        //@自成一个字
        if(*t.text[i - 1] == '@')
        {
            printf("\n");
            countrow++;
            if(countrow > t.PageLength)
            {
                //如果要求每页页底所空行数不小于3，则将页号打印在叶底空行中第二行的中间位置
                if(t.FootingLength >= 3)
                {
                    printf("\n");
                    printf("\n");
                    for(j = 0;j < t.PageWidth/2 - 1;j++)
                    {
                        printf(" ");
                    }
                    printf("%d",countpage);
                    countpage++;
                    printf("\n");
                    for(j = 0;j < t.FootingLength - 3;j++)
                    {
                        printf("\n");
                    }
                }
                //否则不印
                else
                {
                    for(j = 0;j < t.FootingLength;j++)
                    {
                        printf("\n");
                    }
                    countpage++;
                }

                //每页页顶所空行数
                for(j = 0;j < t.HeadingLength;j++)
                {
                    printf("\n");
                }

                countrow = 1;
            }
            printf("\n");
            //左空白
            for(j = 0;j < t.LeftMargin;j++)
            {
                printf(" ");
            }
            //段首缩入8个字符位置
            for(j = 0;j < 8;j++)
            {
                printf(" ");
            }
            //重置字符数
            countchar = strlen(t.text[i]) + 8;
            countrow++;
            if(countrow > t.PageLength)
            {
                //如果要求每页页底所空行数不小于3，则将页号打印在叶底空行中第二行的中间位置
                if(t.FootingLength >= 3)
                {
                    printf("\n");
                    printf("\n");
                    for(j = 0;j < t.PageWidth/2 - 1;j++)
                    {
                        printf(" ");
                    }
                    printf("%d",countpage);
                    countpage++;
                    printf("\n");
                    for(j = 0;j < t.FootingLength - 3;j++)
                    {
                        printf("\n");
                    }
                }
                //否则不印
                else
                {
                    for(j = 0;j < t.FootingLength;j++)
                    {
                        printf("\n");
                    }
                    countpage++;
                }

                //每页页顶所空行数
                for(j = 0;j < t.HeadingLength;j++)
                {
                    printf("\n");
                }

                countrow = 1;
            }
        }

        if(countchar > t.PageWidth)
        {
            countrow++;
            //如果行数超过每页规定最大行数，说明需要换页
            if(countrow > t.PageLength)
            {
                //如果要求每页页底所空行数不小于3，则将页号打印在叶底空行中第二行的中间位置
                if(t.FootingLength >= 3)
                {
                    printf("\n");
                    printf("\n");
                    for(j = 0;j < t.PageWidth/2 - 1;j++)
                    {
                        printf(" ");
                    }
                    printf("%d",countpage);
                    countpage++;
                    printf("\n");
                    for(j = 0;j < t.FootingLength - 3;j++)
                    {
                        printf("\n");
                    }
                }
                //否则不印
                else
                {
                    for(j = 0;j < t.FootingLength;j++)
                    {
                        printf("\n");
                    }
                    countpage++;
                }

                //每页页顶所空行数
                for(j = 0;j < t.HeadingLength;j++)
                {
                    printf("\n");
                }

                countrow = 1;
            }

            countchar = strlen(t.text[i]);
            printf("\n");

            //左空白
            for(j = 0;j < t.LeftMargin;j++)
            {
                printf(" ");
            }
        }
        if(*t.text[i] == '@');

        else
        {
            printf("%s",t.text[i]);
        }

        printf(" ");
    }

    if(t.FootingLength >= 3)
    {
        for(i = countrow;i <= t.PageLength;i++)
        {
            printf("\n");
        }

        for(j = 0;j < t.PageWidth/2 - 1;j++)
        {
            printf(" ");
        }
            printf("%d",countpage);
    }
    return;
}


