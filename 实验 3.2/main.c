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
void Output(Text t,int size);

int main()
{
    Text t;

    t.PageWidth = 80;

    int size;
    int i = 0;

    printf("Enter your text:\n");
    while(getchar() != '\n')
    {
        t.text[i] = (char*)malloc(MAXSIZE*sizeof(char));
        scanf("%s",t.text[i]);
        i++;
    }

    size = i;

    printf("Enter the  page length:\n");
    scanf("%d",&t.PageLength);

    printf("Enter the left margin:\n");
    scanf("%d",&t.LeftMargin);

    printf("Enter the heading length:\n");
    scanf("%d",&t.HeadingLength);

    printf("Enter the footing length:\n");
    scanf("%d",&t.FootingLength);

    printf("Enter the starting number:\n");
    scanf("%d",&t.StartingPageNumber);

    Output(t,size);

    return 0;
}
