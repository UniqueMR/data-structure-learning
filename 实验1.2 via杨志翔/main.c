




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
    srand(time(NULL));//随机数产生种子
//    printf("请输入第一个m\n");
//    scanf("%d",&m);
    m = 41;
    for(i=0;i<n;i++)
   {
        a[i].mima=rand()%n+1;
        a[i].xuhao=i+1;
   }//n个人及其密码产生
   printf("这些人的密码依次是：\n");
   for(i=0;i<n;i++)
    printf("%d\n",a[i].mima);
    while(p!=1)
    {
        if(p==n)i=-1;
        else i=i-1;//区分第一次循环和接着循环
        for(j=0;;j++)
        {
            i++;if(i==p)i=0;
            if(j==m-1)break;
        }//找到将删除的人
        m=a[i].mima;
        b[k]=a[i].xuhao;//传递将删除之人的密码及序号
        k++;
        {
            o=i;
            for(o;o<p-1;o++)
                a[o]=a[o+1];
            p--;
        }//删除一人
        if(i==p)i=0;//删除最后一个人时

    }
    b[k]=a[0].xuhao;
    printf("\n");
    printf("弹出顺序为\n");
    for(i=0;i<n;i++)
        printf("%d\n",b[i]);

}
