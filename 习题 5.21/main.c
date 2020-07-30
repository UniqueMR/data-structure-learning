#include <stdio.h>
#include <stdlib.h>

//�涨�������Ԫ��������
#define MAXSIZE 100

typedef int ElemType;

//�����ݵ�ֵ��λ�ý��з�װ
//���Ϊ����������Ϣ
typedef struct
{
    int i;
    int j;
    ElemType e;
}Triple;

//��Ԫ�飬������飬��������������������Ԫ���ܸ�����ÿ�з���Ԫ�ظ�����ÿ�е�һ������Ԫ������Ԫ���е�λ��
//���Ϊѹ��������Ϣ
typedef struct
{
    Triple data[MAXSIZE];

    //����������
    int mu;
    //����������
    int nu;
    //�����з���Ԫ�صĸ���
    int tu;
}TsMatrix;


//����������
TsMatrix SumTsMatrix(TsMatrix t1,TsMatrix t2)
{
    TsMatrix t;
    //m��n���������������������t1,t2
    int m = 0,n = 0;
    //k������������ľ���
    int k = 0;

    if(t1.mu != t2.mu||t1.nu != t2.nu)
    {
        printf("����Ƚײ�����ӣ�");
        exit(1);
    }

    else
    {
        while(m < t1.mu&&n < t2.mu)
        {
            //�������ȣ��������С��ѹ��
            if(t1.data[m].i < t2.data[n].i)
            {
                t.data[k] = t1.data[m];
                //ѹ��Ԫ�غ�ѹ����Ԫ��ʹ洢��Ԫ�����������ǰ��һλ
                k++;
                m++;
            }
            //�������
            else if(t1.data[m].i == t2.data[n].i)
            {
                //������ȣ�����������������С��ѹ��
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
                //������ȣ�����Ҳ��ȣ��Ͱ�Ԫ��ֵ��ӣ�����λ�ã�������Ԫ������ǰ��
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
            //�������ȣ��������С��ѹ��
            else
            {
                t.data[k] = t2.data[n];
                k++;
                n++;
            }
        }

        //�������Ԫ��������������������ܷ���Ԫ����
        t.tu = k + 1;
        t.mu = t1.mu;
        t.nu = t1.nu;

        //���ش洢��ӽ������Ԫ��
        return t;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
