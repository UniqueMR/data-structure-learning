#include <stdio.h>
#include <stdlib.h>

//����Ԫ������
typedef struct
{
    //Ԫ�عؼ���
    int data;
    //suml��sumg�ֱ�ͳ�Ʊȸ�Ԫ�ش��Ԫ�ص���Ŀ���ͱȸ�Ԫ��С��Ԫ�ص���Ŀ
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

//��ֵ��¼����
Elem MidValue(List L)
{
    int i,j;

    //��ʼ������Ϊ0
    for(i = 0;i < L.length;i++)
    {
        L.elem[i].sumg = 0;
        L.elem[i].suml = 0;
    }

    //��������
    for(i = 0;i < L.length - 1;i++)
    {
        for(j = i + 1;j < L.length;j++)
        {
            if(L.elem[i].data < L.elem[j].data)
            {
                //�ҵ�һ����i��ģ��ҵ�һ����jС��
                L.elem[i].sumg++;
                L.elem[j].suml++;
            }
            else
            {
                //�ҵ�һ����iС�ģ��ҵ�һ����j���
                L.elem[i].suml++;
                L.elem[j].sumg++;
            }
        }
        //���ڶ�ÿһ��Ԫ�أ�����ǰ���Ԫ�رȽϹ���Ҳ�ͺ����Ԫ�رȽϹ�����˿����������ز�©
    }

    int k;

    for(i = 0;i < L.length;i++)
    {
        //kΪ��i��ĺͱ�iСԪ����Ŀ�Ĳ�ֵ
        k = (L.elem[i].sumg > L.elem[i].suml)?(L.elem[i].sumg - L.elem[i].suml):(L.elem[i].suml - L.elem[i].sumg);

        //�����ֵΪ0��Ԫ�ع��������������߲�ֵΪ1��Ԫ�ع���ż���������ͷ�����Ӧ�Ľ��
        if(k == 0||k == 1)
            return L.elem[i];
    }
    return;
}
