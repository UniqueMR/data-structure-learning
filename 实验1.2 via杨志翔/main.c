




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define n 1000
struct person
{
    int xuhao;
    int mima;
};
void main()
{
    struct person a[n];
    int i,j,m,b[n],k=0,o,p=n;
    srand(time(NULL));//�������������
//    printf("�������һ��m\n");
//    scanf("%d",&m);
    m = 41;
    for(i=0;i<n;i++)
   {
        a[i].mima=rand()%n+1;
        a[i].xuhao=i+1;
   }//n���˼����������
   printf("��Щ�˵����������ǣ�\n");
   for(i=0;i<n;i++)
    printf("%d\n",a[i].mima);
    while(p!=1)
    {
        if(p==n)i=-1;
        else i=i-1;//���ֵ�һ��ѭ���ͽ���ѭ��
        for(j=0;;j++)
        {
            i++;if(i==p)i=0;
            if(j==m-1)break;
        }//�ҵ���ɾ������
        m=a[i].mima;
        b[k]=a[i].xuhao;//���ݽ�ɾ��֮�˵����뼰���
        k++;
        {
            o=i;
            for(o;o<p-1;o++)
                a[o]=a[o+1];
            p--;
        }//ɾ��һ��
        if(i==p)i=0;//ɾ�����һ����ʱ

    }
    b[k]=a[0].xuhao;
    printf("\n");
    printf("����˳��Ϊ\n");
    for(i=0;i<n;i++)
        printf("%d\n",b[i]);

}
