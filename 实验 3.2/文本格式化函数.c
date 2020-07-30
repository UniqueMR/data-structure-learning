#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10000

//��װ�õ��ı���������
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

//�������
void Output(Text t,int size)
{
    //ͳ��ÿ�е��ַ���
    int countchar = 0;
    //ͳ������
    int countrow = 1;
    //ͳ��ҳ��
    int countpage = t.StartingPageNumber;

    int i,j;

    //ÿҳҳ����������
    for(j = 0;j < t.HeadingLength;j++)
    {
        printf("\n");
    }

    //��հ�
    for(j = 0;j < t.LeftMargin;j++)
    {
        printf(" ");
    }

    for(i = 0;i < size;i++)
    {
        //���������һ�����������ͬһ�У��ۻ��ַ������ȣ����ո�
        countchar += strlen(t.text[i]) + 1;
        //����ۻ����ȳ���Ҫ������ҳ��ʱ�����ǻ��л��ǻ�ҳ

        //@��Ϊ�����ַ���ָʾ���������������һ�Σ�����һ�У����ڶ�������8���ַ�λ��
        //@�Գ�һ����
        if(*t.text[i - 1] == '@')
        {
            printf("\n");
            countrow++;
            if(countrow > t.PageLength)
            {
                //���Ҫ��ÿҳҳ������������С��3����ҳ�Ŵ�ӡ��Ҷ�׿����еڶ��е��м�λ��
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
                //����ӡ
                else
                {
                    for(j = 0;j < t.FootingLength;j++)
                    {
                        printf("\n");
                    }
                    countpage++;
                }

                //ÿҳҳ����������
                for(j = 0;j < t.HeadingLength;j++)
                {
                    printf("\n");
                }

                countrow = 1;
            }
            printf("\n");
            //��հ�
            for(j = 0;j < t.LeftMargin;j++)
            {
                printf(" ");
            }
            //��������8���ַ�λ��
            for(j = 0;j < 8;j++)
            {
                printf(" ");
            }
            //�����ַ���
            countchar = strlen(t.text[i]) + 8;
            countrow++;
            if(countrow > t.PageLength)
            {
                //���Ҫ��ÿҳҳ������������С��3����ҳ�Ŵ�ӡ��Ҷ�׿����еڶ��е��м�λ��
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
                //����ӡ
                else
                {
                    for(j = 0;j < t.FootingLength;j++)
                    {
                        printf("\n");
                    }
                    countpage++;
                }

                //ÿҳҳ����������
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
            //�����������ÿҳ�涨���������˵����Ҫ��ҳ
            if(countrow > t.PageLength)
            {
                //���Ҫ��ÿҳҳ������������С��3����ҳ�Ŵ�ӡ��Ҷ�׿����еڶ��е��м�λ��
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
                //����ӡ
                else
                {
                    for(j = 0;j < t.FootingLength;j++)
                    {
                        printf("\n");
                    }
                    countpage++;
                }

                //ÿҳҳ����������
                for(j = 0;j < t.HeadingLength;j++)
                {
                    printf("\n");
                }

                countrow = 1;
            }

            countchar = strlen(t.text[i]);
            printf("\n");

            //��հ�
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


