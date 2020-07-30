#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int expectation;
    int result;
}person,*people;

//将所有比exp[low]小的元素分到exp[low]的左边，比exp[low]大的元素都分到exp[low]的右边，并返回中间元素的位置
int Partition(int *exp,int low,int high)
{
    int pivotkey;

    exp[0] = exp[low];
    pivotkey = exp[low];

    while(low < high)
    {
        while(low < high&&exp[high] >= pivotkey)
            high--;
        exp[low] = exp[high];

        while(low < high&&exp[low] <= pivotkey)
            low++;
        exp[high] = exp[low];
    }

    exp[low] = exp[0];

    return low;
}

//快速排序
void Qsort(int *exp,int low,int high)
{
    int pivotloc;

    if(low < high)
    {
        pivotloc = Partition(exp,low,high);
        Qsort(exp,low,pivotloc - 1);
        Qsort(exp,pivotloc + 1,high);
    }

    else
        return;
}

//找到拉拢人员的现金阈值
int FindThreshold(people p,int n)
{
    int i;
    int *exp;

    exp = (int*)malloc((n + 1)*sizeof(int));

    for(i = 0;i < n;i++)
    {
        exp[i + 1] = p[i].expectation;
    }

    Qsort(exp,1,n);

    if(n % 2 == 0)
    {
        return exp[n/2];
    }
    else
        return exp[n/2 + 1];
}

void AllocateMoney(people p,int n)
{
    int threshold;
    int i;
    int low,high;
    int sum = 0;
    int count = 0;

    low = 1;
    high = n - 1;

    if(n < 3)
    {
        printf("Error in input!\n");
        exit(1);
    }

    else if(n == 3)
    {
        for(i = 0;i < n;i++)
        {
            p[i].expectation = 0;
        }

        p[0].result = 100;
        p[1].result = p[2].result = 0;
        return;
    }

    else
    {
        AllocateMoney(p + 1,n - 1);
        threshold = FindThreshold(p + 1,n - 1);
        for(i = low + 1;i <= high&&count <= n/2 - 1;i++)
        {
            if(p[i].expectation <= threshold)
            {
                p[i].expectation++;
                p[i].result = p[i].expectation;
                sum += p[i].result;
                count++;
            }
            else
            {
                p[i].result = 0;
            }
        }
    }
    p[1].result = 0;
    p[0].result = 100 - sum;
}

int main()
{
    int n;
    int i;

    while(1)
    {
        printf("How many pirates:\n");
        scanf("%d",&n);

        people p;

        p = (people)malloc(n*sizeof(person));

        AllocateMoney(p,n);

        for(i = 0;i < n;i++)
            printf("%d\t",p[i].result);

        printf("\n");
    }

    return 0;
}
